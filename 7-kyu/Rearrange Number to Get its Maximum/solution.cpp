void swap(int& x, int& y)
{
  x ^= y;
  y ^= x;
  x ^= y;
}
int max_redigit(const int& num) {
  if(num<100 || num>999) return -1;
  int a = num%10;
  int b = num/10%10;
  int c = num/100;
  //check a with b and c 1st, then check b with c
  if(a < b) swap(a, b);
  if(a < c) swap(a, c);
  if(b < c) swap(b, c);
  return a*100 + b*10 + c;
}
/*#include <string>
#include <algorithm>
int max_redigit(const int& num) {
  if(num > 999 || num < 100) return -1;
  std::string str = std::to_string(num);
  std::sort(str.rbegin(), str.rend());
  return std::stoi(str);
}*/