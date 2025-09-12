#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

  ULListStr emptyCase = ULListStr();
  std::cout << "TESTING: ULListStr EMPTY CASES" << std::endl;
  
  emptyCase.push_back("k"); // empty  
  std::cout << emptyCase.size() << std::endl; // check size (added)

  emptyCase.pop_back(); // only one item, delete 
  std::cout << emptyCase.size() << std::endl; // check size

  emptyCase.push_front("s"); // empty
  std::cout << emptyCase.size() << std::endl; // check size

  emptyCase.pop_front(); // only one item, delete
  std::cout << emptyCase.size() << std::endl; // check size

  ULListStr studentTest = ULListStr();

  std::cout << "TESTING: ULListStr MORE THAN ONE CASES" << std::endl;
  
  // should print testing
  studentTest.push_front("s"); 
  std::cout << studentTest.size() << std::endl; // check size

  studentTest.push_front("e");
  std::cout << studentTest.size() << std::endl; // check size
 
  studentTest.push_back("i"); 
  std::cout << studentTest.size() << std::endl; // check size

  studentTest.push_back("n"); 
  std::cout << studentTest.size() << std::endl; // check size

  studentTest.push_back("g"); 
  std::cout << studentTest.size() << std::endl; // check size

  studentTest.push_front("T");
  std::cout << studentTest.size() << std::endl; // check size


  // to be deleted by pop_back and pop_front
  studentTest.push_front("C");
  std::cout << studentTest.size() << std::endl; // check size

  studentTest.push_back("S");
  std::cout << studentTest.size() << std::endl; // check size
 
  studentTest.push_front("I"); 
  std::cout << studentTest.size() << std::endl; // check size

  studentTest.push_back("C");
  std::cout << studentTest.size() << std::endl; // check size

  for (size_t i = 0; i < studentTest.size(); i++) {
    std::cout << studentTest.get(i) << std::endl;
  }

  std::cout << std::endl; 

  std::cout << studentTest.size() << std::endl; // print num of strings stored
  // should b 11

  // deleting
  studentTest.pop_back();
  studentTest.pop_front();
  studentTest.pop_back();
  studentTest.pop_front();

  std::cout << studentTest.size() << std::endl; 
  // should b 7

  // reprinting
  for (size_t i = 0; i < studentTest.size(); i++) {
    std::cout << studentTest.get(i) << std::endl;
  }

  std::cout << std::endl; 

  std::cout << studentTest.back() << std::endl;
  std::cout << studentTest.front() << std::endl;
}
