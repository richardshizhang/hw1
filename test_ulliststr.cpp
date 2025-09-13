#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr* u = new ULListStr();

  std::string s = "1";
  // u->push_back(s);
  // u->pop_back();
  // u->pop_back();
  std::string s2 = "2";
  std::string s3 = "3";
  u->push_back(s);
  u->push_back(s2);
  u->push_back(s3);
  // std::cout<<u->size()<<std::endl;
  // std::cout<<u->front()<<std::endl;
  // std::cout<<u->back()<<std::endl;
  std::cout<<u->get(0)<<std::endl;
  // std::cout<<u->get(1)<<std::endl;
  // std::cout<<u->get(2)<<std::endl;
  delete u;
}
