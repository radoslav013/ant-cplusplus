#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> romanNumbers {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000}
};

int romanToInt(string s) {
    int result = 0;
    int previous = romanNumbers[s[0]]; // 1
    int current = 0;
    for(int i = 0; i < s.length(); i++){
        current = romanNumbers[s[i]]; // 5
        if(previous < current) {
            result += current - 2*previous; // result = 4, 5 - 2*1
        } else {
            result += current; // result = 1
        }
        previous = current; // previous = 1
    }
    return result;
}

int romanToInt2(string s) {
    int n = s.length() - 1;
    int result = romanNumbers[s[n]]; // 5
    for(int i = n-1; i >= 0; i--) {
        if(romanNumbers[s[i]] >= romanNumbers[s[i+1]]) {
            result += romanNumbers[s[i]];
        } else {
            result -= romanNumbers[s[i]];
        }
    }
    return result;
}

int main()
{
    string s = "IV";
    cout << romanToInt2(s) << endl;
    return 0;
}
