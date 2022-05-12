#include <stdint.h>
#include <cmath>
uint32_t amount_of_pages(uint32_t summary){
  uint32_t total_prev_digits = 0;
  for(int i = 1; i < 6; i++)
  {
    // number of digits of numbers that have i digits 
    // e.x. number of digits of 2-digit numbers is 2*(10^2 - 10) = 180
    uint32_t digits = i * (pow(10, i) - pow(10, i-1));
    if(summary <= total_prev_digits + digits)
    {
      return (summary - total_prev_digits)/i + pow(10, i-1) + 1;
    }
  }
  return 0;
}