#include <string>

// Ideal is derived from checking balanced bracket in an expression
std::string remove_parentheses(const std::string &str)
{
  std::string result;
  int numParetheses = 0;
  for(char c: str)
  {
    if(c == '(') numParetheses++;
    else if (c == ')') numParetheses--;
     //should be else if cause using if may include the last ')' inside the result
    else if(!numParetheses) result.push_back(c);
  }
  return result;