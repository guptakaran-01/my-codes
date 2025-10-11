#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubblesort(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubblesort(arr, n - 1);
}

void selectionsort(int * arr , int n){
    
    
    for (int i = 0; i < n-1; i++)
    {
        int  indexofmin=i;
        for(int j=i+1 ; j<n ; j++){
            if(arr[j]<arr[indexofmin]){
                indexofmin=j;
            }
        }
        swap(arr[i],arr[indexofmin]);
    }
    
}




int main()
{
    int arr[] = {12, 3, 5, 13, 14, 10};
    int size = sizeof(arr) / sizeof(int);
    print(arr, size);
    // bubblesort(arr, size);
    selectionsort(arr, size);


    print(arr, size);

    return 0;
}
