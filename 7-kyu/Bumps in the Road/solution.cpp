#include <string> 
#include <algorithm>

std::string bumps(std::string road){
  return std::count(road.begin(), road.end(), 'n') > 15 ? "Car Dead" : "Woohoo!";
}
/*
std::string bumps(std::string road){
  int count = 0;
  for(auto c: road) 
    if(c=='n') 
      count++;
  return count > 15 ?"Car Dead" : "Woohoo!";
}
*/