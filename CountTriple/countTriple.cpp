#include <iostream>
#include <string>

using namespace std;

/*
countTriple("abcXXXabc") → 1
countTriple("xxxabyyyycd") → 3
countTriple("a") → 0
*/

int countTriples(string text) {
    int l = text.length();
    if(l < 3){
        return 0;
    }

    if(text[0] == text[1] &&
        text[0] == text[2] &&
        text[1] == text[2]) {
        return 1+countTriples(text.erase(0, 1));
    }
    return countTriples(text.erase(0, 1));
}
int main()
{
    cout << countTriples("aaa") << endl;
    return 0;
}
