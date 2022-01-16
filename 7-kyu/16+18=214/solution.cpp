#include<string>
/*
unsigned add(unsigned x, unsigned y)
{
  unsigned result = 0;
  unsigned placeVal = 1;
  while(x != 0 || y != 0)
  {
    unsigned sum = (x%10) + (y%10);
    result  += sum*placeVal;
    placeVal *= (sum > 9) ? 100 : 10;
    x/=10; 
    y/=10;
  }
  return result;
}
*/

unsigned add(unsigned x, unsigned y)
{
  std::string n;
  while(x>0 || y>0)
  {
    n = std::to_string((x%10) + (y%10)) + n; 
    x /= 10;
    y /= 10;
  }
  return !n.empty() ? std::stoi(n) : 0;
}