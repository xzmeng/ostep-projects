#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024

void cat(char *filename) {
    char buffer[MAXLINE + 1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("wcat: cannot open file\n");
        exit(1);
    }
    while(fgets(buffer, MAXLINE, fp)) {
        printf("%s", buffer);
    }
    if (!feof(fp)) {
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        exit(0);
    } else {
        for (int i = 1; i < argc; i++) {
            cat(argv[i]);
        }
    }
}

