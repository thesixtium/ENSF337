// OLList.cpp
// ENSF 337 Fall 2021 Lab 8 Exercise A and B

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
: headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;
    
    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;
        Node *after = headM->next;
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
}

void OLList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA < headM->item)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }

        before->next=maybe_doomed->next;
        delete maybe_doomed;
    }



}

void OLList::destroy()
{
    while(headM){
        Node *old = headM;
        headM = headM->next;
        delete old;
    }
    headM = 0;
}

void OLList::copy(const OLList& source)
{
    Node * currentNode = 0;
    Node * nextNode = 0;

    if( source.headM == 0 )
        headM = 0;

    else
    {
        headM = new Node;
        headM->item = source.headM->item;

        currentNode = headM;
        nextNode = source.headM->next;
    }

    while( nextNode )
    {
        currentNode->next = new Node;
        currentNode = currentNode->next;
        currentNode->item = nextNode->item;

        nextNode = nextNode->next;
    }
    currentNode->next = 0;

}


