#include <iostream>

using namespace std;

void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
cout<<endl;
}
void bubble_sort( int arr[], int size){
   bool is_swapped;
    for(int j=0;j<size-1; j++){
        is_swapped=false;
        for(int i=0; i<size-j-1; i++){
            if(arr[i]>arr[i+1]){
                int s=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=s;
                is_swapped=true;
            }

        }
        if(is_swapped==false){
            break;
        }
    }
     print(arr,size);
}



int main()
{
   int arr[]={111,99,88,66,77,2,1,4,6,3,9,7,8,22,13,11,-11};
    bubble_sort(arr,sizeof(arr)/sizeof(arr[0]));


    return 0;
}
