#include <vector>
#include <string>

class CaesarCipher
{
  public:
    static std::vector<std::string> movingShift(const std::string &s, int shift);
    static std::string demovingShift(std::vector<std::string> &s, int shift);
};

std::vector<std::string> CaesarCipher::movingShift(const std::string& s, int shift)
{
  std::vector<std::string> result(5);
  //if it cannt be divided evenly by 5, take the ceil of length/5;
  int n = s.length()/5 + (s.length()%5 == 0 ? 0 : 1);
  for(size_t i = 0; i < s.length(); i++, shift = (shift + 1)%26) //called at the end, make sure shift < 26
  {
    char c = s[i];
    if(isalpha(c))
    {
      char base = (c >= 'a') ? 'a' : 'A';
      c = ((c - base) + shift)%26 + base;
    }
    result[i/n].push_back(c);
  }

}
std::string CaesarCipher::demovingShift(std::vector<std::string> &s, int shift)
{
  std::string result;
  for(auto str: s)
  {
    for(char c: str)
    {
      if(isalpha(c))
      {
        char base = (c >= 'a') ? 'a' : 'A';
        c = ((c - base) - shift)%26;
        c += ((c < 0) ? 26 : 0) + base;
      }
      result.push_back(c);
      shift++;
    }
  }
  return result;
}

/*class CaesarCipher
{
  public:
    static std::vector<std::string> movingShift(const std::string &s, int shift);
    static std::string demovingShift(std::vector<std::string> &s, int shift);
};

std::vector<std::string> CaesarCipher::movingShift(const std::string& s, int shift)
{
  std::vector<std::string> result(5);
  //if it cannt be divided evenly by 5, take the ceil of length/5;
  int n = s.length()/5 + (s.length()%5 == 0 ? 0 : 1);
  // Decode the string
  std::string decodedStr;
  for(size_t i = 0; i < s.length(); i++)
  {
    char c = s[i];
    if(isalpha(c))
    {
      char base = (c >= 'a') ? 'a' : 'A';
      c = ((c - base) + (i + shift))%26 + base;
    }
    result[i/n].push_back(c);
  }
  for(auto i: result) std::cout<<i;
  std::cout<<'\n';
  return result;
}
std::string CaesarCipher::demovingShift(std::vector<std::string> &s, int shift)
{
  std::string result;
  int i = 0;
  for(auto str: s)
  {
    for(char c: str)
    {
      if(isalpha(c))
      {
        char base = (c >= 'a') ? 'a' : 'A';
        c = ((c - base) - (i + shift))%26;
        c += ((c < 0) ? 26 : 0) + base;
      }
      result.push_back(c);
      i++;  
    }
   
  }
  return result;
}
*/