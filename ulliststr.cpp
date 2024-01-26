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

void ULListStr::push_back(const std::string& val){
  //check if there is a ullist
  if(tail_ == nullptr){
    //create new node and initialize values
    tail_ = new Item();
    tail_->last = 1;
    tail_->val[0] = val;
    head_ = tail_;
  }

  //check if we need another Item
  else if(tail_->last == ARRSIZE){
    //create a new item and intialize values
    Item* temp = new Item();
    temp->last = 1;
    temp->val[0] = val;
    temp->prev = tail_;

    //update tail and move it
    tail_->next = temp;
    tail_ = temp;
  }

  else{
    //update val and increment last
    tail_->val[tail_->last++] = val;
  }

  size_++;
}

void ULListStr::push_front(const std::string& val){
  //check if there is a ullist
if(head_ == nullptr){
  head_ = new Item();
  tail_ = head_;
  head_->last = ARRSIZE;
  head_->first = ARRSIZE - 1;
  head_->val[head_->first] = val;
}
//check if we need a new Item
else if(head_->first == 0){
  //create a new item and initalize values
  Item* temp = new Item();
  temp->first = ARRSIZE - 1;
  temp->last = ARRSIZE;
  temp->val[temp->first] = val;
  temp->next = head_;

  //update and move head pointer
  head_->prev = temp;
  head_ = temp;
}

else{
  head_->val[--head_->first] = val;
}

size_++;
}

void ULListStr::pop_back(){
  //check if there is a linked list
  if(tail_== nullptr){
    return;
  }

  //check if there is only one element
  if(tail_->last == 1){
    //check if there is only one node

    //remove != condition?
    if(head_ == tail_ && head_ != nullptr){
      //delete node and make head and tail pointers null
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
      size_ = 0;
      return;
  }


    //move tail back one
    tail_ = tail_->prev;
    //delete the old tail
    delete tail_->next; 
    //update next to nullptr
    tail_->next = nullptr;
  }
  //if there is more than one element
  else{
    //decrement last
    tail_->last--;
  }

  size_--;
}

void ULListStr::pop_front(){
  //check if there is an unrolled linked list
  if(head_ == nullptr){
    return;
  }

  //check if there is only one element
  if(head_->first == head_->last - 1){
    //check if there is only one node
    //remove != condition?
    if(head_ == tail_ && head_ != nullptr){
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
      size_ = 0;
      return;
    }

    head_ = head_->next;
    delete  head_->prev;
    head_->prev = nullptr;
  }
  else{
    head_->first++;
  }
  size_--;


  // //check if there is only one element
  // if(head_->first == ARRSIZE - 1){
  //   //check if there is only one node
  //   if(head_ == tail_){
  //     //delete node and make head and tail pointers null
  //     delete head_;
  //     head_ = nullptr;
  //     tail_ = nullptr;
  //     return;
  // }
  //   //move head forward one
  //   head_ = head_->next;
  //   //delete old head
  //   delete head_->prev;
  //   //update prev to nullptr
  //   head_->prev = nullptr;
  // }
  // else{
  //   //increment first
  //   head_->first++;
  // }
  // size_--;
}

std::string const& ULListStr::back() const{
  return tail_->val[tail_->last - 1];
}

std::string const& ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  size_t location = 0;
  Item* temp = head_;
  while(temp != nullptr){
    for(size_t i = temp->first; i < temp->last; i++){
      if(location == loc){
        return &(temp->val[i]);
      }
      location++;
    }
    temp = temp->next;
  }
  return nullptr;
}

void ULListStr::print()const{
  Item* temp = head_;
  while(temp != nullptr){
    for(size_t i = temp->first; i < temp->last; i++){
      std::cout << temp->val[i % ARRSIZE] << ' ';
    }
    temp = temp->next;
  }
  std::cout << std::endl;
}
//end of my code

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
