#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low+1;
    int j=high, temp;
    
    while(i<=j){
        while(arr[i]<=pivot && i <=high){
            i++;
        }
        while(arr[j]>pivot && j >= low){
            j--;
        }
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void sort(int arr[],int low,int high){
    if(low<high){
        int part = partition(arr,low,high);
        sort(arr,low,part-1);
        sort(arr,part+1,high);
    }
}

int main(){
    int n, arr[5000];
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
    sort(arr,0,n-1);
    
    printf("Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}