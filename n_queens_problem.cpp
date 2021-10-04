#include<iostream>
using namespace std;
#include<stdlib.h>
#define R 50

int x[R], count;

int place(int k, int i){
    int j;
    for(j=1; j<k; j++){
        if(x[j] == i || abs(x[j]-i) == abs(j-k)){
            return 0;           //false
        }
    }
    return 1;                   //true
}

int NQueens(int k, int n){
    int i, j;
    for(i= 1; i<=n; i++){
        if(place(k, i) == 1){
            x[k] = i;
            if(k == n){
                count++;
                cout<<"Solution "<<"\n";
                cout<<"Row : Column = ";
                for(j=1; j<=n; j++){
                    cout<<j<<" : "<<x[j]<<"\t";
                }
                cout<<endl;
            }else{
                NQueens(k+1, n);
            }
        }
    }
}

int main(){
    int n;
    cout<<"************ 4- Queens problem **************\n";
    do{
        cout<<"\nEnter number of Queens (0 to Quit) :";
        cin>>n;
        count = 0;
        NQueens(1, n);
    }while(n);
}
