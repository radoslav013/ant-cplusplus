#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Counter {
    int index; // what is the last index on which it was found
    int total; // how many times this letter is found in the map
};

int main()
{
    string input = "total";
    map<char, Counter> counter;

    for(int i = 0; i < input.length(); i++) {
        if(counter.find(input[i]) != counter.end()){
            int currValue = counter[input[i]].total;
            counter.erase(input[i]);
            counter.insert(pair<char, Counter>(input[i], {i, currValue+1}));
        } else {
            counter.insert(pair<char, Counter>(input[i], {i, 1}));
        }
    }

    int minIndex = input.length()-1;
    char firstNotRepeating = input[minIndex];

    map<char, Counter>::iterator itr;
    for (itr = counter.begin(); itr != counter.end(); ++itr) {
        cout << itr->first
             << ": " << itr->second.total << ", " << itr->second.index
            << endl;
        if(itr->second.total == 1 && itr->second.index < minIndex) {
            firstNotRepeating = itr->first;
        }

    }
    cout << firstNotRepeating << endl;
    /*
    't': 2
    'o': 1
    'a': 1
    'l': 1
    */

    /*
    0: 5
    1: 2
    3: 5
    4: 7
    5: 10
    */


    return 0;
}
