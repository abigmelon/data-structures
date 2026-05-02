//
// Created by 63092 on 2026/3/14.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("file_modes.txt", "w");
    if (file == NULL) {
        printf("失败\n");
        return 1;
    }

    // 向文件中写入所有 fopen 打开模式的说明
    fprintf(file, "C语言 fopen 函数文件打开模式汇总\n");
    fprintf(file, "=====================================\n\n");

    // 基础模式
    fprintf(file, "1. 基础打开模式（文本模式）\n");
    fprintf(file, "   r    ：以只读方式打开文件。文件必须存在，否则打开失败。\n");
    fprintf(file, "   w    ：以只写方式打开文件。文件不存在则创建，存在则清空原有内容。\n");
    fprintf(file, "   a    ：以追加方式打开文件。文件不存在则创建，写入内容追加到文件末尾。\n");
    fprintf(file, "   r+   ：以读写方式打开文件。文件必须存在，可读写，不会清空原有内容。\n");
    fprintf(file, "   w+   ：以读写方式打开文件。文件不存在则创建，存在则清空原有内容。\n");
    fprintf(file, "   a+   ：以读写方式打开文件。文件不存在则创建，写入内容追加到末尾，可读整个文件。\n\n");

    // 二进制模式（Windows 系统区分文本/二进制，Linux/Mac 不区分）
    fprintf(file, "2. 二进制模式（在基础模式后加 b）\n");
    fprintf(file, "   rb   ：以二进制只读方式打开文件（如图片、视频、可执行文件等）。\n");
    fprintf(file, "   wb   ：以二进制只写方式打开文件，创建/清空文件。\n");
    fprintf(file, "   ab   ：以二进制追加方式打开文件，写入到末尾。\n");
    fprintf(file, "   rb+  ：以二进制读写方式打开文件，文件必须存在。\n");
    fprintf(file, "   wb+  ：以二进制读写方式打开文件，创建/清空文件。\n");
    fprintf(file, "   ab+  ：以二进制读写方式打开文件，追加写入，可读整个文件。\n\n");

    // 扩展说明
    fprintf(file, "=====================================\n");
    fprintf(file, "补充说明：\n");
    fprintf(file, "1. 文本模式（无 b）：Windows 下会自动转换 \\n ↔ \\r\\n，Linux/Mac 无转换。\n");
    fprintf(file, "2. 二进制模式（加 b）：直接读写字节，不做任何转换，适合非文本文件。\n");
    fprintf(file, "3. 所有模式打开失败时，fopen 返回 NULL，需检查返回值。\n");

    // 关闭文件
    fclose(file);
    printf("文件模式说明已成功写入 file_modes.txt！\n");

    return 0;
}