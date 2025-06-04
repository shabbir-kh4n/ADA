#include <stdio.h>
#define max 100

void main(){
    int cost[max][max], min,u,v;
    int visited[max],ne=1,n,src,min_cost=0;

    printf("Enter the no. of nodes");
    scanf("%d",&n);
    printf("Enter Cost matrix\n");
    for(int i=1;i<=n;i++){
        visited[i] = 0;
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Enter Source: ");
    scanf("%d",&src);
    visited[src] = 1;

    while(ne<n){
        min = 999;
        for(int i =1;i<=n;i++){
            if(visited[i]==1){
                for(int j=1;j<=n;j++){
                    if(cost[i][j]<min && visited[j] == 0){
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(visited[v]==0){
            printf("edge %d: (%d->%d) = %d\n",ne++,u,v,min);
            min_cost += min;
            visited[v] = 1;
        }

        cost[u][v] = cost[v][u] = 999;
    }
    printf("MST: %d",min_cost);
}