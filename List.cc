#include <iostream>
using namespace std;

#include "List.h"

List::List() : head(0), tail(0) { }

List::~List()
{
  cleanup();
}

// Adds a student to the front of the list
void List::addFront(Student* newStu)
{
  Node* tmpNode = new Node;
  tmpNode->data = newStu;
  tmpNode->prev = 0;
  tmpNode->next = 0;

  if (head == 0) {
    head = tmpNode;
    tail = tmpNode;
    return;
  }

  tmpNode->next = head;
  head->prev = tmpNode;
  head = tmpNode;
}

// Adds a student in alphabetical order

void List::addAlpha(Student* newStu)
{
  Node* tmpNode = new Node;
  tmpNode->data = newStu;
  tmpNode->next = 0;
  tmpNode->prev = 0;

  if (head == 0) {
    head = tmpNode;
    tail = tmpNode;
    return;
  }

  Node *currNode, *prevNode;

  prevNode = 0;
  currNode = head;

  while (currNode != 0) {
    if (currNode->data->getName() > tmpNode->data->getName())
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == head) {	// add to first position
    currNode->prev  = tmpNode;
    tmpNode->next   = currNode;
    head = tmpNode;
  }
  else if (currNode == 0) {	// add to last position
    prevNode->next  = tmpNode;
    tmpNode->prev   = prevNode;
    tail = tmpNode;
  }
  else {			// add in the middle
    tmpNode->next  = currNode;
    tmpNode->prev  = prevNode;
    prevNode->next = tmpNode;
    currNode->prev = tmpNode;
  }
}

void List::print() const
{
  Node* currNode = head;

  if (currNode == 0) return;

  do {
    currNode->data->print();
    currNode = currNode->next;
  } while (currNode != 0);
}

void List::printBack() const
{
  Node* currNode = tail;

  if (currNode == 0) return;

  do {
    currNode->data->print();
    currNode = currNode->prev;
  } while (currNode != 0);
}

void List::cleanupData()
{
  Node *currNode = head;

  while (currNode != 0) {
    delete currNode->data;
    currNode = currNode->next;
  }
}

void List::cleanup()
{
  Node *currNode, *nextNode;
  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode;
    currNode = nextNode;
  }

  head = tail = 0;
}

bool List::operator==(List &l)
{
  Node *curr1 = head;
  Node *curr2 = l.head;

  while(curr1 != NULL){
    if(curr1->data != curr2->data){ return false;}
    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  return true;
}

bool List::operator!=(List &l)
{
  Node *curr1 = head;
  Node *curr2 = l.head;

  while(curr1 != NULL){
    if(curr1->data != curr2->data){ return true;}
    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  return false;
}

Student* List::operator[](const int index)
{
  Node *curr = head;
  int count = 0;

  while(curr != NULL){
    if(count == index){ return curr->data;}
    curr = curr->next;
    count++;
  }

  return NULL;
}


//not working
ostream& operator<<(ostream& output, List& l)
{
  int index = 0;

  while(l[index] != NULL){
    output << *(l[index]) << endl;
    index ++;
  }

  return output;
}

List& List::operator+=(Student* stu) {
  addFront(stu);
  return *this;
}

List& List::operator+(Student* stu) {
  List *l = new List();
  Node *curr = head;

  while(curr != NULL){
    l->addAlpha(curr->data);
    curr = curr->next;
  }
  l->addAlpha(stu);

  return *l;
}
