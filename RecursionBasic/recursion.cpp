#include <iostream>

using namespace std;
/*
* n!
* 5! = 5*4*3*2*1
* 5! = 120
*/
void countToTen(int a) {
    if(a <= 10) {
        cout << a << endl;
        countToTen(a+1);
    }
}

int recursion(int a) {
    if(a != 1){
        return a*recursion(a-1);
    }
}

//Step1: a = 5; a*4!
//Step2: a = 4; a*3!
//Step3: a = 3; a*2!
//Step4: a = 2; a*1!
//Step5: a = 1;


int main() {
    cout << recursion(5) << endl;
    return 0;
}
