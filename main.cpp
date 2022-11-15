#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

#include "CustomAssert.hh"
#define NDEBUG

typedef unsigned int uint_32;

struct Err {

};

std::string intToBinary(int i){
  std::string answer = "";
  if (i > 1){
    while (i != 0){
      int q = i%2;
      answer += std::to_string(q);
      i /= 2;
    }
  }
  return answer;
}

// lambda function 🧠🧠
auto testCases = [](auto func, auto expected) {
  uint_32 passedTestcases = 0;
  // map <int, int>
  for (auto i: expected){
    try {
      Assert<Err>(func(i.first) == i.second);
    } catch(Err err){
      std::stringstream ss;
      std::string hi;
      std::string hi2;
      ss << func(i.first);
      hi = ss.str();
      ss.str(std::string());
      ss << i.second;
      hi2 = ss.str();
      return "Assertion failed at testcase #" +  std::to_string(passedTestcases) + " (Expected " + hi + " but got " + hi2 + ") Passed " + std::to_string(passedTestcases) + "/" + std::to_string(expected.size()) + " testcases."; 
    }
    passedTestcases++;
  }

  return "Passed " + std::to_string(passedTestcases) + "/" + std::to_string(expected.size()) + " testcases."; 
};

int main() {
    // try to make it typename iterator_traits<Iter>::value_type for more flexibility
  
  std::vector<std::pair<int,std::string>> testcasesExpect {{55,"110111"}};
  // give it a input and expected val in the std::pair
  std::cout << testCases(intToBinary,testcasesExpect);
  return 0;
}
