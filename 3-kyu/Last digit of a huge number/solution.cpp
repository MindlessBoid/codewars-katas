#include <list>
#include <iostream>
#include<cmath>
using namespace std;
std::list<int> processZeros(const std::list<int>& arr)
{
  // Eleminate all consecutive 0s
  std::list<int> result;
  int count = 0;
  bool prev = false; //check if prev is a 0
  for(auto it = arr.begin(); it != arr.end(); it++)
  {
    if(*it != 0)
    {
      if(!prev) result.push_back(*it);
      else break;
    }
    else
    {
      count++;
      prev = true;
    }
  }
  if(count%2 == 1)
  {
    // odd nmber of 0s -> 0
    if(result.empty()) result.push_back(0);
    else result.back() = 1;
  }
  return result;

}
int last_digit(std::list<int> array) 
{
  //Digits  | Last digits cycles
  // 1      | 1
  // 2      | 2, 4, 6, 8
  // 3      | 3, 9, 7, 1
  // 4      | 4, 6
  // 5      | 5
  // 6      | 6
  // 7      | 7, 9, 3, 1
  // 8      | 8, 4, 2, 6
  // 9      | 9, 1
  // Dealing with 0s
  auto arr = processZeros(array);
  // Case: empty 
  if(arr.empty()) return 1;

  // Case: the base is 0 or ends with 0
  if((arr.front()%10) == 0) return 0;

  auto it = arr.begin();
  int base = *it;
  // Case: 1 number
  if(arr.size() == 1) return base%10;
  
  // Case: 2 numbers
  std::advance(it, 1);
  int exponent1 = *it;
  if(arr.size() == 2) return static_cast<int>(pow(base%10, exponent1 % 4 == 0 ? 4 : exponent1%4)) % 10;

  // Case: more than 3
  // Source: https://math.stackexchange.com/a/2713380
  std::advance(it, 1);
  int exponent2 = *it;
  std::advance(it, 1);
  if(*it == 0) exponent2 = 1;
  int mod2 = base%2;
  int mod5 = 0;
  if(base%5 != 0)
  {
    base %= 5;
    if(exponent1%2 == 0) mod5 = (exponent2 == 1) ? (base*base)%5 : 1;
    else
    {
      exponent1 %= 4;
      exponent2 %= 2;
      mod5 = static_cast<int>(pow(base, pow(exponent1, exponent2))) % 5;
    }
  }
  int d = 1;
  while(true)
  {

    if(d%2 == mod2 && d%5 == mod5) break;
    d++;
  }
  return d;
}
