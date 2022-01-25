#include <vector>

bool isPrime(unsigned short int num)
{
  if(num <= 1) return false;
  if(num <= 3) return true;
  if(num%2 == 0 || num%3 == 0) return false;
  //6k-1 and 6k +1
  //can be overflown
  for(int i = 5; i*i <= num; i += 6)
  {
    if(num%i == 0 || num%(i + 2) == 0) return false;
  }
  return true;
}
unsigned long long numPrimorial (unsigned short int number )
{
  int pCount = 0;
  unsigned long long result = 1;
  int currPrime = 0;
  while(pCount < number)
  {
    if(isPrime(currPrime))
    {
      result *= currPrime;
      pCount++;
    }
    currPrime++;
  }
  return result;
}
/*
// Start with 2 increment by 1 till number of primes is met
// only need to check if the current number is prime or not with the stored primes (vector)
unsigned long long numPrimorial (unsigned short int number )
{
  unsigned long long result = 2;
  std::vector<unsigned short int> v = {2};
  int i = 1;
  while(v.size() < number)
  {
    int currPrime = 2 + i;
    bool isPrime = true;
    for(auto i: v)
    {
      if(currPrime % i == 0) isPrime = false;
    }
    if(isPrime) 
    {
      result *= currPrime;
      v.push_back(currPrime);
    }
    i++;
  }
  return result;
}
*/