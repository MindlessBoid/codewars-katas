#include <stdint.h>

int digits(uint64_t n) {
  int count = !n;
  while(n > 0)
  {
    count++;
    n/=10;
  }
  return count;
}