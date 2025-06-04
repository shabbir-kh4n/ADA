// knapsack Greedy

#include <stdio.h>
typedef struct{
    int id,wt,val;
    float r;
}item;

void display(item it[], int n){
    printf("\nItem\tWeight\tValue\tRatio\n");
    for(int i=1;i<=n;i++){
        printf("%d\t%d\t%d\t%.2f\n",it[i].id,it[i].wt,it[i].val,it[i].r);
    }
}

void main(){
    item it[10],temp;
    int n,capacity,in_capacity,selected_c[10],selected_d[10];
    float tval_c = 0,tval_d = 0;

    printf("Enter The no. of items:\n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        printf("Enter the Cost and val of item[%d]: ",i);
        scanf("%d",&it[i].wt);
        scanf("%d",&it[i].val);
        it[i].id = i;
        it[i].r = it[i].val/it[i].wt;
        selected_c[i] = 0;
        selected_d[i] = 0;
    }

    printf("Enter the Capacity of bag: ");
    scanf("%d",&capacity);
    in_capacity = capacity;

    display(it,n);

    for(int i=1; i<n;i++){
        for(int j =i+1; j<=n;j++){
            if(it[i].r < it[j].r){
                temp = it[i];
                it[i] = it[j];
                it[j] = temp;
            }
        }
    }

    display(it,n);

    //Continuous
    for(int i=1;i<=n;i++){
        if(capacity<it[i].wt){
            tval_c+= it[i].r * capacity;
            selected_c[it[i].id] = 2;
            break;
        }
        tval_c += it[i].val;
        capacity -= it[i].wt;
        selected_c[it[i].id] = 1;
    }

    printf("Total profit in fractional: %.2f ",tval_c);
    printf("\nItem selected in fractional: ");
    for(int i =1;i<=n;i++){
        if(selected_c[i]!=0){
            printf("%d ",i);
        }
    }

    //Dicrete
    capacity = in_capacity;
    for(int i=1;i<=n;i++){
        if(capacity>=it[i].wt){
            tval_d += it[i].val;
            capacity -= it[i].wt;
            selected_d[it[i].id] = 1;
        }
    }

    printf("\nTotal profit in Discrete: %.2f ",tval_d);
    printf("\nItem selected in Discrete: ");
    for(int i =1;i<=n;i++){
        if(selected_d[i]!=0){
            printf("%d ",i);
        }
    }
}
