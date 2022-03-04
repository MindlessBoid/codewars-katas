#include <string>
#include <vector>
std::string encode_rail_fence_cipher(const std::string &str, int n) {
  std::vector<std::vector<char>> v(n, std::vector<char>(str.length(), '\n'));
  int i = 0;
  bool isMovingUp = false;
  for(size_t j = 0; j < str.length(); j++)
  {
    // List the characters in diagonal manner from 0 to n then go up from n to 0
    v[i][j] = str[j];
    //update i
    i += isMovingUp ? -1 : 1;
    //check the direction
    if(i == 0 || i == n-1) isMovingUp = !isMovingUp;
  }

  // Exctract 
  std::string encode;
  for(auto i: v)
  {
    for(auto j: i)
    {
      if(j != '\n') encode.push_back(j);
    }
  }

  return encode;
}


std::string decode_rail_fence_cipher(const std::string &str, int n) {
  std::vector<std::vector<char>> v(n, std::vector<char>(str.length(), '\n'));
  auto it = str.begin();
  // Same thing as encode, just do it n more times
  // Fill in the 1st row where collum index == i
  // then 2nd ....
  for(int j = 0; j < n; j++)
  {
      int i = 0;
      bool isMovingUp = false;
     for(size_t k = 0; k < str.length(); k++)
     {
        if(i == j) v[i][k] = *it++;
        //update i
        i += isMovingUp ? -1 : 1;
        //check the direction
        if(i == 0 || i == n-1) isMovingUp = !isMovingUp;
     }
  }
  // Extract, just need to read collumn-wise
  std::string decode;
  for(size_t i = 0; i < str.length(); i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(v[j][i] != '\n') decode.push_back(v[j][i]);
    }
  }
  return decode;
}