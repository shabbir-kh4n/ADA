#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 50000

void sort(int arr[max], int n){
    int min, temp;
    for(int i = 0 ;i<n-1;i++){
        min = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void main(){
    int n, arr[max];
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        arr[i] = rand()%n;
    }
    printf("Un-Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    clock_t start = clock();
    sort(arr,n);
    clock_t end = clock();
    printf("Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\nTime Taken: %.8f",(double)((end-start)/CLOCKS_PER_SEC));
}