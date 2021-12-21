#include <cmath>
typedef unsigned long long ull;
class SumFct
{
  public:
  static ull perimeter(int n)
  {
    ull prev = 0;
    ull curr = 1;
    ull sum = 0;
    while(n-- >= 0)
    {
      sum += 4 * curr;
      curr = curr + prev;//new curr
      prev = curr - prev;//prev = old curr
    }
    return sum;
  }

};