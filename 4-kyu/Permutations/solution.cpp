#include <string>
#include <vector>
#include <algorithm>
#include <set>

/* Using algorithm>
std::vector<std::string> permutations(std::string s) {
  std::sort(s.begin(), s.end());
  std::vector<std::string> result;
  do{
    result.push_back(s);
  }while(std::next_permutation(s.begin(), s.end()));
  return result;
}
*/

/*https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/?ref=lbp*/
void genPermutations(std::string lhs, std::string rhs, std::set<std::string>& result)
{
  /*1. |abcd
        lhs = "", rhs = "abcd"
        swap 1st char of rhs swap(a, a), swap(a, b),...swap(a, d)
        then add the 1st char of rhs to lhs and del that char of rhs
    2. a|bcd or b|acd...
       lhs = "a", rhs = "bcd" or lhs = "b", rhs = "acd" ...
    .
    .
    .
    Till rhs has the length of 1
  */
  //base condition
  if(rhs.length() == 1) result.insert(lhs + rhs);
  //border case 
  else if(rhs.length() == 0) result.insert("");
  else
  {
    for(size_t i = 0; i < rhs.length(); i++)
    {
      std::string temp(rhs);
      std::swap(temp.front(), temp[i]);
      genPermutations(lhs + temp.front(), temp.substr(1), result);
    }
  }
}

std::vector<std::string> permutations(std::string s) {
  std::set<std::string> permuList;
  genPermutations("", s, permuList);
  return std::vector<std::string>(permuList.begin(), permuList.end());
}