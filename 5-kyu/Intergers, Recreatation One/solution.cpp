#include <utility>
#include <vector>
#include <cmath>
class SumSquaredDivisors
{
public:
    static std::vector<std::pair<long long, long long>> listSquared(long long m, long long n)
    {
        std::vector<std::pair<long long, long long>> result;
        for(long long i = m; i <= n; i++)
        {
            long long sum = 0;
            //find all divisors of i, just need to check from 1 to sqrt(i);
            for(long long j = 1; j*j <= i; j++)
            {
                if(i%j == 0) sum += (j*j == i) ? j*j : j*j + (i/j)*(i/j);
            }
            long long sqrt_sum = sqrt(sum);

            if(sqrt_sum*sqrt_sum == sum) result.push_back(std::make_pair(i, sum));
        }
        return result;
    }
};