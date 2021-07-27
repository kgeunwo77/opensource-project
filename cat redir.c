#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]) {
    FILE* fd;
    char* readData;
    char writeData;
    
    if (strcmp(argv[1], ">") == 0) //>가 문자일 때.. argc==1로는 구현 못함..
        fd = fopen(argv[2], "w");
    
    while (scanf("%c", &writeData)!=EOF) {
        fputc(writeData, fd);
    }
    close(fd);
    return 0;
}