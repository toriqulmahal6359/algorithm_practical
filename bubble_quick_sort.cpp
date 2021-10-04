#include<iostream>
using namespace std;
#include<stdlib.h>
#include<time.h>

void bubble_sort(int a[], int n){
    int i, j, temp;
    for(i= 0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void quick_sort(int a[], int left, int right){
    int i= left, j= right, mid;
    mid = (a[i] + a[j])/2;
    while(i <= j){
        while(a[i] <= mid){
            i++;
        }
        while(a[j] >= mid){
            j--;
        }
        if(i <= j){
            int temp;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if(left < j){
        quick_sort(a, left, j);
    }
    if(i > right){
        quick_sort(a, i, right);
    }
}

int main(){
    int i;
    int b[4500];
    clock_t sb, eb, sq, eq;
    for(i= 0; i<=4500; i++){
        b[i] = rand()%4500+1;
    }
    //For Bubble sort
    sb = clock();
    bubble_sort(b, 4500);
    eb = clock();
    cout<<"Bubble Sort - "<<difftime(eb, sb)<<"\n";

    //For Quick sort
    sq = clock();
    quick_sort(b, 1, 4500);
    eq = clock();
    cout<<"Quick Sort - "<<difftime(eq, sq);
}


