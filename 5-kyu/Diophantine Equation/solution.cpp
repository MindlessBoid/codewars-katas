#include <vector>
#include <utility>

class Dioph
{
  public:
  static std::vector<std::pair <long, long>> solEquaStr(long long n);
};

std::vector<std::pair<long, long>> Dioph::solEquaStr(long long n)
{
    /*  
        x^2 - 4*y^2 = n
    <=> (x - 2y) * (x + 2y) = n
    - n must be a composite number -> find n's divisor
    - assume a * b = n with a < b
      then a <= sqrt(n), cause eithet a or b must be <= sqrt(n)
    - x = (a + b) / 2 -> check (a + b)%2
    - y = (b - a) / 4 -> check (b - 4)%4
    */
    std::vector<std::pair<long, long>> result;
    for(long long i = 1; i * i <= n; i++)
    {
      if(n % i == 0)
      {
        long long x = i + n/i;
        long long y = n/i - i;
        if(x%2 == 0 && y%4 == 0)
          result.push_back({x/2, y/4});
      }
    }
    return result;
}