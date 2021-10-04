#include<iostream>
using namespace std;

void maxmin(int a[], int i, int j, int &min, int &max){
    if(i == j){
        max=min=a[i];
    }else if(i == j - 1){
        if(a[i] > a[j]){
            max = a[i]; min = a[j];
        }else{
            max = a[j]; min = a[i];
        }
    }else{
        int mid = (i + j)/2;
        maxmin(a, i, mid, min, max);
        int min1 = min; int max1 = max;
        maxmin(a, mid+1, j, min, max);
        if(max1 > max) max = max1;
        if(min1 < min) min = min1;

        return;
    }
}

int main(){
    int min, max;
    int a[100];
    int num, i;

    cout<<"Enter total number of numbers : "<<endl;
    cin>>num;
    cout<<"Enter the numbers: "<<endl;
    for(i= 0; i<num; i++){
        cin>>a[i];
    }
    max= a[0]; min= a[0];
    maxmin(a, 0, num-1, min, max);
    cout<<"Maximum element in an array : "<<max<<endl;
    cout<<"Minimum element in an array : "<<min<<endl;

    return 0;
}
