#include <iostream>
#include <string>

using namespace std;

void changeTextByReference(string& text){
    text = "Bye!";
}

string changeTextByValue(string text){
    text = "Bye!";
    return text;
}

int main()
{
    string text = "Hello";
    changeTextByReference(text);
    cout << text << endl;

    string text2 = "Hello";
    text2 = changeTextByValue(text);
    cout << text2 << endl;
    return 0;
}
