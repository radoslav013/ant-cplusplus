#include <iostream>

using namespace std;

int countBlocks(int rows){
    if(rows == 1) {
        return 1;
    }
    return rows + countBlocks(rows-1);

}

int main()
{
    // We know that on line 2 there are 2 blocks etc
    cout << countBlocks(5);
    return 0;
}
