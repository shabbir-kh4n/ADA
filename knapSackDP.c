#include <stdio.h>

int max(int x,int y){
    return x>y?x:y;
}
void kpdp(int wt[10], int val[10],int n,int w){
    int sol[n+1][w+1];
    int selected[n];
    for(int i=0;i<n;i++){
        selected[i] = 0;
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j == 0){
                sol[i][j] = 0;
            }

            else if(j>=wt[i]){
                sol[i][j] = max(sol[i-1][j], sol[i-1][j-wt[i]] + val[i]);
            }

            else{
                sol[i][j] = sol[i-1][j];
            }
        }
    }
    printf("Optimal sol: %d",sol[n][w]);
    int i = n;
    int j = w;
    while(i>0 && j>0){
        if(sol[i][j] != sol[i-1][j]){
            selected[i] = 1;
            j = j-wt[i];
        }
        i--;
    }
    printf("\nItem Selected: ");
    for(int i=0;i<n;i++){
        if(selected[i]!=0){
            printf("%d ",i+1);
        }
    }
}

void main(){
    int n,val[10],wt[10],w;
    printf("Enter no. of items: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the wt and value of item[%d]: ",i+1);
        scanf("%d%d",&wt[i],&val[i]);
    }
    printf("Enter the capacity of bag: ");
    scanf("%d",&w);
    kpdp(wt,val,n,w);
}