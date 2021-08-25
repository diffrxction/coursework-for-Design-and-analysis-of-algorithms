//Write a program to combine two sorted arrays and display the resultant sorted array. Consider two random array from
// the user and sort them individually by employing any comparison based sort (e.g. Bubble, Insertion, Selection sort)
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void mergeArray(int arr1[], int arr2[], int arr3[], int m, int n){
    int i = 0, j = 0, k = 0;
    while (i < m && j < n){

        if (arr1[i] < arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else{
            arr3[k++] = arr2[j++];
        }
    }
    while (i < m){
        arr3[k++] = arr1[i++];
    }
    while (j < n){
        arr3[k++] = arr2[j++];
    }
}

void input(int *arr, int size){
    printf("Enter the elements of the array\n");
    for(int i = 0; i<size; i++){
        scanf("%d",&arr[i]);
    }
}

int main(){
    int m = 0,n = 0;
    printf("Enter the sizes of the two arrays : \n");
    scanf("%d %d", &m,&n);
    //Dynamic memory allocation.
    int * a1 = new int[m];
    int * a2 = new int[n];
    int * a3 = new int[m+n];

    input(a1, m);
    input(a2, n);

    insertionSort(a1, m);
    insertionSort(a2, n);
    mergeArray(a1, a2, a3, m, n);

    cout<<"Final array after merging\n";
    for(int i=0; i<(m+n); i++){
        cout<<a3[i]<<" ";
    }
    delete[] a1;
    delete[] a2;
    delete[] a3;
    return 0;
}