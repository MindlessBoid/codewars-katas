#include<vector>
#include <algorithm>
#include <map>
#include <string>

/* Recursive solution: KNAPBACK algo
  //2 choices: either to include or exclue the current coin
unsigned long long count(int money, const std::vector<unsigned int>& coins, int coinIndex, std::map<std::string, unsigned long long>& table)
{
  if(money == 0) return 1;
  if(money < 0 || coinIndex < 0) return 0;

  std::string key = std::to_string(money) + '|' + std::to_string(coinIndex);
  if(table.find(key) == table.end())
  {
    auto include = count(money - coins[coinIndex], coins, coinIndex, table);
    auto exclude = count(money, coins, coinIndex - 1, table);
    table[key] = include + exclude;
  }
  return table[key]; 
}

unsigned long long countChange(int money, 
                                const std::vector<unsigned int>& coins) 
{
  std::map<std::string, unsigned long long> table;
  return count(money, coins, coins.size() - 1, table);
}
*/


// Dynamic programming solution
unsigned long long countChange(int money, 
                              const std::vector<unsigned int>& coins) 
{
  /*Source: https://www.geeksforgeeks.org/understanding-the-coin-change-problem-with-dynamic-programming/
    ***************Example coins = {5, 2, 3}
    ***************Sum N = 10,.etc 5 + 5 = 10
    *U want an array to store the previous solutions so ways[N+1], this case ways[11] = {0}
    *Each index represents a sum, 
    the value at that index represent number of ways u can combine the coins
    *Initialize ways[0] = 1 because there is one way to make sum = 0, using 0 coin
    or if u go from top-down everytime the sum reaches 0 u count -> sum = 0 is BASE CASE -> 1
    *Loop through coins 
      *and loop thru the ways 
        if coin value <= index of ways: 
            ways[i] += ways[i - curr_coin]
      
      + Example: coin = 5 
        ways = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        i  :   {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}   (can be viewed as sums)
        - with 5 coin u cant make the sum of 0, 1, 2, 3, 4 -> ways[0->4] = same
        - at i = 5: ways[5] += ways[5 - 5] = ways[0] = 1 -> there is one way to make sum of 5 with a 5 coin
        - at i = 6: ways[6] += ways[6 - 5] = ways[1] = 0 
        ....
        ways = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}
        so i - curr_coin is the curr_sum - curr_coin = prev_sum
        using this prev_sum as index we can find out its value or number of ways and add to the current ways
  */
  //money + 1 because u want the last index = money or the desired sum
  std::vector<unsigned long long> ways(money + 1, 0);
  ways[0] = 1;
  for(auto coin: coins)
  {
    for(size_t i = 0; i < ways.size(); i++)
    {
      if(coin <= i) ways[i] += ways[i - coin];
    }
  }
  return ways[money];
}