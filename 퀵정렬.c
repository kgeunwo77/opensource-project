#include<stdio.h>
void quickS(int arr[], int index) {
    int pivot, cursor, i, temp;
    pivot = arr[0];
    cursor = 0;
    for (i = 1; i < index; i++) {
        if (pivot > arr[i]) {
            cursor++;
            temp = arr[cursor];
            arr[cursor] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[0];
    arr[0] = arr[cursor];
    arr[cursor] = temp;
    if (cursor > 0) {
        quickS(arr, cursor);
    }
    if (cursor + 1 < index - 1) {
        quickS(arr + cursor + 1, index - cursor - 1);
    }
}
int main() {
    int i, num, index, arr[30];
    index = 0;
    while (scanf("%d", &num) != EOF) {
        arr[index] = num;
        index++;
    }
    quickS(arr, index);
    for (i = 0; i < index; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}