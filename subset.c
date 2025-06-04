#include <stdio.h>
#define max 100
int s[max], set[max], d, n, flag = 0,count =0;

void display(int set[], int count) {
    printf("{");
    for (int i = 0; i < count; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}

void subset(int sum, int i) {
    if (sum == d) {
        flag = 1;
        display(set, count);
        return;
    }
    if (i >= n || sum > d) {
        return;
    }

    set[count] = s[i];
    count++;
    subset(sum + s[i], i + 1);
    count--;
    subset(sum, i + 1);
}

int main() {
    printf("Enter the no of element in Set: ");
    scanf("%d", &n);
    printf("Enter elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    printf("Enter the sum to Generate: ");
    scanf("%d", &d);
    subset(0, 0);
    if (flag == 0) {
        printf("No subset found with the given sum.\n");
    }
    return 0;
}