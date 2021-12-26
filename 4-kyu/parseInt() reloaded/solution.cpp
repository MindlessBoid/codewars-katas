#include <string>
#include <map>
#include <sstream>
/*
std::string reverse(std::string str)
{
  std::stringstream ss(str);
  std::string result, temp;
  while(ss>>temp) result = (ss.eof() ? "" : " ") + temp + result;
  return result;
}
long parse_int(std::string number) {
  std::map<std::string, int> numbers = {{"zero", 0},{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, 
                                        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
                                        {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14},
                                        {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
                                        {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50}, {"sixty", 60},
                                        {"seventy", 70}, {"eighty", 80}, {"ninety", 90},
                                        };
  std::stringstream ss(reverse(number));
  std::string temp;
  long result = 0;
  long i = 1;
  while(ss >> temp)
  {
    size_t pos = temp.find_first_of('-');
    if(temp == "hundred") i *= 100; //can appear twice
    else if(temp == "thousand") i = 1000;
    else if(temp == "million") i = 1000000;
    else if (numbers.find(temp) != numbers.end() && pos == std::string::npos)
    {
      result += numbers[temp] * i;
    }
    else if(pos != std::string::npos)
    {
      result += i * (numbers[temp.substr(0, pos)] + numbers[temp.substr(pos+1)]);
    }
  }
  return result;
}
*/

long parse_int(std::string number) {  
  std::map<std::string, int> numbers = {{"zero", 0},{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, 
                                        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
                                        {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14},
                                        {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19},
                                        {"twenty", 20}, {"thirty", 30}, {"forty", 40}, {"fifty", 50}, {"sixty", 60},
                                        {"seventy", 70}, {"eighty", 80}, {"ninety", 90},
                                        };
  for(auto& c: number) 
    if(c == '-') 
      c = ' ';
  std::stringstream ss(number);
  std::string temp;
  long result = 0;
  long n = 0; //to store each hundred, reset if million or thousand
  while(ss >> temp)
  {
    if(temp == "million")
    {
      result += n*1000000;
      n = 0;
    }
    else if(temp == "thousand")
    {
      result += n*1000;
      n = 0;
    }
    else if(temp == "hundred")
    {
      n*=100;
    }
    else if(numbers.find(temp) != numbers.end())
    {
      n += numbers[temp];
    }
  }
  return result + n;
}