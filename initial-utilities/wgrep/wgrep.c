#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int match(char *txt, char *pat) {
    int m = strlen(txt);
    int n = strlen(pat);
    for (int i = 0; i < m - n; i++) {
        int j = 0;
        while (txt[i + j] == pat[j]) {
            j++;
        }
        if (j == n) {
            return i;
        }
    }
    return -1;
}

void grep_and_print(FILE *fp, char *pat) {
    char *line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    while ((linelen = getline(&line, &linecap, fp)) > 0) {
        if (match(line, pat) != -1)
            fwrite(line, linelen, 1, stdout);
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    if (argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    } else if(argc == 2){
        fp = stdin;
    } else {
        fp = fopen(argv[2], "r");
        if (fp == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
    }
    char *pat = argv[1];
    grep_and_print(fp, pat);
    exit(0);
}