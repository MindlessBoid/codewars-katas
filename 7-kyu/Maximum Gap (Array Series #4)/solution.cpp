#include <vector>
#include <algorithm>
using namespace std; 

int maxGap (vector <int> numbers)
{
  std::sort(numbers.begin(), numbers.end());
  int maxGap = numbers[1] - numbers[0];
  for(size_t i = 1; i < numbers.size(); i++)
  {
    int currGap = numbers[i] - numbers[i-1];
    if(currGap > maxGap) maxGap = currGap;
  }
  return maxGap;

}