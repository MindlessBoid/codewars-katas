#include <cmath>
//the jizz is finding the most significant bit
//this method is prone to round error but works fine in this kata
unsigned int squaresNeeded(long long n) {
  return log2(n) + 1;
}
