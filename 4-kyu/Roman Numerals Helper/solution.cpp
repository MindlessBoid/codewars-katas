#include <string>
#include <map>
class RomanHelper{
  public:
    std::string to_roman(unsigned int n){
      const std::string symbols[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
      const int symbolValues[13] =    { 1,   4,    5,   9,    10,  40,   50,  90,   100, 400,  500, 900,  1000};
      std::string result;
      //start at the largest value 1000
      size_t i = 12;
      while(n > 0)
      {
        //if n < symbolValue[i], quotient = 0, remainder = same
        int quotient = n / symbolValues[i] ;
        n %= symbolValues[i]; 
        while(quotient-- > 0)
        {
          result += symbols[i];
        }
        i--;
      }
      return result;
    }

    int from_roman(std::string rn){
      std::map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
      int sum = 0;
      for(size_t i = 0; i < rn.length() - 1; i++)
      {
        //check the next element
        int currVal = map[rn[i]];
        int nextVal = map[rn[i+1]];
        sum += (currVal >= nextVal) ? currVal : - currVal;
        if(i == rn.length() - 2) sum += nextVal;
      }
      //add the last character
      return sum + map[rn.back()];
    }
};
