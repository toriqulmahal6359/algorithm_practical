#include<iostream>
using namespace std;
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

class ShortestPath{
    int n;
    int p[10][10];
    int A[10][10];
    int cost[10][10];

public:
    void get_data();
    void path_matrix();
    void allpaths();
    void display();

};

void ShortestPath::get_data(){
    int i, j, k;
    cout<<"Enter the node of cost Adjacency matrix : ";
    cin>>n;
    cout<<"Enter the Adjacency matrix : "<<endl;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin>>A[i][j];
            p[i][j] = 0;
        }
    }
    cout<<"Enter the cost Matrix is : "<<endl;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin>>cost[i][j];
        }
    }
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            p[i][j] = A[i][j];
        }
    }
}
void ShortestPath::display(){
    //cout<<"The Output of the given graph is : ";
    int i, j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cout<<p[i][j];
        }
        cout<<endl;
    }
}
void ShortestPath::path_matrix(){
    int i, j, k;
    for(k=1; k<=n; k++){
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                p[i][j] = p[i][j] || p[i][k] && p[k][j];
            }
        }
    }
}

void ShortestPath::allpaths(){
    int i, j, k;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            p[i][j] = cost[i][j];
        }
    }
    for(k=1; k<=n; k++){
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                if(p[i][j] < (p[i][k]+ p[k][j])){
                    p[i][j] = p[i][j];
                }else{
                    p[i][j] = p[i][k] + p[k][j];
                }
            }
        }
    }
}

int main(){
    ShortestPath sp;
    sp.get_data();

    sp.path_matrix();
    cout<<"Path Matrix is: \n";
    sp.display();
    getch();

    sp.allpaths();
    cout<<"All Pair Shortest Path is : \n";
    sp.display();
    getch();
}
