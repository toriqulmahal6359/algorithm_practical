#include<stdio.h>
#include<conio.h>
#define max 10

int count, m = 30, x[max];
int w[] = {5,10,12,13,15,18};

void SumOfSub(int s, int k, int r){
    int i;
    //Generate Left child
    x[i] = 1;
    if(s+w[k] == m)
    {
        printf("\nSolution = %d", ++count);
        for(i= 0; i<=k; i++){
            if(x[i] == 1){
                printf("%d", w[i]);
            }
        }
    }else if(s+w[k]+w[k+1] <= m){
        SumOfSub(s+w[k], k+1, r-w[k]);
    }

    //Generate Right child
    if((s+r-w[k] >= m) && (s+w[k+1]<=m)){
        x[k] = 0;
        SumOfSub(s, k+1, r-w[k]);
    }
}

int main(){
    int s=0, i, n;
    n = 5;
    for(i=0; i<n; i++)
        s += w[i];
    if(s < m){
        printf("\nThere is no Solution\n");
    }else{
        printf("\nThe Solution Exists\n");
    }
    count = 0;
    SumOfSub(0,0,s);
    return 0;
}
