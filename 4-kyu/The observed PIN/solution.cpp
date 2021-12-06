#include <vector>
#include <string>


/*Solution w/o recursion*/
std::vector<std::string> get_pins(std::string observed) {
 
  std::vector<std::string> v = {"08", "124", "1235", "2356", "1457", "24568", "3569", "478", "05789", "689"};
  
  //vector to store iterators to strings of v, each string corresponds to a character of the PIN
  std::vector<std::string::iterator> its;
  for (auto c: observed)
  {
    its.push_back(v[c - '0'].begin());
  }
  std::vector<std::string> result;
  while (its[0] != v[observed[0] - '0'].end())
  {
    //retrieve a combination
    std::string combination;
    for(auto it: its) combination.push_back(*it);
    result.push_back(combination);

     //the last iterator should always be incremented
    its.back()++;
    
     //check iterators vector if the neighbor to the right is end() then increment by one and reset the neighbor
     //!DO NOT CHECK i == 0 cause if so the 1st iterator will loop back => infinite loop => i-- > 1
    for(size_t i = its.size(); (i-- > 1) && (its[i] == v[observed[i] - '0'].end()); )
    {
      //wrap back
      its[i] = v[observed[i] - '0'].begin();
      its[i-1]++;
    }
  }
  return result;
}