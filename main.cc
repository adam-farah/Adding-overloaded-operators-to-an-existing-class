#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <cstdlib>

#include "Student.h"
#include "List.h"


int main()
{
  List list1, list2, list11, list22;
  Student* stuPtr;
  string   name, number;

  ifstream infile("stu.txt", ios::in);
  if (!infile) {
    cout<<"could not open file"<<endl;
    exit(1);
  }

  while (infile >> number >> name) {
    stuPtr = new Student(number, name);
    list1.addFront(stuPtr);
    list2.addAlpha(stuPtr);

    list11.addFront(stuPtr);
    list22.addAlpha(stuPtr);
  }

  cout << "ADD FRONT FORWARD" << endl;
  list1.print();
  cout << "ADD FRONT BACKWARD" << endl;
  list1.printBack();
  cout << "ADD ALPHA FORWARD" << endl;
  list2.print();;
  cout << "ADD ALPHA BACKWARD" << endl;
  list2.printBack();;


  // == and != checking
  cout << endl << endl << endl;
  if(list11 == list1){
    cout << "list11 and list1 are equal" << endl;
  }
  if(list22 == list2){
    cout << "list22 and list2 are equal" << endl;
  }
  if(list1 == list2){
    cout << "list1 and list2 are equal" << endl;
  }else{
    cout << "list1 and list2 are NOT equal" << endl;
  }

  cout<<"========================="<<endl;

  //get index 2 of list 1 and <<
  Student *t = list1[2];
  cout << "index 2 of list 1" << endl;
  cout << *t << endl;

  cout << "print list 1: " << endl;
  cout << list1 << endl;

  cout << endl << endl << endl;
  cout << "Adding new student += to list1" << endl;
  Student *stu = new Student("101039776","Mike Nguyen");
  list1 += stu;
  list1.print();

  cout << endl << endl << endl;
  cout << "Adding new student to list 2" << endl;
  List list3 = list2 + stu;
  list3.print();



  list1.cleanupData();

}
