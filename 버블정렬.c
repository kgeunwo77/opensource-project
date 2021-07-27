#include<stdio.h>
#define MAX 30
int main() {
	int i, num, index, k, flag, arr[MAX], temp;
	index = 0;
	while (scanf("%d", &num) != EOF) {
		arr[index] = num;
		index++;
	}
	k = index - 1;
	flag = 1;
	while (k > 0 && flag == 1) {
		flag = 0;
		for (i = 0; i < k; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				flag = 1;
			}
		}
		k--;
	}
	for (i = 0; i < index; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}