#include <vector>
#include <stdexcept>

class NewAverage
{
public:
   static long long newAvg(std::vector<double> &arr, double navg)
   {
     double newAvg = 0.0;
     for(auto i : arr) newAvg += i;
     newAvg = navg*(arr.size() + 1) - newAvg;
     if(newAvg < 0) throw std::invalid_argument("Invalid argument");
     else return (long long)newAvg + (newAvg > (long long)newAvg ? 1 : 0);
   }
};