#include <iostream>
#include <algorithm>

using namespace std;

struct shoe{

    int sizeshoe;

    int frequency;

};

void readarr(int arr[], int N){

    for(int i = 0; i < N; i++){

        cin >> arr[i];

    }

}

bool sortbyfrequency(struct shoe shoe1, struct shoe shoe2){

    if(shoe1.frequency != shoe2.frequency){

        return shoe1.frequency > shoe2.frequency;

    }

    return shoe1.sizeshoe < shoe2.sizeshoe;

}

void countfrequency(int arr[], int N){

    sort(arr, arr + N);

    struct shoe shoes[N];

    int count = 1;

    int j = 0;

    for(int i = 1; i < N; i++){

        if(arr[i] == arr[i - 1]){

            count++;

        }

        if(arr[i] != arr[i - 1] || i == N - 1){

            shoes[j].sizeshoe = arr[i - 1];

            shoes[j].frequency = count;

            j++;

            count = 1;

        }

    }

    sort(shoes, shoes + j, sortbyfrequency);

    for(int i = 0; i < j; i++){

        cout << shoes[i].sizeshoe << " " << shoes[i].frequency << endl;

    }

}

int main()
{
    int N;

    cin >> N;

    int arr[N];

    readarr(arr, N);

    countfrequency(arr, N);
}
