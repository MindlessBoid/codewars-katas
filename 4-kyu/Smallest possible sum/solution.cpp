#include <vector>

typedef unsigned long long ull;
ull gcd(ull a, ull b)
{
    return b == 0 ? a : gcd(b, a%b);
}
ull solution(const std::vector<unsigned long long>& arr){
  ull divisor = arr[0];
  for(size_t i = 1; i < arr.size(); i++)
  {
    divisor = gcd(divisor, arr[i]);
  }
  return divisor * arr.size();
}