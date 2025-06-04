#include <stdio.h>

void warshall(int a[10][10],int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
}

int min(int x,int y){
    return x<y?x:y;
}

void floyd(int d[10][10],int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j] = min( d[i][j] , d[i][k] + d[k][j]);
            }
        }
    }
}

void main(){
    int n, a[10][10],d[10][10];
    printf("Enter no of nodes: ");
    scanf("%d",&n);

    // printf("Enter Adjecency Matrix: \n");
    // for(int i =0;i<n;i++){
    //     for(int j = 0;j<n;j++){
    //         scanf("%d",&a[i][j]);
    //     }
    // }
    // warshall(a,n);
    // printf("Transitive encloser\n");
    // for(int i =0;i<n;i++){
    //     for(int j = 0;j<n;j++){
    //         printf("%d\t",a[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("Enter Cost Matrix: \n");
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&d[i][j]);
        }
    }
    floyd(d,n);
    printf("All pair Shortest Path\n");
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            printf("%d\t",d[i][j]);
        }
        printf("\n");
    }


}