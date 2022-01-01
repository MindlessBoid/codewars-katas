#include <vector>

class Decomp
{
public:
  static std::vector<long long> decompose(long long n);
  static bool divide(std::vector<long long>& v, long long remain, long long last);
};

std::vector<long long> Decomp::decompose(long long n)
{
  std::vector<long long> result;
  if(divide(result, n*n, n))
  {
    return result;
  } 
  return {};
}

bool Decomp::divide(std::vector<long long>& v, long long remain, long long last)
{
  /* Using back tracking
    remain, last
    11^2 ,11
    |
    ---------------------------------------------------------
    |                          |                            |
    11^2 - 10^2, 10            11^2 - 9^2, 9     ...        11^2 - 1^2, 1
    |
    --------------------------------------------------------
    |                          |                           |
    21 - 9^2, 9      ...      21 - 4^2, 4        ...       21 - 1^2, 1
    <0 => return               |                           | 
                               .                           .
                               .                           .
                               .                           .
  */
  //base case 
  if(remain <= 0)
  {
    return remain == 0;
  }
  
  for(long long i = last - 1; i > 0; i--)
  {
    //setting i = last - 1 also eleminates case wher n*n = 1*1 + ... + 1*1;
    if(divide(v, remain - i*i, i))
    {
      v.push_back(i);
      return true;
    }
  }
  //other cases
  return false;
}
