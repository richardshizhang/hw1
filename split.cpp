/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
/* Add a prototype for a helper function here if you need */
void walk(Node*& n, Node*& add);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in == NULL){
    return; // empty list
  }
  Node* next = in->next;
  in->next = NULL; // detach (remove link of) next node from input before attaching to either odds or evens
  if (in->value % 2 == 1){ // if odd
    if (odds==NULL){
      odds = in; // if odds list isn't initialized, set its head to the input
    }
    else{
      Node* moving = odds; //creates a temporary pointer to walk the odds list
      walk(moving, in); // helper function to traverse a list recursively
    }
  }
  else if (in->value % 2 == 0){ // if even
    if (evens==NULL){
      evens = in; // if evens list isn't initialized, set its head to the input
    }
    else{
      Node* moving = evens; //creates a temporary pointer to walk the evens list
      walk(moving, in); // helper function to traverse a list recursively
    }
  }
  split(next, odds, evens); // split the smaller input list
  in = NULL; // sets the input to NULL as specified when the function terminates
}

/* If you needed a helper function, write it here */
// recursively walks a singly linked list from head n
// and adds node "add"
void walk(Node*& n, Node*& add)
{
  if (n==NULL){
    return;
  }
  if(n->next == NULL){// you have reached the end, so you can add this item
    n->next = add;
    return;
  }
  else {
    walk(n->next, add); // traverses to the next node
  }

}