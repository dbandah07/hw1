/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit [] non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
// #include <iostream>

// using namespace std;

/* Add a prototype []] a helper function here if you need */

// struct Node {
//  int value;
//  Node *next;
//};

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  // split the elements of a sorted(in inc. order), 
  // singly-linked lists of ints into TWO sorted, 
  // singly linked lists where the first list are all the odd's 
  // and the 2nd are all the even val's.
  // og list IS NOT preserved

  // cout << "DEBUG: made it to split" << endl;
  if (in == NULL) {
    return;
  }

  Node* temp = in; // current 
  in = in->next; // going to nxt Node
  temp->next = NULL; 

  // split to evens
  if (temp->value % 2 == 0) { 
    // cout << "DEBUG: made it to mod 2 if" << endl;
    // cout << temp->value << endl;
    
    if (evens == NULL) { // empty
      // cout << "DEBUG: made it to evens == NULL" << endl;
      evens = temp; // add even value
      // cout << "DEBUG: evens->value " << evens->value << endl; 
    }
    else {
      temp->next = evens; 
      evens = temp; 
    }
  }

  // split to odds
  else {
    if (odds == NULL) {
      // cout << "DEBUG: made it to odds == NULL" << endl;
      odds = temp;
      // cout << "DEBUG: odds->value" << odds->value << endl;
    }
    else {
      temp->next = odds;
      odds = temp; 
    }
  }

  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
