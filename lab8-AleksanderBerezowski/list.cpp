using namespace std;
#include "list.h"

FlowList::FlowList()
        : headM(0)
{
}

FlowList::FlowList(const FlowList& source)
{
    copy(source);
}

FlowList& FlowList::operator =(const FlowList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

FlowList::~FlowList()
{
    destroy();
}

void FlowList::print() const
{
    cout << "Year\tFlow"<<endl;
    if (headM != nullptr) {
        cout << headM->item.year << '\t' << headM->item.flow;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << "\n" << p->item.year << '\t' << p->item.flow;
    }
}

void FlowList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;

    if (headM == nullptr || (itemA.flow <= headM->item.flow && itemA.year <= headM->item.year) ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;
        Node *after = headM->next;
        while(after != nullptr && itemA.flow > after->item.flow && itemA.year > after->item.year) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
    }
}

void FlowList::remove(const string& year)
{
    // if list is empty, do nothing
    if (headM == nullptr || (stoi(year) < headM->item.year))
        return;

    Node *doomed_node = nullptr;

    if (stoi(year) == headM->item.year) {
        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != nullptr && stoi(year) > maybe_doomed->item.year) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }

        before->next=maybe_doomed->next;
        delete maybe_doomed;
    }



}

void FlowList::destroy()
{
    while(headM){
        Node *old = headM;
        headM = headM->next;
        delete old;
    }
    headM = nullptr;
}

void FlowList::copy(const FlowList& source)
{
    Node * currentNode = nullptr;
    Node * nextNode = nullptr;
    if( source.headM == nullptr )
        headM = nullptr;
    else {
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
    currentNode->next = nullptr;

}

double FlowList::average(){
    int entires = 0;
    double sum = 0;
    double average = 0;

    while (headM != NULL) {
        sum += headM->item.flow;
        entires += 1;
        headM = headM->next;
    }
    average = sum / entires;
    return average;
};

void FlowList::save(const string& filePath){
    Node *current = headM;
    ofstream outObj;
    outObj.open(filePath);
    while (current){
        outObj << current->item.year << '\t' << current->item.year << endl;
        current = current->next;
    }
    outObj.close();
}


