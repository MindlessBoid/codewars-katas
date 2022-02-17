#include<string>
#include<stdio.h>
#include <numeric>
#include <iterator>
#include <sstream>

//not using str replace
std::string calculate(std::string str)
{
  std::string temp;
  for(auto c: str)
  {
    if(c == 'p') temp.push_back(' ');
    else if(c == 'm') temp.push_back(' -');
    else if(isdigit(c)) temp.push_back(c);
  }
  std::istringstream is(temp);
  return std::to_string(std::accumulate(std::istream_iterator<int>(is), std::istream_iterator<int>(), 0));
}

/*
//using str replace
std::string calculate(std::string str)
{
  while(str.find("minus") != std::string::npos) str.replace(str.find("minus"), 5, " -");
  while(str.find("plus") != std::string::npos) str.replace(str.find("plus"), 4, " ");
  std::istringstream is(str);
  return std::to_string(std::accumulate(std::istream_iterator<int>(is), std::istream_iterator<int>(), 0));
}
*/

/* 
//basic loop solution
std::string calculate(std::string str)
{
  int result = 0;
  std::string num = ""; //to store numbers
  bool isPlus = true; //cause a number will always be at the beginning;
  for(size_t i = 0; i < str.length(); i++)
  {
    if(str[i] == 'm') isPlus = false;
    else if(str[i] == 'p') isPlus = true;
    else if(isdigit(str[i]))
    {
      num.push_back(str[i]);
      //check the neighbor to the right
      if(!isdigit(str[i+1]) || i + 1 == str.length())
      {
        result += (isPlus ? 1 : -1) * std::stoi(num);
        num = "";
      } 
    }
  }
  return std::to_string(result);
}
*/