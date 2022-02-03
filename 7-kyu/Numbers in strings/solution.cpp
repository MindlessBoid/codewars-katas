#include <string>
int solve(std::string s){
  // to deal with if the number is at the end of the string
  // can just compare once more at the end, e.g. max(max, buffer)
  s += 'a';
  int max = 0;
  int buffer = 0;
  for(auto c: s)
  {
    if(isdigit(c)) buffer = buffer*10 + (c - '0');
    else
    {
      if(buffer > max) max = buffer;
      //reset
      buffer = 0;
    }
  }
  return max;
}