#include <iostream>

using namespace std;

/*
* Task: Enter two numbers a and b, which will decide the range.
* Find all even numbers in this range and store them in array.
* Print the array
*/

void printArray(int arr[], int N) {
    for(int i = 0; i < N; i++){
        cout << arr[i] << endl;
    }
} // wanted result: 10, 12, 14, 16...

int main()
{
    int a, b;
    cout << "Enter a: "; // 25
    cin >> a;

    cout << "Enter b: "; // 46
    cin >> b;

    const int N = (b - a)/2 + 1; // 21/2 = 10+1 = 11

    if(a >= b) {
        cout << "Error in data!!!" << endl;
    } else {
        int evenNumbers[N];

        int i = 0;
        if(a % 2 != 0){
            a++;
        }
        while(a <= b) {
            evenNumbers[i] = a;
            i++;
            a+=2;
        }

        printArray(evenNumbers, N);
    }

    return 0;
}
