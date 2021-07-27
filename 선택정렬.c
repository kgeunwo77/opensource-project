#include<stdio.h>
int main() {
    int i, j, num, index, arr[30], temp;
    index = 0;
    while (scanf("%d", &num) != EOF) {
        arr[index] = num;
        index++;
    }
    for (i = 0; i < index; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (i = 0; i < index; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}