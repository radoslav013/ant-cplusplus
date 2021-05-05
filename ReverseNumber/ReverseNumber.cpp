#include <iostream>

using namespace std;
/*
* Task: Enter a number and print it reverse
Example: 1999 => 9991
         2020 => 0202

         get the lastdigit => num % 10
         remove the lastdigit => num / 10
And also check if the number is palindrome;

12321 => 12321
или => или
Batman has black clothessehtolc kcalb sah namtaB
*/
int main()
{
    int num;
    cout << "Enter num: ";
    cin >> num; // 1234

    int sum = 1;
    while(num>0){
        // Reverse the number
        int lastdigit = num % 10; // get the last digit
        sum *= lastdigit; // sum up with the last digit
        num /= 10; // remove the last digit
    }
    cout << sum << endl; // 9991
    return 0;
}
