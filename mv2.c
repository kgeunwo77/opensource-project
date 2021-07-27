#include<stdio.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char* argv[]) {
    int i, j;
    struct stat buf;

    FILE* from;
    FILE* to;
    char* save_dir = argv[argc - 1];

    lstat(argv[argc - 1], &buf);
    if (S_ISDIR(buf.st_mode)) {
        for (i = 1; i < argc - 1; i++) {
            char save[1000];
            char tmp_char;
            strcpy(save, save_dir);
            strcat(save, "/");
            strcat(save, argv[i]);

            from = fopen(argv[i], "r");
            to = fopen(save, "w");
            while (1) {
                tmp_char = fgetc(from);
                if (feof(from))
                    break;
                fputc(tmp_char, to);
            }
            fclose(from);
            fclose(to);
            remove(argv[i]);
        }
    }
    else {
        if (argc == 3) {
            rename(argv[1], argv[2]);
        }
        else
            printf("mv: target '%s' is not a directory\n", argv[argc - 1]);
    }
    return 0;
}