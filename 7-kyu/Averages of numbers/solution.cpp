#include <vector>
std::vector<double> averages(std::vector<int> numbers)
{
    std::vector<double> result;
    for(size_t i = 1; i < numbers.size(); i++)
    {
      result.push_back((numbers[i] + numbers[i+1])/2.0);
    }

    return result;
}