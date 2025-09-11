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
void walk2(Node*& n, Node*& add);
void print_list(Node*& head);
void delete_list(Node*& head);
int main(int argc, char* argv[])
{
  Node* start = new Node(1,NULL);
  Node* temp = start;
  Node* newNode = new Node(2, nullptr);
  temp->next = newNode;
  temp = newNode;
  newNode = new Node(3, nullptr);
  temp->next = newNode;
  temp = newNode;
  newNode = new Node(4, nullptr);
  temp->next = newNode;
  temp = newNode;
  newNode = new Node(5, nullptr);
  temp->next = newNode;
  temp = newNode;
  newNode = new Node(6, nullptr);
  temp->next = newNode;
  temp = newNode;
  std::cout<<start->value<<std::endl;
  std::cout<<start->next->next->value<<std::endl;
  Node* odds = NULL;
  Node* evens = NULL;
  split(start, odds, evens);
  std::cout<<odds->value<<std::endl;
  std::cout<<odds->next->value<<std::endl;
  std::cout<<odds->next->next->value<<std::endl;
  std::cout<<evens->value<<std::endl;
  std::cout<<evens->next->value<<std::endl;
  std::cout<<evens->next->next->value<<std::endl;

  delete_list(start);
  delete_list(odds);
  delete_list(evens);
  delete odds;
  delete evens;
}
void delete_list(Node*& head){
  if (head==NULL){
    return;
  }
  if (head->next == NULL){
    return;
  }
  delete_list(head->next);
  delete head->next;
}