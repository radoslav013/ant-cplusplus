#include <iostream>
#include <vector>

using namespace std;
// vector with elements
// find the smallest number
// find the largest number
int main()
{
    cout << "How many numbers you want to enter: ";
    int n;
    cin >> n;

    vector<int> vect;
    int min = 0, max = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        vect.push_back(temp);

        if(i == 0){
            min = vect[i];
            max = vect[i];
        } else {
            if(vect[i] > max) {
                max = vect[i];
            } else if(vect[i] < min) {
                min = vect[i];
            }
        }
    }
    cout << "This is the smallest number: " << min << endl;
    cout << "This is the largest number: " << max << endl;
    return 0;
}
