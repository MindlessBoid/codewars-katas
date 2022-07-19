#include <string>

bool is_merge(const std::string& s, const std::string& part1,
              const std::string& part2) 
{
    if (s.length() != (part1.length()+part2.length()))
    {
        return false;
    }
    
    // base condition
    if(s.empty())
    {
        return true;
    }
   
    //The fact that all of the strings are in order
    //Therefore, either 1st char of part1 or part2 must be the 1st char of s
    //We simply check the 1st char, if True, we slice the strings and so on
    if(!part1.empty() && s.front()==part1.front() && is_merge(s.substr(1), part1.substr(1), part2))
    {
        return true;
    }
    if(!part2.empty() && s.front()==part2.front() && is_merge(s.substr(1), part1, part2.substr(1)))
    {
        return true;
    }
    return false;
}