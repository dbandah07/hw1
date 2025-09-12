/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>


using namespace std;

int main(int argc, char* argv[])
{
  Node* iter = new Node (0, NULL);
  Node* head = iter;

  for (int i = 1; i <= 12; i++) { // loops thru 12 
    iter->next = new Node (i, nullptr); // adds pointer to iter 
    iter = iter->next; 
    // should print 12...0;
  }

  cout << "TESTING: all contents in loop" << endl;
  // testing printing:
  Node* print = head; // protect head;
  while (print != nullptr) { // until it reaches end of list
    cout << print->value << endl;
    print = print->next;
  }

  // testing split ();
  
  cout << endl; 
  cout << "TESTING: split function" << endl;
  Node* t_evens = NULL; 
  Node* t_odds = NULL;
  // cout << "DEBUG: iter->value " << iter->value << endl;
  // cout << "DEBUG: head->value" << head->value << endl;
  split(head, t_odds, t_evens);

  // cout << endl;
  // cout << "TESTING: t_evens in split()" << endl;

  Node* temp_e = t_evens;
  Node* traverse;
  // cout << ""DEBUG: temp_e->value" temp_e->value << endl; 
  while (temp_e != nullptr) {
    // cout << "DEBUG: makes it to while loop for temp_e" << endl;
    // cout << temp_e->value << endl; // print val in t_evens
    traverse = temp_e;
    temp_e = temp_e->next;
    delete traverse;
  }
  // cout << endl; 
  // cout << "TESTING: t_odds in split()" << endl;

  Node* temp_o = t_odds;
  while (temp_o != nullptr) {
    cout << temp_o->value << endl;
    traverse = temp_o;  
    temp_o = temp_o->next;
    delete traverse;
  }
}