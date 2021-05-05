#include <iostream>
#include<algorithm>

using namespace std;

void print_remove_duplicates(int arr[],int size){
    int i=0;
    while(i<size){
        cout<<arr[i]<<" ";
        i++;
    }

}

void remove_duplicates(int arr[], int size){
    int arr2[size];
    int i=0;
    int j=0;
    while(i<size){
        arr2[j]=arr[i];
        j++;
        while(arr[i]==arr[i+1]){
            i++;
        }
        i++;
    }
    print_remove_duplicates(arr2,j);
}

void sort_array(int arr[], int n){
    // sort the array
    for(int i = 1; i < n; i++){
        int current = arr[i];
        int lastIndex = i-1;
        while(lastIndex >= 0 && current < arr[lastIndex]) {
            arr[lastIndex+1] = arr[lastIndex];
            arr[lastIndex] = current;
            lastIndex--;
        }
    }
}

int main()
{
    int arr[]={1,2,2,2,3,4,4,5,7,7,7,7,7,8,8,12,13,13,13,6,6,4,4,2,2,1,14,15,15,16,16};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort_array(arr,n);
    remove_duplicates(arr,n);
    return 0;
}
