#include <iostream>
#include <vector>

using namespace std;

void changeThirdElement(vector<int>& vect){
    vect[2] = 500;
}

int main()
{
    vector<int> vect = {100, 200, 300, 400};
    changeThirdElement(vect);
    cout << vect[2] << endl;
    return 0;
}
