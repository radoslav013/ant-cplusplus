#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> vect){
    for(int i=0; i<vect.size(); i++){
        cout<<vect.at(i)<<" ";
    }
    cout<<endl;
}
/*
number = 5
1 1 2 1 2 3 1 2 3 4 1 2 3 4 5
*/
void seriesUp(vector<int> vect, int number){
    for(int i=1; i<=number; i++){
        for(int j=1;j<=i; j++){
            vect.push_back(j);
        }
    }
    printVector(vect);
}

int main()
{
    vector<int> vect;
    int number=10;
    seriesUp(vect,number);

    return 0;
}
