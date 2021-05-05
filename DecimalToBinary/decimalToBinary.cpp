#include <iostream>

using namespace std;

int d(int n){
    if(n == 0) {
        return 0;
    }
    return n%2 + (d(n/2));
}
int main()
{
    cout << d(9);
    return 0;
}
/*
int n = 9;
Step 1: 9%2 = 1 + (d(9/2)) = 11
Step 2: 4%2 = 0 + (10 * d(4/2)) = 10
Step 3: 2%2 = 0 + (10 * d(2/2)) = 10
Step 4: 1%2 = 1 + (10 * d(1/2)) = 1
Step 5: if(n==0) return 0;

int n = 7;
Step 1: 7%2 = 1 + (10 * d(7/2)) = 111
Step 2: 3%2 = 1 + (10 * d(3/2)) = 11
Step 3: 1%2 = 1 + (10 * d(1/2)) = 1
Step 5: if(n==0) return 0;

0 = 0000
1 = 0001
2 = 0010
3 = 0011
4 = 0100
5 = 0101
6 = 0110
7 = 0111
8 = 1000
9 = 1001

*/
