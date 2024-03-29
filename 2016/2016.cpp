// 2016.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//文本文件 input.txt 由若干英文单词和分隔符(空格，回车，换行)构成.根据如下说明编写程序统计不同单词出现
//的次数(频度).将统计结果按出现频度从高到低排序，并将出现频度大于 5 的单词及其频度输出到文件 output.txt
//中.文件格式如图所示

//多个连续的分隔符被视为一个分隔符.
//大小写敏感.
//每个单词的长度不超过 20 个字符.
//单词的数量未知.如使用定义静态大数组的方式来统计，将被扣除 5 分.
#include "pch.h"
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct {
	int freq;
	char word[20];
}Word;
int compare(const void* a, const void* b) {
	return ((Word*)b)->freq - ((Word*)a)->freq;   //这里在用强制转换之后 要在外面套上括号! 不能缺省.
}
void find(Word* arr, int& length, char buff[20]) {
	for (size_t i = 0; i < length; i++)
	{
		if (strcmp(arr[i].word, buff) == 0) {//该单词已经存在
			arr[i].freq += 1;
			return;
		}
	}
	//该单词还不存在 加入词典
	arr[length].freq = 1;
	strcpy(arr[length].word, buff);
	length++;//长度加一
}
int main()
{
	FILE* fpr = fopen("input.txt", "r");
	if (!fpr) {
		printf("can't open file");
		return EXIT_FAILURE;
	}
	FILE* fpw = fopen("output.txt", "w");
	if (!fpw) {
		printf("can't open file");
		return EXIT_FAILURE;
	}
	char buff[20];
	int wordCount = 0;
	while ((fscanf(fpr, "%s", buff))!=EOF) {
		wordCount++;
	}
	Word* arr = (Word*)malloc(sizeof(Word)*wordCount);
	int uniqueCount = 0;
	fseek(fpr, 0, SEEK_SET);
	for (size_t i = 0; i < wordCount; i++){
		fscanf(fpr, "%s", buff);
		find(arr, uniqueCount, buff);
	}
	qsort(arr, uniqueCount, sizeof(Word), compare);
	for (size_t i = 0; i < uniqueCount; i++)
	{
		if (arr[i].freq < 5)
			break;
		fprintf(fpw, "%s, %d\n", arr[i].word, arr[i].freq);
	}

	fclose(fpr);
	fclose(fpw);
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
