#include <cmath>
class Movie
{
public:
    static int movie(int card, int ticket, double perc)
    {
      double sysA = 0;
      double sysB = card;
      int count = 0;
      while(ceil(sysA) <= ceil(sysB))
      {
       count++;
       sysA += ticket;
       sysB += ticket*pow(perc, count);
      }
      return count;
    }
};