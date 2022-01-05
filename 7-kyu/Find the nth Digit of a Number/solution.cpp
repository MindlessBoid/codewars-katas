#include <cmath>
int findDigit(int num, int nth){
    return nth <= 0 ? -1 : abs((int)(num/pow(10, nth-1))%10);
}