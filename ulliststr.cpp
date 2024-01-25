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
  //if there is nothing in the list yet
  if(!tail_){
    //create a new Item
    tail_ = new Item();
    //set head pointer to point to the new Item
    head_ = tail_;
    //set last to the "middle"
    head_->last = ARRSIZE / 2;
    //put val in the "middle" - 1
    head_->val[ARRSIZE / 2 - 1] = val;
  }
  //check if tail is full
  if(tail_->last == ARRSIZE){
    //create a new Item
    tail_->next = new Item();
    //update previous in the new Item
    tail_->next->prev = tail_;
    //point tail to the new Item
    tail_ = tail_->next;
    //initialize val at 0th index to val passed in
    tail_->val[0] = val;
    //increment last
    tail_->last++;
  }
  //if tail is not full
  else{
    //assign val to last index of array and increment last
    tail_->val[tail_->last++] = val;
  }
}

void ULListStr::push_front(const std::string& val){
  if(!head_){
    //create a new Item
    head_ = new Item();
    //set head pointer to point to the new Item
    tail_ = head_;
    //set last to the "middle"
    head_->last = ARRSIZE / 2;
    //put val in the "middle" - 1
    head_->val[ARRSIZE / 2 - 1] = val;
  }
  //check if head is full
  if(head_->last == ARRSIZE){
    //create a new Item
    head_->prev = new Item();
    //update next in the new Item
    head_->prev->next = head_;
    //assign head to the new Item
    head_ = head_->prev;
    //update first and last
    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;
    //insert val
    head_->val[head_->first] = val;
  }
  //if head is not full
  else{
    //assign val to the first index of the array and increment first
    head_->val[--head_->first] = val;
  }
}

void ULListStr::pop_back(){
  //check if there is only one element
  if(tail_->last == tail_->first - 1){
    //check if there is only one node
    if(head_ == tail_){
      //delete node and make head and tail pointers null
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
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
}

void ULListStr::pop_front(){
  //check if there is only one element
  if(head_->first == ARRSIZE - 1){
    //check if there is only one node
    if(head_ == tail_){
      //delete node and make head and tail pointers null
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
      return;
  }
    //move head forward one
    head_ = head_->next;
    //delete old head
    delete head_->prev;
    //update prev to nullptr
    head_->prev = nullptr;
  }
  else{
    //increment first
    head_->first++;
  }
}

std::string const& ULListStr::back() const{
  return tail_->val[tail_->last - 1];
}

std::string const& ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  Item* temp = head_;
  size_t count = 0;
  while(count != loc){
    count++;
  }



  // //checks if ull is empty
  // if(head_ == nullptr){
  //   return nullptr;
  // }

  // Item* temp = head_;

  // size_t count = 0;
  // size_t pos = head_->first;
  // while(count != loc){
  //   pos++;
  //   count++;
  //   if(pos == ARRSIZE){
  //     pos = 0;
  //     if(temp->next == nullptr){
  //       return nullptr;
  //     }
  //     temp = temp->next;
  //   }
  // }

  // return &(temp->val[pos]);



  // //come back to this if getValAtLoc doesn't work
  // if(loc > size_){
  //   return nullptr;
  // }
  // Item* temp = head_;
  // size_t pos = head_->first;
  // size_t count = 0;
  // while(count != loc){
  //   count++;
  //   pos++;
  //   if(pos == ARRSIZE){
  //     if(temp->next == nullptr){
  //       return nullptr;
  //     }
  //     temp = temp->next;
  //     pos = 0;
  //   }
  //   // //if position is at the max size, go to the next node
  //   // if(pos == ARRSIZE){
  //   //   temp = temp->next;
  //   //   pos = 0;
  //   // }
  //   // pos++;
  //   // // //if we are in the tail node and reached the last index, return null
  //   // // if(pos == temp->last - 1 && temp == tail_){
  //   // //   return NULL;
  //   // // }
  // }
  // return &(temp->val[pos]);
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
