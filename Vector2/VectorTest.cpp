#include <iostream>
#include <vector>

using namespace std;

void test(vector<int>& arr) {
    arr[0] = 9;
}
int main()
{
    vector<int> a = { 90, 10 };
    test(a);
    cout << a[0] << " " << a[1] << endl;

    return 0;
}
