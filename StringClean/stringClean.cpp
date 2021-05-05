#include <iostream>
#include <string>

using namespace std;
/*
Given a string, return recursively a "cleaned" string
where adjacent chars that are the same
have been reduced to a single char. So "yyzzza" yields "yza".

stringClean("yyzzza") → "yza"
stringClean("abbbcdd") → "abcd"
stringClean("Hello") → "Helo"
*/

string stringClean(string str){
    int len = str.length();
    if(len == 0){
        return "";
    }

    char last = str[len - 1];
    int i = len - 2;
    while(str[i] == last){
        i--;
    }
    return stringClean(str.substr(0, i+1)) + last;
}

int main(){
    cout << stringClean("eHHellozzz") << endl;
    return 0;
}
