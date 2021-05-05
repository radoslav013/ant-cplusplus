#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Find all words in a text with length more than k or equal to k
int main()
{
    int k = 5;
    string str = "Today is Saturday and we study programming.";
    stringstream ss(str);

    string word;
    while(ss >> word){
        if(word.length() >= k){
            cout << word << endl;
        }
    }
    return 0;
}
