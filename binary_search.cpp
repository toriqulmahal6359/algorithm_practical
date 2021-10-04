#include <iostream>
using namespace std;

int BinarySearch(int arr[], int l, int h, int i){
    if(l <= h){
        int mid = (l + h)/2;
        if(arr[mid]==i){
            return mid;
        }
        if(arr[mid] < i){
            return BinarySearch(arr, mid+1, h, i);
        }else{
            return BinarySearch(arr, l, mid-1, i);
        }
    }
}

int main(){
    int l, h, i;
    int arr[] = {10, 40, 50, 75, 85, 90, 116, 125};
    int n = sizeof(arr)/sizeof(arr[0]);
    l = 0;
    h = n-1;

    cout<<"Enter The Item You want to find:";
    cout<<"\n";
    cin>>i;
    int result = BinarySearch(arr, l, h, i);
    if(result == -1){
        cout<<"Element not Found";
    }else{
        cout<<"element Found at Index: "<<result;
    }
    return 0;
}
