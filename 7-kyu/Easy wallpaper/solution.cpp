#include <cmath>
#include <string>
using namespace std;

class Wallpaper
{
  public:
  static string wallPaper(double l, double w, double h)
  {
     std::string map[21] = {"zero", "one", "two", "three", "four",
                         "five", "six", "seven", "eight", "nine",
                         "ten", "eleven", "twelve", "thirteen", "fourteen",
                         "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                        "twenty"};
    //count how many rolls does it take to cover (l+w) length then multiply with number of rolls u can stack vertically
    int n = (l == 0 || w == 0 || h == 0) ? 0 : ceil(((l+w)*2*1.15/10) * (h/0.52));
    return map[n];
  }
};