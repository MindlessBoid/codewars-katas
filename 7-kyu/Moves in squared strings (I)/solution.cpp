#include <string>
#include <sstream>
class Opstrings
{
public:
    static std::string vertMirror(const std::string &str);
    static std::string horMirror(const std::string &str);
    // your high order function oper
    template<typename Func>
    static std::string oper(Func func, const std::string &str);
};
std::string Opstrings::vertMirror(const std::string& str)
{
  std::stringstream ss(str);
  std::string result;
  std::string temp;
  while(std::getline(ss, temp))
  {
    result += std::string(temp.rbegin(), temp.rend()) + (ss.eof() ? "" : "\n");
  }
  return result;
}

std::string Opstrings::horMirror(const std::string& str)
{
  std::stringstream ss(str);
  std::string result;
  std::string temp;
  while(std::getline(ss, temp))
  {
    result = (ss.eof() ? "" : "\n") + std::string(temp.begin(), temp.end())  + result;
  }
  return result;
}
template <typename Func>
std::string Opstrings::oper(Func func, const std::string& str)
{
  return func(str);
}