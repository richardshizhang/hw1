#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
void check_empty(ULListStr& u);
void check_back(ULListStr& u);
void check_front(ULListStr& u);
int main(int argc, char* argv[])
{
  ULListStr u;
  check_empty(u);
  check_back(u);
  check_front(u);
}
void check_empty(ULListStr& u){
  //check empty cases
  u.pop_back();
  u.pop_front();
  //add one value and empty twice
  std::string s = "0";
  u.push_back(s);
  u.pop_back();
  u.pop_front();
  // check empty in middle
  std::string s0 = "0";
  u.push_back(s0);
  std::string s1 = "1";
  u.push_back(s1);
  std::string s2 = "2";
  u.push_back(s2);
  u.pop_front();
  u.pop_back();
  u.pop_back();
  u.pop_front();
  u.pop_back();
}
void check_back(ULListStr& u){
  std::string s0 = "0";
  u.push_back(s0);
  std::string s1 = "1";
  u.push_back(s1);
  std::string s2 = "2";
  u.push_back(s2);
  std::string s3 = "3";
  u.push_back(s3);
  std::string s4 = "4";
  u.push_back(s4);
  std::string s5 = "5";
  u.push_back(s5);
  std::string s6 = "6";
  u.push_back(s6);
  std::string s7 = "7";
  u.push_back(s7);
  std::string s8 = "8";
  u.push_back(s8);
  std::string s9 = "9";
  u.push_back(s9);
  std::string s10 = "10";
  u.push_back(s10);
  std::cout<<u.size();
  u.pop_back();
  u.pop_back();
  u.get(7);
  u.back();
  u.front();
}
void check_front(ULListStr& u){
  std::string s0 = "0";
  u.push_front(s0);
  std::string s1 = "1";
  u.push_front(s1);
  std::string s2 = "2";
  u.push_front(s2);
  std::string s3 = "3";
  u.push_front(s3);
  std::string s4 = "4";
  u.push_front(s4);
  std::string s5 = "5";
  u.push_front(s5);
  std::string s6 = "6";
  u.push_front(s6);
  std::string s7 = "7";
  u.push_front(s7);
  std::string s8 = "8";
  u.push_front(s8);
  std::string s9 = "9";
  u.push_front(s9);
  std::string s10 = "10";
  u.push_front(s10);
  std::cout<<u.size();
  u.pop_front();
  u.pop_front();
  u.get(7);
  u.back();
  u.front();

}