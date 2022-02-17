
#include <string>



bool valid_spacing(const std::string& s) {
    /*
    if string is empty true 
    back and front must not be spaces
    and find the two contiguous spaces (invalid space)
    */
    return s.empty() || (s.front() != ' ' && s.back() != ' ' && s.find("  ")==std::string::npos);
}
/*
bool valid_spacing(const std::string& s) {
  if(s.empty()) return true;
  if(s.front() == ' ' || s.back() == ' ') return false;
  for(size_t i = 1; i < s.length() - 1; i++)
  {
    if((s[i] == ' ' && s[i-1] == ' ') || (s[i] == ' ' && s[i+1] == ' ') ) return false;
  }
  return true;
}
*/