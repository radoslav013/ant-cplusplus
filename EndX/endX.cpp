#include <iostream>
#include <string>

using namespace std;

string endX(string text) {
    if(text.length() == 0){
        return text;
    }
    if(text[0] == 'x') {
        return endX(text.substr(1)) + 'x';
    }
    return text[0] + endX(text.substr(1));
}

int main()
{
    cout << endX("xexhixnd");
    // step1: exxndx
    // step2: endxxx
    return 0;
}
