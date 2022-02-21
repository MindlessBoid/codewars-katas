#include <vector>
typedef unsigned long long ull;
std::vector<ull> odd_row(ull n) {
  /*
    the 1st element of n-row = n-row * (n-row - 1) + 1
    e.g: 2nd row: 3 = 2*1 + 1
         3rd row: 7 = 3*2 + 1
        4th row: 13 = 4*3 + 1
        ....
  */
  std::vector<ull> result;
  for(size_t i = 0; i < n; i++) result.push_back(n*(n-1)+1 + 2*i);
  return result;
}

/* Not so good solution
std::vector<unsigned long long> odd_row(unsigned long long n) {
  //sum of the total odd numbers in the triangle
  unsigned long long m = n*(n+1)/2;
  //odd number: 2k + 1, k is integer >= 0
  std::vector<unsigned long long> result;
  for(auto i = 0ULL; i < n; i++)
  {
    result.push_back(2*(m - n + i) + 1);
  }
  return result;
}
*/