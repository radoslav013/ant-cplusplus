#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[10];
    vector<int> vect;
    vect.push_back(12);
    for(int i = 0; i < vect.size();i++){
        cout << vect.at(i) << endl;
        // vect.at(i); == vect[i];
    }

    cout << vect.max_size() << endl;

    vector<double> vectdb;
    vectdb.resize(5, 1.99);
    vectdb.pop_back();
    for(int i = 0; i < vectdb.size();i++){
        cout << vectdb.at(i) << endl;
        // vect.at(i); == vect[i];
    }

    vector<int> vectint;
    vectint.push_back(10);
    vectint.push_back(15);
    vectint.push_back(18);
    vectint.push_back(19);
    // 10, 15, ^, 18, 19
    vectint.insert(vectint.begin(), 12);

    for(int i = 0; i < vectint.size();i++){
        cout << vectint.at(i) << endl;
        // vect.at(i); == vect[i];
    }
    return 0;
}
