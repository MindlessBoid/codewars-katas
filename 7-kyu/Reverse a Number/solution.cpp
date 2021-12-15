#include <string>

/* string solution
long long reverseNumber(long long n) {
  std::string str = std::to_string(n);
  return stoll((str.front() == '-' ? "-" : "") + std::string(str.rbegin(), str.rend() + (str.front() == '-' ? 1 : 0)));
}
*/
long long reverseNumber(long long n) {
  long long result = 0;
  while(n != 0)
  {
    //increase the place values of result while decreasing n
    result = result*10 + n%10;
    n/=10;
  }
  return result;
}