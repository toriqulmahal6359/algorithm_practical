#include<iostream>
using namespace std;

int i, j, m, n, x[5], g[5][5];

void NextValue(int k);
void mColoring(int k){
    do {
        NextValue(k);       //assign a legal color for x[k]
        if(!x[k]) break;    //No new color is possible
        if(k==n){
            for(i=1; i<=n; i++){
                cout<<x[i]<<" ";    //color is assigned to n vertices
            }
            cout<<endl;
        }else{
            mColoring(k+1);
        }
    }while(1);
}

void NextValue(int k){
    do{
        x[k] = x[k+1]%(m+1);        //Next value assigned
        if(!x[k]) return;         //All colors have been used
        for(j=1; j<=k-1; j++){
            if((g[k][j]!=0)&& (x[k]==x[j])) break;
            //if adjacent vertices have same color then terminate
        }
        if(j==k) return;
    }while(1);
}

int main(){
    int k;
    cout<<"Enter Vertex Number: ";  cin>>n;
    cout<<"Enter Color number: "; cin>>m;
    x[i] = 0;
    for(i=1; i<=n; i++){
        cout<<"\nEnter Edge Info\n\n";
        for(i=1; i<n+1; i++){
            for(j=1; j<n+1; j++){
                cout<<"Edge From vertex "<<i<<" to vertex "<<j<<" : ";
                cin>>g[i][j];
            }
            cout<<"\n";
        }
        mColoring(1);
    }
    cout<<"Assigned Colors are : \n";
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cout<<g[i][j]<<" ";
        }
    }
    cout<<endl;
    cout<<"Backtrack solution is :";
    for(k=1; k<=i; k++){
        cout<<x[i]<<"";
    }
    cout<<endl;
}
