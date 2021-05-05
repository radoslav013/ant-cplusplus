#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int N = 5;
    vector<int> vect;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        vect.push_back(temp);
    }

    vector<int> result;
    for(int i = 0; vect.size(); i++) {
        int count = 0;
        for(int j = 0; j < result.size(); j++) {
            if(vect.at(i) == result.at(j)){
                count++;
            }
        }
        if(count == 0)
            result.push_back(vect.at(i));
    }

    for(int i = 0; i < result.size(); i++) {
        cout << result.at(i) << endl;
    }
    return 0;
}
