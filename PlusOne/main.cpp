#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {

    if(digits[digits.size()-1] != 9) {
        digits[digits.size()-1]++;
    } else {
        int i = digits.size()-1;
        while(i >= 0){
            if(digits[i] != 9) {
                digits[i]++;
                break;
            } else {
                digits[i] = 0;
            }
            i--;
        }
    }

    if(digits[0] == 0) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

// 1909
// 1910

int main()
{
    vector<int> digits = {9};
    plusOne(digits);
    for(int i = 0; i < digits.size(); i++) {
        cout << digits[i] << endl;
    }

    return 0;
}
