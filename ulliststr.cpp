#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


void ULListStr::push_back(const std::string& val)
{
  if (tail_ == NULL){ // empty list
    Item* newItem = new Item;
    newItem->val[0] = val; //sets value at start of array
    // set first and last and since it's the only node, prev and next as NULL
    newItem->first = 0; 
    newItem->last = 1;
    newItem->prev = NULL;
    newItem->next = NULL;
    // newItem is both the head and tail, and size is incremented
    head_ = newItem;
    tail_ = newItem;
    size_++;
    return;
  }
  if (tail_->last==ARRSIZE){ // if you need to add a new node
    Item* newItem = new Item;
    newItem->val[0] = val; // adds to front of new node's array
    newItem->prev = tail_; // sets the previous to the old tail
    newItem->next = NULL; // sets the next of the new tail to NULL
    newItem->first = 0;
    newItem->last = 1;
    // adds newItem to the tail and shifts the tail to the new one and increments size
    tail_->next = newItem; 
    tail_ = newItem;
    size_++;
    return;
  }
  else{
    // adds to the end and increments last and size
    tail_->val[tail_->last] = val; 
    tail_->last++;
    size_++;
    return;
  }
}

void ULListStr::pop_back()
{
  if (tail_==NULL){ // empty list case
    return;
  }
  if (tail_->last==1){ // position of last element is the first position of an item
      Item* temp = tail_;
      tail_ = tail_->prev;
      if (tail_ != NULL){ // if list isn't empty, new tail's next is set to NULL
        tail_->next = NULL;
      }
      delete temp;
      size_--;
      if (size_==0){ // if empty list
        head_=NULL;
        tail_=NULL;
      }
      return;
  }
  else{
    tail_->last--;
    size_--;
    if (size_==0){ // if empty in the middle
      delete head_;
      head_=NULL;
      tail_=NULL;
    }
    return;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if (head_ == NULL){ // empty case
    Item* newItem = new Item;
    // adds value to the front of the array and sets first, last, prev, next
    newItem->val[0] = val; 
    newItem->first = 0;
    newItem->last = 1;
    newItem->prev = NULL;
    newItem->next = NULL;
    // the new item is now both the head and tail, and size is incremented
    head_ = newItem;
    tail_ = newItem;
    size_++;
    return;
  }
  if (head_->first==0){ // if we need to add a new node to the front
    Item* newItem = new Item;
     // add the string to the last position of the new front node
    newItem->val[ARRSIZE-1] = val;
    newItem->next = head_;
    newItem->prev = NULL;
    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
    // shifts the old head to the new head, adding the prev link to the old head
    head_->prev = newItem;
    head_ = newItem;
    size_++;
    return;
  }
  else{ // adds to the front and moves first to the left
    head_->val[head_->first-1] = val;
    head_->first--;
    size_++;
  }
}

void ULListStr::pop_front()
{
  if (head_==NULL){ // empty list case
    return;
  }
  if (head_->first==ARRSIZE-1){ // if current first value is in the last position of a node
    Item* temp = head_;
    head_ = head_->next;
    if (head_ != NULL){// new head's prev value is now NULL
        head_->prev = NULL;
      }
    delete temp;
    size_--;
    if (size_==0){//if list is fully empty
      head_=NULL;
      tail_=NULL;
    }
  }
  else{
    head_->first++;//move the value of first to the right
    size_--;
    if (size_==0){ // in case empty in the middle
      delete head_;
      head_=NULL;
      tail_=NULL;
    }
  }

}

std::string const & ULListStr::back() const
{
  // according to the video, we don't have to account for the empty list case
  return tail_->val[tail_->last-1]; // value of the last item
}
std::string const & ULListStr::front() const
{
  // according to the video, we don't have to account for the empty list case
  return head_->val[head_->first]; // value of the first item
}
/** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc>=size_){ // invalid index
    return NULL;
  }
  if (head_==NULL){ // empty list
    return NULL;
  }
  int headfirst = head_->first; //shorthand mainly for the for loop condition
  int modLoc = (loc%ARRSIZE+headfirst)%ARRSIZE; 
  //loc modulo ARRSIZE shifted by the position of first in head that will have the index from 0 to ARRSIZE
  Item* temp = head_;
  // walks the number of nodes necessary to get to the node that corresponds to loc
  // ARRSIZE-headfirst is the amount of positions from the back where the first node starts
  // increment by ARRSIZE to skip nodes to get closer to the proper node
  // static casting because the condition may be negative but loc and arrsize are unsigned ints
  for (int i = 0; i<static_cast<int>(loc)-(static_cast<int>(ARRSIZE)-headfirst)+1;i+=ARRSIZE){
    temp = temp->next; // walks the number of nodes necessary
  }
  return &temp->val[modLoc];//once we're at the right node, we already know the position
}