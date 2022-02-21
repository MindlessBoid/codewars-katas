#include <array>

std::array<int, 10> paint_letterboxes(int start, int end)
{
  std::array<int, 10> result = {0};
  for(int i = start;  i <= end; i++)
  {
    int num = i;
    while(num)
    {
      result[num%10]++;
      num/=10;
    }
  }
  return result;
}