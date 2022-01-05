#include <string>
#include <numeric>
using namespace std;

/*
string balancedNum (unsigned long long int number)
{
  std::string str = std::to_string(number);
  size_t n = str.length()/2;
  bool isEven = str.length()%2 == 0;
  return std::accumulate(str.begin(), str.begin() + n + (isEven ? -1 : 1), 0)
      == std::accumulate(str.rbegin(), str.rbegin() + n + (isEven ? -1 : 1), 0) 
      ? "Balanced" : "Not Balanced";
 }
 */


string balancedNum (unsigned long long int number )
{
  std::string str = std::to_string(number);
  size_t n = str.length()/2 + (str.length()%2 == 0 ? -1 : 1);
  int sum = 0;
  for(size_t i = 0; i < n; i++)
    sum += str[i] - str[str.length() - 1 - i];
  return (sum != 0) ? "Not Balanced" : "Balanced";
}