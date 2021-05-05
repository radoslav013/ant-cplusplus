#include <iostream>

using namespace std;

void readArray(int* p, int size) {
    if(size == 0) {
        return;
    }
    cin >> *p; // A[0]
    readArray(p+1, size-1);
}

int findMax(int* p, int size) {
    int max = *p;
    for(int i = 0; i < size; i++){
        if(*(p + i) > max) {
            max = *(p + i);
        }
    }
    return max;
}

int findMin(int* p, int size) {
    int min = *p;
    for(int i = 0; i < size; i++){
        if(*(p + i) < min) {
            min = *(p + i);
        }
    }
    return min;
}

void printArray(int* p, int size){
    for(int i = 0; i < size; i++){
        cout << *(p + i) << endl;
    }
}

int main()
{
    const int SIZE = 10;
    int A[SIZE];
    int *p = &A[0];
    readArray(p, SIZE);
    int min = findMin(p, SIZE);
    int max = findMax(p, SIZE);
    cout << "Min: " << min << ", Max: " << max << ", Diff: " << max - min << endl;
    //printArray(&A[0], SIZE);
    return 0;
}
