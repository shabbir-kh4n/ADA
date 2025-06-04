#include <stdio.h>
#include <stdio.h>
#include <time.h>
#define max 50000

void merge(int a[max],int low,int mid,int high){
    int newarr[max], k = low;
    int i = low;
    int j = mid+1;

    while(i<=mid && j<=high){

        if(a[i]<a[j]){
            newarr[k++] = a[i++];
        }
        else{
            newarr[k++] = a[j++];
        }
    }
    while(i<=mid){
        newarr[k++] = a[i++];
    }

    while(j<=high){
        newarr[k++] = a[j++];
    }

    for(int i = low; i <= high; i++){
        a[i] = newarr[i];
    }
}

void sort(int a[max],int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        sort(a,low,mid);
        sort(a,mid+1,high);
        merge(a,low,mid,high);
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
    sort(arr,0,n-1);
    clock_t end = clock();
    printf("Sorted Array: ");
    
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\nTime Taken: %.8f",(double)(end-start)/CLOCKS_PER_SEC);
}
