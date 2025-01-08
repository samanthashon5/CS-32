#include "Set.h"
#include <iostream>
using namespace std;

//Constructor
Set::Set() : head(nullptr), tail(nullptr), sizenum(0)
{}

//When a Set is destroyed, the nodes in the linked list 
//must be deallocated.
Set::~Set()
{
    //if there is nothing in the set, there is nothing to be destroyed
    if(head == nullptr)
    {
        return;
    }

    //deallocates dynamically allocated memory
    Node* p = head;
    while(head != nullptr)
    {
        Node* next = p -> next;
        delete p;
        p = next;
    }
}

//When a brand new Set is created as a copy of an existing 
//Set, enough new nodes must be allocated to hold a duplicate 
//of the original list.
Set::Set(const Set& other) : head(nullptr), tail(nullptr)
{
    sizenum = other.sizenum;
    p = other.head;
    while(p != nullptr)
    {
        Node* newGuy = new Node;
        newGuy -> amt = p->amt;
        newGuy -> next = nullptr;
        newGuy -> previous = tail -> previous;
        tail -> next = newGuy;
        tail = newGuy;
        p = p->next;
    }
    
}

//When an existing Set (the left-hand side) is assigned the value 
//of another Set (the right-hand side), the result must be that the 
//left-hand side object is a duplicate of the right-hand side object, 
//with no memory leak of list nodes 
Set& Set::operator=(const Set& other)
{
    if(this != &other)
    {
        Set temp(other);
        swap(temp);
    }
    return *this;
}

bool Set::empty() const
{
    //if the head and tail are both the nullptr, there is nothing in the set
    if(head == nullptr && tail == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Set::size() const
{
    int sizenum = 0;
    Node* p = head;
    //count the number of nodes
    while(p != nullptr)
    {
        sizenum++;
        p = p -> next;
    }
    return sizenum;
}

bool Set::insert(const ItemType& value)
{
    //if value already exists, don't insert
    if(contains(value))
    {
        return false;
    }

    if(head == nullptr)
    {
        Node* newGuy = new Node;
        newGuy->amt = value;
        newGuy->next = nullptr;
        newGuy->previous = nullptr;
        head = newGuy;
        tail = newGuy;
        sizenum++;
        return true;
    }

    tail->next = nullptr;
    //create new node to hold value
    Node* newGuy = new Node;
    newGuy->amt = value;
    newGuy->next = nullptr;
    newGuy->previous = tail->previous;
    tail->next = newGuy;
    tail = newGuy;
    sizenum++;
    return true;
}

bool Set::erase(const ItemType& value)
{
    p = head;
    while(p != nullptr)
    {
        // find the value you want to erase
        if(p->amt == value)
        {
            Node* toBeDeleted = p->next;
            p->next = p->next->next;
            p->next->previous = p->previous;
            p->previous->next = p->next;
            delete toBeDeleted;
            sizenum--;
            return true;
        }
        else
        {
            p = p->next;
        }
    }
    return false;
}

bool Set::contains(const ItemType& value) const
{
    Node* p = head;
    while(p != nullptr)
    {
        if(p -> amt == value)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

bool Set::get(int pos, ItemType& value) const
{
    Node* p = head;
   if(0 <= pos && pos < size())
   {
    while(p != nullptr)
    {
        for(int i = 0; i < pos; i++)
        {
            p = p->next;
        }
        value = p->amt;
        return true;
    }
   } 
   return false;
}

void Set::swap(Set& other)
{
    Node* newNode = new Node;
    p = head;
    while(p != nullptr)
    {
        newNode->amt = p->amt;
        p->amt = other.p->amt;
        other.p->amt = newNode->amt;
        p = p->next;
    }
}

//new functions
void unite(const Set& s1, const Set& s2, Set& result)
{
    for(int i = 0; i < s1.size(); i++)
    {
        ItemType value;
        if(s1.get(i, value))
        {
            result.insert(value);
        }
    }

    for(int j = 0; j < s2.size(); j++)
    {
        ItemType value2;
        if(s2.get(j,value2))
        {
            if(!s1.contains(value2))
            {
                result.insert(value2);
            }
        }
    }
}

void inOnlyOne(const Set& s1, const Set& s2, Set& result)
{
    for(int i = 0; i < s1.size(); i++)
    {
        ItemType value;
        if(s1.get(i,value))
        {
            if(!s2.contains(value))
            {
                result.insert(value);
            }
        }
    }
    for(int j = 0; j < s2.size(); j++)
    {
        ItemType value2;
        if(s2.get(j,value2))
        {
            if(!s1.contains(value2))
            {
                result.insert(value2);
            }  
        }
    }
}