#include <string>

std::string alphabetWar(std::string fight)
{ 
  // Empty case
  if(fight.empty()) return "No one wins";

  int score = 0;
  std::string letters ="sbpw""zdqm"; // can use std::map
  for(size_t i = 0; i < fight.length(); i++)
  {
    size_t pos = letters.find_first_of(fight[i]);
    if(pos != std::string::npos)
    {
      // Check left and side neighbors
      bool left = (i > 0) ? isalpha(fight[i - 1]) : true;
      bool right = (i < fight.length() - 1) ? isalpha(fight[i + 1]) : false;
      // Calculate score, if < 4 -> left side, esle right side
      if(left && right) score += (pos < 4 ? 1 : -1) * (pos%4 + 1);
    }
  }
  
  return score > 0 ? "Left side wins!"
        :score < 0 ? "Right side wins!"
        :"Let's fight again!";
}