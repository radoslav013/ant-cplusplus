#include <iostream>

using namespace std;

unsigned long long int fact(unsigned long long int n) {
    if(n == 0) {
        return 1;
    }
    return n*fact(n-1);
}
long calculateCombination(long n, long k) {
    unsigned long long c = fact(n) / (fact(k)*fact(n-k));
    cout << n << " " << k << " " << c << endl;
    return c;
}
long climbStairs(long n) {
    /* 10*1 + 0*2 => 1
    8*1 + 1*2 => 9
    6*1 + 2*2 => 28
    4*1 + 3*2 => 35
    2*1 + 4*2 => 15
    0*1 + 5*2 => 1 */

    long result = 0;
    long twos = n/2;
    while(twos >= 0) {
        long ones = n - twos*2;
        result += calculateCombination(ones+twos, twos);
        twos--;
    }

    return result;
}
int main()
{
    cout << climbStairs(35) << endl;
    cout << endl;
    cout << fact(26) << endl;
    // Expected: 14930352
    // Real:        56935
    return 0;
}
