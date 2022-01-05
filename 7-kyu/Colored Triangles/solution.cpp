#include <string>

/* Recursion, bad sol
const std::string C_COLORS = "RGB";
void getNextColours(std::string last, std::string& result)
{
  for(size_t i = 1; i < last.length(); i++)
  {
    for(auto color : C_COLORS)
    {
      if((last[i] == last[i-1] && last[i] == color) 
      || (last[i] != last[i-1] && last[i] != color && last[i-1] != color))
      {
        last[i-1] = color;
        break;
      }
    }
  }
  if(last.length() > 1) getNextColours(last.substr(0, last.length() - 1), result);
  else result = last;;
}
std::string triangle(std::string row_str) {
  std::string result;
  getNextColours(row_str, result); 
  return result;
}
*/

std::string triangle(std::string row_str) {
  while(row_str.length() > 1)
  {
    for(size_t i = 1; i < row_str.length(); i++)
    {
      //only need to update row_str[i-1] if diff
      if(row_str[i - 1] != row_str[i])
      {
        row_str[i - 1] = 'B' + 'G' + 'R' - row_str[i] - row_str[i - 1];
      }
    }
    row_str.pop_back();
  }
  return row_str;
}