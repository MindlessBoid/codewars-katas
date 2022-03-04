#include <string>
#include <cmath>
/*Test*/
int last_digit(const std::string &str1, const std::string &str2) {
  /* Source: https://brilliant.org/wiki/finding-the-last-digit-of-a-power/ 
    1)Pattern:
      Digit d | d^1  d^2  d^3  d^4
        1     | 1    
        2     | 2    4    8    6
        3     | 3    9    7    1
        4     | 4    6    
        5     | 5
        6     | 6
        7     | 7    9    3    1
        8     | 8    4    2    6
        9     | 9    1
      The maximum length is cycle repitiion is 4.
    2)Any number that has more than 2 digits can be written as:
                  100*k + ab
      Since 100*k is divisible by 4 -> just need to check ab for remainder
  */

  // Case exponent = 0
  if(str2 == "0") return 1;
  
  // Case base = 0
  if(str1 == "0") return 0;
  
  // Other cases
  int base = str1.back() - '0';
  //last 2 digits of exponent, if str2 is longer than 2 than add the second to last digit
  int exp = (*str2.rbegin() - '0') + (str2.length(
    
  ) < 2 ? 0 :(*(str2.rbegin() + 1) - '0') * 10);
  return static_cast<int>(pow(base, exp%4 == 0 ? 4 : exp%4)) % 10;
}