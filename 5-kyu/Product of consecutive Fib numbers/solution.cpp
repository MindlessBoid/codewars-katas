#include <vector>
typedef unsigned long long ull;
class ProdFib
{
public:
  static std::vector<ull> productFib(ull prod)
  {
    ull a = 0;
    ull b = 1;
    while(a * b < prod)
    {
      //can use a temp var
      b = b + a;//new b = next fib number
      a = b - a;//new a = previous b
    }
    return {a, b, a*b == prod};
  }
};