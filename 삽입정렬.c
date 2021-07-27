#include<stdio.h>
#define MAX 30
int main() {
    int i, j, index, num, arr[MAX], temp;
    index = 0;
    while (scanf("%d", &num) != EOF) {
        arr[index] = num;
        index++;
    }
    for (i = 0; i < index - 1; i++) {
        for (j = i + 1; j > 0; j--) {
            if (arr[j - 1] > arr[j]) {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
            else
                continue;
        }
    }
    for (i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}