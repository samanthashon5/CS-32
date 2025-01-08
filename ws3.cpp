#include <iostream>
using namespace std;

struct Node {
int val;
Node* next;
};
class LinkedList {
public:
void rotateLeft(int n); // rotates head left by n
// Other working functions such as insert and printItems
private:
Node* head;
};

void LinkedList::rotateLeft(int n)
{
    Node* p = new Node;
    while(p -> next != NULL)
    {
        p = p -> next;
    }
    for(int i = 0; i <= n; i++)
    {
        Node* newGuy = new Node;
        head -> val = newGuy -> val;
        head -> next = head -> next -> next;
    }
}