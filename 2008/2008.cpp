// 2008.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//要求：
//用 IE 从 FTP 上下载 org.dat ，并保存在 D 盘的根目录中.
//此文件中按文本方式存放了一段其他文章，其中有若干长度小于 15 的英文单词，单词之间用空格分开，无其他符号.
//顺序读取这段文章的不同的单词(大小写敏感)，同时在读取的过程中排除所有的单词 THE 以及变形，即这些单词不能出现在读取的结果中.
//将读取的所有单词的首字母转大写后，输出 D 根目录下 new.txt ，每个单词一行.

#include "pch.h"
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

bool isthe(char word[15]) {
	if ((word[0] == 't' || word[0] == 'T') && (word[1] == 'h' || word[1] == 'H') && (word[2] == 'e' || word[2] == 'E') && word[3] == 0)
		return true;
	else return false;
}
void turnUpper(char word[15]) {
	int i = 0;
	while (word[i] != 0) {
		if (word[i] >= 'a'&&word[i] <= 'z')
			word[i] = word[i] - ('a' - 'A');
		++i;
	}
}
int main()
{
	FILE* fp = fopen("D:/org.dat", "r");
	if (fp == NULL) {
		printf("can't open file");
		return EXIT_FAILURE;
	}
	FILE* fp2 = fopen("D:/new.txt", "w");
	if (!fp) {
		printf("can't open file");
		return EXIT_FAILURE;
	}
	char word[15];
	while (fscanf(fp, "%s\n", word) != EOF) {
		if (isthe(word))
			continue;
		
		else {
			turnUpper(word);
			fprintf(fp2, "%s ", word);
			
		}
	}


	fclose(fp);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
