// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCharacters(FILE* file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

int countWords(FILE* file) {
    int count = 0;
    char ch;
    int inWord = 0; // 标记是否在单词内部

    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == ',' || ch == '\n' || ch == '\t') {
            inWord = 0;
        }
        else if (inWord == 0) {
            inWord = 1;
            count++;
        }
    }
    return count;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s [parameter] [input_file_name]\n", argv[0]);
        return 1;
    }

    char* parameter = argv[1];
    char* filename = argv[2];

    FILE* file;
    if (fopen_s(&file, filename, "r") != 0) {
        printf("Error opening file.\n");
        return 1;
    }

    int count;
    if (strcmp(parameter, "-c") == 0) {
        count = countCharacters(file);
        printf("字符数：%d\n", count);
    }
    else if (strcmp(parameter, "-w") == 0) {
        count = countWords(file);
        printf("单词数：%d\n", count);
    }
    else {
        printf("Invalid parameter.\n");
        return 1;
    }

    fclose(file);
    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
