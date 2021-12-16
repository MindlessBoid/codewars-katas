#include <vector>
#include <numeric>

/* using numeric
char add_letters(std::vector<char> letters) {
  int sum = std::accumulate(letters.begin(), letters.end(), 0, 
                            [](uint8_t c1, uint8_t c2)
                            {
                              return c1 + c2 - 'a' + 1;
                            });
  return letters.empty() ? 'z' : (sum%26 == 0 ? 26 : sum%26) + 'a' - 1;
}
*/

#include <vector>
char add_letters(std::vector<char> letters) {
  int sum = 0;
  for(auto c: letters)
    sum += c - 'a' + 1;
  sum%=26;
  return (sum==0 ? 26 : sum) + 'a' - 1;
}