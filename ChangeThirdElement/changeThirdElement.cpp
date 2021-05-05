#include <iostream>

using namespace std;

void changeThirdElement(int arr[]){
    arr[2] = 150;
}

int main()
{
    int arr[5] = {10, 30, 50, 20, 90};
    changeThirdElement(arr);
    cout << arr[2] << endl;
    return 0;
}
