#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]) {
	int i, j;
	char flag, tmp;
	int cnt = 1;
	FILE* src;

	if (strcmp(argv[1], "-n") == 0) {
		for (i = 2; i < argc; i++) {
			if (i == 2)
				printf("     %d  ", cnt);
			src = fopen(argv[i], "r");
			while (1) {
				tmp = fgetc(src);
				if (feof(src))
					break;
				if (flag == '\n') {
					cnt++;
					printf("     %d  ", cnt);
				}
				printf("%c", tmp);
				flag = tmp;
			}
			close(src);
		}
	}
	else {
		for (i = 1; i < argc; i++) {
			src = fopen(argv[i], "r");
			while (1) {
				tmp = fgetc(src);
				if (feof(src))
					break;
				printf("%c", tmp);
			}
			close(src);
		}
	}
	return 0;
}