#include <stdio.h>
#define max 100


void main(){
    int cost[max][max], min,u,v,a,b;
    int parent[max],ne=1,n,min_cost=0;

    printf("Enter the no. of nodes");
    scanf("%d",&n);
    printf("Enter Cost matrix\n");
    for(int i=1;i<=n;i++){
        parent[i] = 0;
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }

    while(ne<n){
        min = 999;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cost[i][j]<min){
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while(parent[u]){
            u = parent[u];
        }
        while(parent[v]){
            v = parent[v];
        }

        if(u!=v){
            printf("Edge %d: (%d->%d) = %d\n",ne++,a,b,min);
            min_cost += min;
            parent[v] = u;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("MST: %d",min_cost);
}