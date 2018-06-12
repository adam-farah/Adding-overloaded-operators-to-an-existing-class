#ifndef LIST_H
#define LIST_H

#include "Student.h"

class List
{
  friend ostream& operator<<(ostream&, List&);

  class Node
  {
    friend class List;
    private:
      Student* data;
      Node*    prev;
      Node*    next;
  };
  public:
    List();
    ~List();
    void addFront(Student*);
    void addAlpha(Student*);
    void cleanupData();
    void print() const;
    void printBack() const;
    bool operator==(List&);
    bool operator!=(List&);
    Student* operator[](const int);
    List& operator+=(Student*) ;
    List& operator+(Student*);


  private:
    Node* head;
    Node* tail;
    void cleanup();
};

#endif
