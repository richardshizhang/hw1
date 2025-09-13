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
  if (tail_ == NULL){
    Item* newItem = new Item;
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    newItem->prev = NULL;
    newItem->next = NULL;
    head_ = newItem;
    tail_ = newItem;
    size_++;
    return;
  }
  if (tail_->last==ARRSIZE){
    Item* newItem = new Item;
    newItem->val[0] = val;
    newItem->prev = tail_;
    newItem->next = NULL;
    newItem->first = 0;
    newItem->last = 1;
    tail_->next = newItem;
    tail_ = newItem;
    size_++;
    return;
  }
  else{
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
    return;
  }
}

void ULListStr::pop_back()
{
  if (tail_==NULL){
    return;
  }
  if (tail_->last==1){
      Item* temp = tail_;
      tail_ = tail_->prev;
      if (tail_ != NULL){
        tail_->next = NULL;
      }
      delete temp;
      size_--;
      if (size_==0){
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
  if (head_ == NULL){
    Item* newItem = new Item;
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    newItem->prev = NULL;
    newItem->next = NULL;
    head_ = newItem;
    tail_ = newItem;
    size_++;
    return;
  }
  if (head_->first==0){
    Item* newItem = new Item;
    newItem->val[ARRSIZE-1] = val;
    newItem->next = head_;
    newItem->prev = NULL;
    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
    head_->prev = newItem;
    head_ = newItem;
    size_++;
    return;
  }
  else{
    head_->val[head_->first-1] = val;
    head_->first--;
    size_++;
  }
}

void ULListStr::pop_front()
{
  if (head_==NULL){
    return;
  }
  if (head_->first==ARRSIZE-1){
    Item* temp = head_;
    head_ = head_->next;
    if (head_ != NULL){
        head_->prev = NULL;
      }
    delete temp;
    size_--;
    if (size_==0){
      head_=NULL;
      tail_=NULL;
    }
  }
  else{
    head_->first++;
    size_--;
    if (size_==0){ // if empty in the middle
      delete head_;
      head_=NULL;
      tail_=NULL;
    }
  }

}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}
std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
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
  int modLoc = (loc%10+head_->first)%10; //the edited version that will have the index from 0 to ARRSIZE
  Item* temp = head_;
  int headfirst = head_->first;
  //std::cout<<loc-(ARRSIZE-headfirst)+1<<std::endl;

  for (int i = 0; i<static_cast<int>(loc)-(static_cast<int>(ARRSIZE)-headfirst)+1;i+=ARRSIZE){
    temp = temp->next; // walks the number of nodes necessary
  }
  return &temp->val[modLoc];
}