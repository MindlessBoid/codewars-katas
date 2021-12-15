#include<cmath>
const double PI  = 3.141592653589793238463;
double square_area(double A) {
  double result = 4*A*A/(PI*PI);
  return round(result*100) / 100.0;
};