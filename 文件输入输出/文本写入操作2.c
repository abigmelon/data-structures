//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("file.txt", "a+");//追加到末尾
    char buf[3];
    setvbuf(file, buf, _IOFBF,3);//设置缓冲区的大小
    if (file != NULL) {
        while (1) {
            int c = getchar();
            if (c == 'q') break;
            putc(c, file);
            fflush(file);//刷新缓冲区
        }
        fclose(file);
    }
    return 0;
}