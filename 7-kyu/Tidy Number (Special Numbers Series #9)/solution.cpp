#include <string>

using namespace std; 

// Tidy number = non-decreasing digits = ascending digits

#include <string>
#include <algorithm>
using namespace std; 


bool tidyNumber (int number)
{
  std::string num  = std::to_string(number);
  return std::is_sorted(num.begin(), num.end());
}
/*
bool tidyNumber (int number)
{
  while(number > 0)
  {
    int last = number%10;
    number /= 10;
    //compare last digit to current
    if(last < number%10) return false;
  }
  return true;
}
*/