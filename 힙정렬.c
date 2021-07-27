#include<stdio.h>
void heapS(int arr[], int index) {
    int i, temp;
    for (i = index - 1; i > 0; i--) {
        if (arr[i] > arr[(i - 2) / 2]) {
            temp = arr[i];
            arr[i] = arr[(i - 2) / 2];
            arr[(i - 2) / 2] = temp;
        }
        if (arr[i] > arr[(i - 1) / 2]) {
            temp = arr[i];
            arr[i] = arr[(i - 1) / 2];
            arr[(i - 1) / 2] = temp;
        }
    }
    temp = arr[0];
    arr[0] = arr[index - 1];
    arr[index - 1] = temp;
    if (index > 2) {
        heapS(arr, index - 1);
    }
}
int main() {
    int arr[30], i, index, num;
    index = 0;
    while (scanf("%d", &num) != EOF) {
        arr[index] = num;
        index++;
    }
    heapS(arr, index);
    for (i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}