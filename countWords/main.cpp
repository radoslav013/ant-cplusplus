#include <iostream>

using namespace std;

void ReadArray(char *arr, int size){
    int i = 0;
    for(int i = 0; i < size; i++) {
        cin >> noskipws >> *(arr + i);
    }
}

void findWords(char *arr, int size, int *br){
    for(int i=0;i<size;i++){
        if(*(arr+i)==' '){
            *br += 1;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    char arr[n];
    ReadArray(arr,n);
    int br=1;
    findWords(arr, n, &br);
    cout<<"Broya na dumite e: "<<br;
    return 0;
}
