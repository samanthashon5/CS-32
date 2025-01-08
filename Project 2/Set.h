#ifndef SET_H
#define SET_H
#include <iostream>
using ItemType = std::string;
class Set
{
  public:
    Set();
    //Destructor
    ~Set();
    //Copy Constructor
    Set(const Set& other);
    //Assignment Operator
    Set& operator=(const Set& other);
    bool empty() const;
    int size() const;
    bool insert(const ItemType& value);
    bool erase(const ItemType& value);
    bool contains(const ItemType& value) const;
    bool get(int pos, ItemType& value) const;
    void swap(Set& other);

  private:
  // make doubly linked list
    struct Node
    {
        ItemType amt;
        Node* next;
        Node* previous;
    };
    Node* head;
    Node* tail;
    Node* p;

    int sizenum = 0; 
};


  void unite(const Set& s1, const Set& s2, Set& result);
  void inOnlyOne(const Set& s1, const Set& s2, Set& result);

#endif