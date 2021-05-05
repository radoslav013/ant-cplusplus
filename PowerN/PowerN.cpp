#include <iostream>

using namespace std;
/*
Given base and n that are both 1 or more,
compute recursively (no loops) the value of base to the n power,
so powerN(3, 2) is 9 (3 squared).

powerN(3, 1) → 3
powerN(3, 2) → 9
powerN(3, 3) → 27
*/

int powerN(int num, int power){
    if(power == 1) {
        return num;
    }
    return num * powerN(num, power-1); // 3 * 3 = 9
}

int main()
{
    cout << powerN(5, 3) << endl;

    return 0;
}
