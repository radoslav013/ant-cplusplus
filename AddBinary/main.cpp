#include <iostream>
#include <string>

using namespace std;

string addSimpleBinary(int sum) {
    switch(sum) {
        case 0: return "00";
        case 1: return "01";
        case 2: return "10";
        case 3: return "11";
    }
    return "";
}

int charToInt(char a) {
    return a - '0';
}

string addBinary(string a, string b) {
    if(a.length() > b.length()) {
        b.insert(0, a.length() - b.length(), '0');
    } else {
        a.insert(0, b.length() - a.length(), '0');
    }
    string sum = "";
    char carry = '0'; // edno na um // 0
    for(int i = a.length() - 1; i >= 0; i--) {
        string result =
        addSimpleBinary(charToInt(carry) +
                        charToInt(a[i]) +
                        charToInt(b[i]));
        sum.insert(0, 1, result[1]); // 01
        carry = result[0];
    }
    if(carry == '1') {
        sum.insert(0, 1, carry);
    }

    return sum;
}

int main()
{
    cout << addBinary("1010", "1011") << endl;
    return 0;
}
