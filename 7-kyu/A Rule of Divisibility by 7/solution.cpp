#include <utility>
class DivSeven
{
public:
    static std::pair<long long, long long> seven(long long m)
{
  long long count = -(!m); //case m = 0 => count = -1  or just use while loop instead of do-while
  long long prev = 0;
  do
  {
    m = m/10 - 2 * (m%10);
    count++;
  } while(m >= 100);
  return {m, count};
}
};