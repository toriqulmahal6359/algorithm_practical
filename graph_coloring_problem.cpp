#include<iostream>
using namespace std;

int i, j, m, n, x[10], g[10][10];

int NextValue(int k);
int mColoring(int k){
    do{
        NextValue(k);
        if(x[k] != 0) break;
        if(k==n){
            for(i=1; i<=n; i++){
                cout<<x[i]<<" ";
            }
            cout<<endl;
        }else{
            mColoring(k+1);
        }
    }while(k==1);
}
int NextValue(int k){

    do{
        x[k] = x[k+1]%(m+1);
        if(x[k]!=0){
            for(j=1; j<k; j++){
                if((g[j][k]!=0)&&(x[j]==x[k])){
                    break;
                }
            }
        }
        if(j==k)
            return 1;
        else
            return 0;

    }while(k==1);
}

int main(){
    cout<<"No. of Colors available : "; cin>>m;
    cout<<"No. of regions : "; cin>>n;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cout<<"g"<<"["<<i<<"]"<<"["<<j<<"]"<<" = ";
            cin>>g[i][j];
        }
    }
    mColoring(1);
}
