#include <iostream>

using namespace std;

int main()
{
    const int N = 2;
    int arr[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    // already inputed array
    int temp = arr[0];
    arr[0] = arr[N-1];
    arr[N-1] = temp;

    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
