#include<iostream>
using namespace std;
#define INF 30000
#define R 100

int n, v, cost[R][R], dist[R];
/************************** Data Input ***********************/
void input(){
    int x, y, length;
    cout<<"Enter The number of Vertices: ";
    cin>>n;
    for(x= 0; x<=n; x++){           // elements of cost[][] is initializing by infinite
        for(y= 0; y<=n; y++){
            cost[x][y] = INF;
            cost[y][x] = 0;
        }
    }

    do{
        cout<<"Enter edge (-1,-1) to quit: "<<endl;
        cin>>x>>y;
        if(x == -1 || y == -1) break;
        cout<<"Enter cost: ";
        cin>>length;
        cost[x][y] = length;
    }while(1);

    cout<<"Enter Source: "<<endl;
    cin>>v;
}

/************************** Output **************************/
void display(){
    int i;
    cout<<"Shortest Paths from the Source"<<v<<endl;
    for(i= 1; i<=n; i++){
        cout<<i<<" : "<<dist[i]<<" ";
    }
    cout<<"\n\n";
}

/********************** Dijkstra' Shortest Path **************/
void ShortestPath(){
    int i, j, temp, u, w;
    int S[R];
    for(i=1; i<= n; i++){
        S[i] = 0;               // Initialize S[] and S[i]=false
        dist[i] = cost[v][i];
    }
    S[v]= 1;    dist[v]= 0;     //S[v]=true and set dist[v]=0
    for(i=2; i<n-1; i++){
        temp = INF; u = 1 ;
        for(j=1; j<=n; j++){
            if(S[j] == 0 && dist[j] < temp){        //let a vertex j not in S[] such that S[j]=0
                u = j;
                temp = dist[j];
            }
        }
        S[u] = 1;               //S[u]=true
        //Update distances from u to w
        for(w= 1; w<=n; w++){
            if(S[w]==0 && dist[w] > dist[u]+cost[u][w])
                dist[w] = dist[u]+cost[u][w];
        }
    }
}

/********************** Main Function ************************/
int main(){
    int q;
    do{
        cout<<"1.Input Data"<<endl;
        cout<<"2.Evaluate Single source Shortest Path"<<endl;
        cout<<"3.Quit"<<endl;
        cin>>q;

        if(q == 1) input();
        else if(q == 2){
            ShortestPath();
            display();
        }
    }while(q != 3);
}

