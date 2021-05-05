#include <iostream>

using namespace std;

const int N = 6;
void readArray(int masiv[]) {
    cout << "Enter your numbers: ";
    for(int i = 0; i < N; i++) {
        cin >> masiv[i];
    }
}

/*
arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4]
// and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4]
// and place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4]
// and place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4]
// and place it at beginning of arr[3...4]
11 12 22 25 64

original 90 100 110 40 50
step0
    min: 90
    for...
    min: 40
    result: 40 100 110 90 50
step1
    min: 100
    for...
    min: 50
    result: 40 50 110 90 100
*/

void selectionSort(int masiv[]) {
    int temp;
    for(int i = 0; i < N-1; i++) {
        int min = masiv[i];
        for(int j = i; j < N; j++){
            if(masiv[j] < min){
                min = masiv[j];
                temp = masiv[i];
                masiv[i] = min;
                masiv[j] = temp;
            }
        }
    }
}

void printArray(int masiv[]) {
    for(int i = 0; i < N; i++) {
        cout << masiv[i] << " ";
    }
    cout << endl;
}

int main()
{

    int masiv[N];
    readArray(masiv);
    selectionSort(masiv);
    printArray(masiv);
    return 0;
}
