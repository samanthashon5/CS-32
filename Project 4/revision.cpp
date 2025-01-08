#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <functional>
#include <sstream>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

//add
//copy
const int N = 20;
const int bucketNum = 1009;

//own find function for hash table
bool find(vector<list<pair<int,string>>> hashTable, const string& seq, int& start, const int& bucketNum)
{
  size_t hashVal = hash<string>()(seq) % bucketNum;
  for(auto it = hashTable[hashVal].begin(); it != hashTable[hashVal].end(); ++it)
    {
      if(it -> second == seq)
      {
        start = it -> first;
        return true;
      }
    }
  return false;
}


void createRevision(istream& fold, istream& fnew, ostream& frevision)
{
  //copy old and new into strings
  string oldstr = "";
  char ch;
  while(fold.get(ch))
    {
      oldstr += ch;
    }
  
  string newstr = "";
  while(fnew.get(ch))
    {
      newstr += ch;
    }

  //create hash table
  vector<list<pair<int,string>>> hashTable(bucketNum);

  //insert string sequences into hash table
  for(int i = 0; i < oldstr.size() - N; i++)
    {
      string seq = oldstr.substr(i, N);
      size_t hashVal = hash<string>()(seq) % bucketNum;

      //insert pair into hash table
      // cout << "Fail 1 ";
      pair<int, string> add(i, seq);
      if(hashVal >= 0)
      {
        hashTable[hashVal].push_back(add);
        // cout << "Fail 2 ";
      }
    }
  cout << "FINISHED HZ " << newstr.size() << endl;
  // cout << "ASDASDASD" << endl;
  //create a string so that it doesn't add each individual character separately
  //add
  string add = "";
  int j = 0;
  while(j < newstr.size())
    {
      cout << "Inside Loop j = " << j << endl;
      //find where it fails
      if(j + N < newstr.size())
      {
        string curr = newstr.substr(j, N);
        int copylen = 0;
        int start = 0;

        cout << curr << endl;

        //find sequence in hash table
        if(find(hashTable, curr, start, bucketNum))
        {
          cout << "found" << endl;
          //add instructions
          if(!add.empty())
          {
            cout << "add not empty" << endl;
            frevision << "+/" << add <<'/';
            add.clear();
          }
          //find length of sequences that are the same in both strings
          copylen = N;
          while(j + copylen < newstr.size() && start + copylen < oldstr.size() && newstr[j + copylen] == oldstr[start + copylen])
            {
              copylen++;
            }
          //copy instructions
          frevision << '#' << start << ',' << copylen;
          j += copylen;
        }
          
        else
        {
          add += newstr[j];
          j++;
          continue;
        }
      }
        
      else
      {
        add += newstr[j];
        j++;
        continue;
      }
    }
  if(!add.empty())
  {
    frevision << "+/" << add << '/';
  }
  cout << "done revision";
}


//revision
bool revise(istream& fold, istream& frevision, ostream& fnew)
{
    string oldtxt = "";
    char ch;
    while(fold.get(ch))
        {
            oldtxt += ch;
        }

    string revision = "";
    while(frevision.get(ch))
        {
            revision += ch;
        }

    string newtxt = "";


    int i = 0;
    while(i != revision.size())
        {
            //make sure that every revision starts with add or copy

            //add
            char delimiter;
            if(revision[i] == '+')
            {
                if(i + 1 < revision.size())
                {
                    delimiter = revision[i + 1];
                }
                if(i + 2 < revision.size())
                {
                    i = i + 2;
                    while(revision[i] != delimiter)
                        {
                             newtxt += revision[i];
                            i++;
                        }
                }
                if(revision[i] == delimiter)
                {
                    i++;
                }
            }

            //copy
            else if(revision[i] == '#')
            {
                string start = "";
                string end = "";
                if(i + 1 < revision.size())
                {
                    i++;
                }
                while(revision[i] != ',' && i < revision.size())
                {
                    if(!isdigit(revision[i]))
                    {
                        return false;
                    }
                    else
                    {
                        start += revision[i];
                        i++;
                    }
                }
                if(revision[i] == ',')
                {
                    if(i + 1 < revision.size())
                    {
                        i++;
                    }
                    while(isdigit(revision[i]) && i < revision.size())
                    {
                        end += revision[i];
                        i++;
                    }
                }

                //convert end and start to integers
                int startval = 0;
                int endval = 0;
                for (int j = 0; j < start.size(); j++)
                {
                    startval = startval * 10 + (start[j] - '0');
                }
                for(int j = 0; j < end.size(); j++)
                {
                    endval= endval * 10 + (end[j] - '0');
                }
                for(int j = startval; j < startval + endval; j++)
                {
                    if(j < oldtxt.size())
                    {
                        newtxt += oldtxt[j];
                    }
                }
            }

            //do nothing
            else if(revision[i] == '\n' || revision[i] == '\r')
            {
                i++;
            }

            else{cout << "Failed at" << revision[i];}
        }

    fnew << newtxt;
    return true;
}

bool runtest(string oldName, string newName, string revisionName, string newName2)
{
    if (revisionName == oldName  ||  revisionName == newName  ||
        newName2 == oldName  ||  newName2 == revisionName  ||
            newName2 == newName)
    {
        cerr << "Files used for output must have names distinct from other files" << endl;
        return false;
    }
    ifstream oldFile(oldName, ios::binary);
    if (!oldFile)
    {
        cerr << "Cannot open " << oldName << endl;
        return false;
    }
    ifstream newFile(newName, ios::binary);
    if (!newFile)
    {
        cerr << "Cannot open " << newName << endl;
        return false;
    }
    ofstream revisionFile(revisionName, ios::binary);
    if (!revisionFile)
    {
        cerr << "Cannot create " << revisionName << endl;
        return false;
    }
    createRevision(oldFile, newFile, revisionFile);
    revisionFile.close();

    oldFile.clear();   // clear the end of file condition
    oldFile.seekg(0);  // reset back to beginning of the file
    ifstream revisionFile2(revisionName, ios::binary);
    if (!revisionFile2)
    {
        cerr << "Cannot read the " << revisionName << " that was just created!" << endl;
        return false;
    }
    ofstream newFile2(newName2, ios::binary);
    if (!newFile2)
    {
        cerr << "Cannot create " << newName2 << endl;
        return false;
    }
    assert(revise(oldFile, revisionFile2, newFile2));
    newFile2.close();

    newFile.clear();
    newFile.seekg(0);
    ifstream newFile3(newName2, ios::binary);
    if (!newFile)
    {
        cerr << "Cannot open " << newName2 << endl;
        return false;
    }
    if ( ! equal(istreambuf_iterator<char>(newFile), istreambuf_iterator<char>(), 
                 istreambuf_iterator<char>(newFile3), istreambuf_iterator<char>()))
    {
        cerr << newName2 << " is not identical to " << newName
                 << "; test FAILED" << endl;
        return false;
    }
    return true;
}

int main()
{
    assert(runtest("myoldfile.txt", "mynewfile.txt", "myrevisionfile.txt", "mynewfile2.txt"));
    cerr << "Test PASSED" << endl;
}
