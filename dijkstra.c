#include <stdio.h>
#define inf 999

void dj(int cost[10][10],int n,int src){
    int i,j,min,u,v,d[n],visited[n];
    for(i = 1;i<=n;i++){
        d[i] = inf;
        visited[i] = 0;
    }
    d[src] = 0;

    for(i = 1;i<=n;i++){
        min = inf;
        for(j = 1;j<=n;j++){
            if(d[j] < min && visited[j] == 0){
                min = d[j];
                u = j;
            }
        }
        visited[u] = 1;

        for(v=1;v<=n;v++){
            if(d[u] + cost[u][v] < d[v]){
                d[v] = d[u] + cost[u][v];
            }
        }
    }
    int ne = 1;
    for(i=1;i<=n;i++){
        if(d[i]!=0 && d[i]!= 999){
            printf("Edge %d: (%d->%d) = %d\n",ne++,src,i,d[i]);
        }
    }
}

void main(){
    int cost[10][10]; 
    int n,src;

    printf("Enter the no. of nodes");
    scanf("%d",&n);
    printf("Enter Cost matrix\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    printf("Enter Source: ");
    scanf("%d",&src);
    dj(cost,n,src);

}
