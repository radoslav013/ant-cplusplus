#include <iostream>

using namespace std;

void read(int *start, int *end){
    for(int *i = start; i != end; i++){
        cin >> *i;
    }
}

void print(int *start, int *end){
    for(int *i = start; i != end; i++){
        cout << *i;
    }
}

void findNotDesc(int *start, int *end,
                 int **startresult, int **endresult) {
    int maxlength = 0, length = 0;
    for(int *i = start; i != end; i++){
        length++;
        if(*i > *(i+1)){
            if(length > maxlength) {
                maxlength = length;
                *startresult = i - length+1;
                *endresult = i;
            }
            length = 0;
        }
    }
    if(length > maxlength) {
        maxlength = length;
        *startresult = end - length;
        *endresult = end-1;
    }
}

int main(){
    const int N = 10;
    int a[N] = {1, 2, 3, 5, 5, 10, 20, 30, 40, 50};
    int *aend = a + N;

    //read(a, aend);
    //print(a, aend);

    int *startresult;// a == &a[0]
    int *endresult;
    findNotDesc(a, aend, &startresult, &endresult);
    cout << *startresult << " " << *endresult << endl;

    return 0;
}
