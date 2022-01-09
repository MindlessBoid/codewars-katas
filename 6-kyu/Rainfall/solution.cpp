#include <string>
#include <numeric>
#include <sstream>
#include <vector>

class Rainfall
{
public:
    static double mean(std::string town, const std::string &data);
    static double variance(std::string town, const std::string &data);
    static std::vector<double> getTownData(std::string town, const std::string& data);
  
};
std::vector<double>  Rainfall::getTownData(std::string town, const std::string& data)
{
  /*Get a town's rainfall data*/
  // Parse 
  std::stringstream ss1(data);
  std::string townData;
  while(std::getline(ss1, townData))
  {
    //if town is found break
    if(townData.substr(0, townData.find_first_of(':')) == town) break;
  }

  // Convert the string into vector
  std::vector<double> result;
  //if town is found parse that string if not return empty
  if(townData.substr(0, townData.find_first_of(':')) == town)
  {
    std::stringstream ss2(townData.substr(townData.find_first_of(':') + 1));
    std::string buff;
    while(std::getline(ss2, buff, ','))
    {
      result.push_back(std::stod(buff.substr(buff.find_first_of(' '))));
    }
  }
  return result;
}

double Rainfall::mean(std::string town, const std::string& data)
{
  auto townData = getTownData(town, data);
  if(townData.empty()) return -1;
  double mean = std::accumulate(townData.begin(), townData.end(), 0.0) / 12;
  return mean;
}

double Rainfall::variance(std::string town, const std::string& data)
{
  auto townData = getTownData(town, data);
  if(townData.empty()) return -1;
  double mean = std::accumulate(townData.begin(), townData.end(), 0.0) / 12;
  return std::accumulate(townData.begin(), townData.end(), 0.0 , [=](double init, double val){return init + (val - mean) * (val - mean);}) / 12;
}