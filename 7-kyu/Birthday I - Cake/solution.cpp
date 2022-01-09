#include <string>

std::string cake(int x, std::string y){
  double sum = 0;
  for(size_t i = 0; i < y.length(); i++) sum += y[i] - (('a' - 1) * (i%2));
  return sum > 0.7*x ? "Fire!" : "That was close!";
}