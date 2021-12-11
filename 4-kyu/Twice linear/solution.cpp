#include <set>
#include <vector>

/*REFERRENCE: https://www.geeksforgeeks.org/ugly-numbers/*/

//dynamic programming
/*int dblLinear(int n)
{
  std::vector<int> seq = {1};
  int next_2x = 0, i1 = 0;
  int next_3x = 0, i2 = 0;
  while (seq.size() <= n)
  {
    next_2x = 2*seq[i1] + 1;
    next_3x = 3*seq[i2] + 1;

    //whichever is lower push to seq and increment the corresponding index, 
    //case == push either and inscrease both indices
    if(next_2x <= next_3x)
    {
      seq.push_back(next_2x);
      i1++;
      if(next_2x == next_3x) i2++;
    }
    else if(next_3x < next_2x)
    {
      seq.push_back(next_3x);
      i2++;
    }
   
  }
  return seq[n];
}*/

//using set
int dblLinear(int n)
{
  std::set<int> s = {1};
  std::set<int>::iterator it = s.begin();
  while(n-- != 0)
  {
    s.insert(2*(*it) + 1);
    s.insert(3*(*it) + 1);
    it++;
  }
  return *it;
}

