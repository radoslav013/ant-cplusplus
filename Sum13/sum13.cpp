#include <iostream>

using namespace std;

int sum13(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == 13){
            i += 1;
        } else {
            sum += arr[i];
        }
    }
    return sum;
}

int main()
{
    int arr[] = {1, 5, 6, 13, 30, 15};
    cout << sum13(arr, sizeof(arr)/sizeof(arr[0])) << endl;

    return 0;
}
