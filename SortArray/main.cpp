#include <iostream>
#include <algorithm>

using namespace std;

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

// First even numbers in asc, then odd in desc
void twoWaySort(int arr[], int n)
{
    // Current indexes from left and right
    int l = 0, r = n - 1;

    // Count of odd numbers
    int k = 0;

    while (l < r) {
        // even numbers
        while (arr[l] % 2 == 0) {
            l++;
            k++;
        }

        // odd numbers
        while (arr[r] % 2 != 0 && l < r)
            r--;

        if (l < r)
            swap(arr[l], arr[r]);
    }

      // Sort even numbers in asc
      sort(arr, arr + k);

      // Sort odd numbers in desc
      sort(arr + k, arr + n, greater<int>());
}

int main() {
    int n = 0;
    cin >> n;

    int input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    twoWaySort(input, n);

    for (int i = 0; i < n; i++) {
        if(i != n-1) cout << input[i] << " ";
        else cout << input[i];
    }

    return 0;
}
