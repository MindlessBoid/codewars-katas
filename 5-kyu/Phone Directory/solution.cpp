#include <string>
#include <sstream>

// !!!!! Random test cases are broken
class PhoneDir
{
public:
    static std::string phone(const std::string& orgdr, std::string num);
};
std::string PhoneDir::phone(const std::string& orgdr, std::string num)
{
  std::stringstream ss1(orgdr);
  std::string buffer1;
  std::string str;
  while(std::getline(ss1, buffer1))
  {
    //found
    if(buffer1.find(num) != std::string::npos)
    {
      //1st occurrence
      if(str.empty()) str = buffer1;
      //duplicate
      else return "Error => Too many people: " + num;
    }
  }
  //if str still empty at the end of the loop => no number matched
  if(str.empty()) return "Error => Not found: " + num;

  //else
  std::stringstream ss2(str);
  std::string buffer2;
  std::string name;
  std::string address;
  while(std::getline(ss2, buffer2, ' '))
  {
    //skip if phone number phone or buffer2 is space
    if(buffer2.find_first_of('+') != std::string::npos || buffer2.size() < 2) continue;
    
    //filtered allowed characters
    std::string temp;
    for(auto c: buffer2)
    { 
      if(isdigit(c) || isalpha(c) || c == '.' || c== '-' || c == '\'')
      {
        temp.push_back(c);
      }
      else if (c == '_' && c != buffer2.front()) temp.push_back(' ');
    }
    if(buffer2.find_first_of('<') != std::string::npos || buffer2.find_first_of('>') != std::string::npos)
    {
      name += temp + ' ';
    }
    else
    {
      address += temp + ' ';
    }
  }
  //remove trailing space
  name.pop_back();
  address.pop_back();
  
  return "Phone => " + num + ", Name => " + name + ", Address => " + address;
}
