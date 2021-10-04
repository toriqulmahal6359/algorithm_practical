#include<stdio.h>
#include<iostream>
using namespace std;
#define INF 25000
#define R 50

/*********************** Function Prototypes ****************************/
int total, n, t[R][3], cost[R][R];

int input();
void display(int mincost);
int Prim();

/************************ Main Function *********************************/
int main()
{
    int q, mincost;
    do {
        cout<<"1.Input Data"<<endl;
        cout<<"2.Evaluate minimum cost Spanning Tree"<<endl;
        cout<<"3.Quit"<<endl;
        cout<<"Enter Choice"<<endl;
        cin>>q;

        if(q==1) n= input();
        else if(q==2) {
            mincost= Prim();
            display(mincost);
        }
    }while(q != 3);
}

/*************************** Output *************************************/
void display(int mincost)
{
    int i, total;
    cout<<"\n Prim's Minimum-Cost Spanning Tree is "<<mincost<<endl;
    cout<<"The Spanning Tree is : "<<endl;
    for(i = 1; i<=total; i++){
        cout<<t[i][1]<<" -> "<<t[i][2]<<endl;
    }
    cout<<endl;
}

/********************************** Data Input ****************************/
int input()
{
    int V, x, y, kost;
    cout<<"Enter number of Vertices :"<<endl;
    cin>>V;
    for(x=0; x<=V; x++){
        for(y=0; y<=V; y++){
            cost[x][y] = INF;                    //Set all vertices Infinity
            cost[y][x] = INF;
        }
    }

    do{
        cout<<"Enter edge(-1, -1 to quit): "<<endl;
        cin>>x>>y;
        if(x == -1 || y == -1) break;
        cout<<"Enter Cost: ";
        cin>>kost;
        cost[x][y] = kost;
        cost[y][x] = kost;
    }while(1);

    return V;
}
/************************ Prim' Spanning Tree ********************************/
int Prim(){
    int i, j, k, l, mincost, near[R];
    k=l=1; total= 0;
    for(i= 1; i<= n; i++){                  //Find cost of edges for per iteration
        for(j= 1; j<= n; j++){
            if(cost[i][j] < cost[k][l]){
                k= i, l=j;
            }
        }
    }
    mincost = cost[k][l];
    t[1][1] = k; t[1][2]= l; total++;
    for(i= 2; i<=n; i++){               //Find additional n-2 edges for t
        if(cost[i][n] < cost[i][k]){
            near[i] = l;
        }else{
            near[i] = k;
        }
    }
    near[l] = near[k] = 0;

    for(i= 2; i<= n; i++){               //Find near edges of l or k then set for another vertex
        l = INF;
        for(k=1; k<=n; k++){
            if(cost[k][near[k]] < l){
                l = cost[k][near[k]];
                j = k;
            }
        }
        t[i][1] = near[j]; t[i][2]= j;
        total++;
        mincost = mincost + cost[j][near[j]];
        near[j] = 0;

        //Update near[]
        for(k= 1; k<=n; k++){
            if(near[k]!= 0 && cost[k][near[k]]> cost[k][j]){
                near[k] = j;
            }
        }
    }
    return mincost;
}
