#include <stdio.h>

void indegree(int indeg[],int arr[10][10], int n){
    for(int j=0;j<n;j++){
        indeg[j] = 0;
        for(int i=0;i<n;i++){
            indeg[j] += arr[i][j];
        }
    }
}

void sort(int arr[10][10],int n){
    int stack[10],top = -1;
    int indeg[10], sorted[10],k=0;

    indegree(indeg,arr,n);
    for(int i=0;i<n;i++){
        if(indeg[i] == 0){
            stack[++top] = i;
        }
    }

    while(top != -1){
        int j = stack[top--];
        sorted[k++] = j;
        for(int i = 0;i<n;i++){
            if(arr[j][i] != 0){
                indeg[i]--;
                if(indeg[i]==0){
                    stack[++top] = i;
                }
            }
        }
    }

    printf("Topological sort: ");
    for(int i=0;i<k;i++){
        printf("%d\t",sorted[i]);
    }
}

void main(){
    int arr[10][10],n;
    printf("Enter no: ");
    scanf("%d",&n);
    printf("Enter:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    sort(arr,n);

}