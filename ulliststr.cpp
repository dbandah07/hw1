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

// MY CODE BEGINS
// first is inclusive, last is exclusive
// first = 0, last = 0 -> none of the elements are used
// first = 0, last = ARRSIZE -> fully occupied

void ULListStr::push_back(const std::string& val) {
  // Adds new value to the back of list

  // if array IS NOT full, add it to the end of last val, 
  // if array IS full, make new node

  if (size_ == 0) { // empty, uninitialized
    head_ = new Item();
    tail_ = head_;
    // std::cout << "DEBUG: in push_back first if" << std::endl;
    head_->first = 0;
    head_->last = 1;
    head_->val[0] = val;
    head_->next = nullptr;
    head_->prev = nullptr;
    size_++;
    return;
  }


  // array is FULL
  if (tail_->last == ARRSIZE) { 
    // std::cout << "DEBUG: in second if statement " << std::endl;
    Item* add = new Item();
    add->first = 0;
    add->last = 1;
    add->val[0] = val;


    // update tail
    tail_->next = add;
    add->prev = tail_;
    tail_= add; // new tail is the new node
    
  }
  // array has items, adding to wtvrs at the end;
  else {
    // std::cout << "DEBUG: in push_back else" << std::endl;

    tail_->val[tail_->last] = val;
    tail_->last++; // ICREMENTTTTT     
  }

  size_++; // increment size var
}


// not passing :  
// UnrolledList.Back_PushBack
// UnrolledList.Back_PushFront


void ULListStr::pop_back() {
  // Removes from back of list

  // cases:
  // list is empty, if theres only one node (head == tail), and if theres more

  if (tail_ == nullptr) { // empty
    return;
  }

  tail_->last--; // removes element

  if (tail_->first == tail_->last) { // if same then,
    if (tail_ == head_) { // they're e/o 
      tail_ = nullptr;
      delete head_;
      head_ = nullptr;
    }

    else { // theres more
      Item* temp = tail_;
      tail_ = tail_->prev; // go back
      tail_->next = nullptr; 
      delete temp;
    }
  }
  size_--;
}

void ULListStr::push_front(const std::string& val) {
  // Adds value to the front of list
  // if there's room b4 the first val in the head node,
  // add it there, otherwise, allocate new head node
  // array is FULL 


  // UPDATED: 
  if (size_ == 0) { // empty, uninitialized
    head_ = new Item();
    tail_ = head_;
    // std::cout << "DEBUG: in push_front first if" << std::endl;
    head_->last = head_->first + 1;
    head_->val[head_->first] = val;
    head_->next = nullptr;
    head_->prev = nullptr;
    size_++;
    return;
  }

  if (head_->first == 0) {
    // std::cout << "DEBUG: in push_front second if" << std::endl;

    Item* add = new Item();

    // last is exclusive
    add->last = ARRSIZE;
    add->first = ARRSIZE - 1;

    add->val[add->first] = val; 
    head_->prev = add;
    add->next = head_;
    head_ = add; // update head

  }

  else {
    // std::cout << "DEBUG: in push_front else" << std::endl;
    
      head_->first--; // make space BEFORE first ?
      head_->val[head_->first] = val; // array has items, adding to front of them;
  }
  size_++;
}

void ULListStr::pop_front() {
  // Removes val from front of list
  // list is empty, if theres only one node (head == tail), and if theres more

  if (head_ == nullptr) { // empty
    return;
  }

  head_->first++; // remove one element

  if (head_->first == head_->last) {
    if (head_ == tail_) { // one
      tail_ = nullptr;
      delete head_;
      head_ = nullptr;
    }
    else { // 2+
      Item* temp = head_;
      head_ = head_->next;
      head_->prev = nullptr;
      delete temp;
    }
  }
  size_--; // increment size var

}

std::string const & ULListStr::back() const {
  // returns const reference to the back element
  // std::string const & last_element = " ";
  // tail_->val[tail_->last-1] = last_element;

  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const {
  // returns const reference to the front element
  // std::string const & front_element = " ";
  // head_->val[head_->first] = front_element;

  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  // private
  // returns a pointer to the item at index, loc, if loc is valid
  // NULL otherwise
  
  std::string* ptr = &head_->val[head_->first];

  Item* t_ptr = head_; 

  if (loc > size_) { // loc is not valid
    // std::cout << "DEBUG: invalid loc " << loc << " size_ = " << size_ << std::endl;
    return NULL;
  }


  // std::cout << "DEBUG: starting loop for loc " << std::endl;  
  // loc IS valid
  for (size_t i = 0; i < loc; i++) { // loop thru list until loc is found, return the ptr;
    // std::cout << "DEBUG: i = " << i << std::endl;
    // std::cout << "DEBUG: ptr points to " << *ptr << std::endl;
    // std::cout << "DEBUG: first = " << t_ptr->first << std::endl;
    // std::cout << "DEBUG: last =  " << t_ptr->last << std::endl;

    if (ptr == &t_ptr->val[t_ptr->last-1]) { // if its the last in the Nodes' array, 
      
      // if (t_ptr->next == nullptr) {
      //   std::cout << "DEBUG: node is null, invalid" << std::endl;
      //   return nullptr;
      // }
      // // then move to next Node
      // std::cout << "DEBUG: inside if-statement" << std::endl;

      t_ptr = t_ptr->next;
      ptr = &t_ptr->val[t_ptr->first];  // assing first 
      
      // std::cout << "DEBUG: first = " << t_ptr->first << std::endl;
      // std::cout << "DEBUG: last = " << t_ptr->last << std::endl;
    
    }
    else {
      ptr++;
    }
  }
  
  return ptr;
}

// MY CODE ENDS 

// PROVIDED CODE BEGINS (again)

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
