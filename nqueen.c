#include <stdio.h>
#include <stdlib.h>
#define max 10
int board[max],sol=0;

void display(int n){
    printf("\n\nSolution: %d\n",++sol);
    for(int i=1;i<=n;i++){
        printf("\t%d",i);
    }
    for(int i=1;i<=n;i++){
        printf("\n\n%d",i);
        for(int j = 1;j<=n;j++){
            if(board[i] == j){
                printf("\tQ");
            }
            else{
                printf("\t_");
            }
        }
    }
}

int place(int row, int col){
    for(int i = 1;i<=row-1;i++){
        if(board[i] == col){
            return 0;
        }
        else if(abs(board[i]-col) == abs(i-row)){
            return 0;
        }
    }
    return 1;
}

void nqueen(int n, int row){
    int col;
    for(col = 1;col<=n;col++){
        if(place(row,col)){
            board[row] = col;
            if(row==n){
                display(n);
            }
            else{
                nqueen(n,row+1);
            }
        }
    }
}

void main(){
    int n;
    printf("Enter no. of queen: ");
    scanf("%d",&n);
    nqueen(n,1);
}