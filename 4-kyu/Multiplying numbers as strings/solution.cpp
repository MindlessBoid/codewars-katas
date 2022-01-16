#include <string> 
#include <vector>


std::string multiply(std::string a, std::string b) 
{
  //to store the digits, size of length 1 + length2 should be more than enough
  std::vector<unsigned> result(a.length() + b.length(), 0);
  //to keep track of which digit are we at in the result array, n1_max should be the total number of multiplications we need to perform
  size_t n1 = 0; 
  unsigned carry = 0;
  for(size_t i = a.length(); i-- > 0;)
  {
     //n2 starts from n1 and moves forward
    size_t n2 = n1;
    for(size_t j = b.length(); j-- > 0;)
    {
      //should add the result's digit here cause the last digit addition may overflow to next digit 
      unsigned mul = (a[i] - '0') * (b[j] - '0') + carry + result[n2]; 
      result[n2++] = mul%10 ;
      carry = mul/10;
    }
    //deal with left over carry
    while(carry > 0)
    {
      result[n2++] += carry%10;
      carry /= 10;
    }
    n1++;
  }
  //deal with trailing 0, keep 1 element for boder case: multiply with 0
  //TODO: deal with empty inputs
  while(result.back() == 0 && (result.size() > 1)) result.pop_back();
  std::string str;
  for(auto it = result.rbegin(); it != result.rend(); it++)
  {
    str.push_back((*it) + '0');
  }
  return str;
}