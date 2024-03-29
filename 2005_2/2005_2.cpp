// 2005_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


//统计篇文章中各英文字母的个数，并排序.
#include "pch.h"
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


bool isLetter(char &ch) {//是字母
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return true;
	else return false;
}
bool isUpper(char &ch) {//是大写字母
	if (ch >= 'A' && ch <= 'Z') {
		return true;
	}
	else return false;
}
bool isLower(char &ch) {//是小写字母
	if (ch >= 'a'&&ch <= 'z')
		return true;
	else return false;
}
typedef struct {
	char letter;
	int count;
}Letter;//字母和出现次数的结构体
int compare(const void* A, const void* B) {//用于排序的比较函数
	return ((Letter*)A)->count - ((Letter*)B)->count;
}
int main()
{
	int letter[26] = {0};
	char ch;
	FILE* fp = fopen("eng.txt", "r");//读取文件
	if (!fp) {
		printf("can't open file");
		return EXIT_FAILURE;
	}
	while ((ch = fgetc(fp)) != EOF) {
		if (isLower(ch)) {//小写字母
			letter[ch - 'a'] += 1;
		}
		else if (isUpper(ch)) {//大写字母
			letter[ch - 'A'] += 1;
		}
		else continue;//其他字符
	}

	
	fclose(fp);//关闭文件
	/*for (int i = 0; i < 26; ++i) {
		printf("%c:%d\n", 'A' + i, letter[i]);
	}*/
	Letter arr[26];
	for (int i = 0; i < 26; ++i) {
		arr[i].letter = 'A' + i;
		arr[i].count = letter[i];
	}//赋值给结构体
	qsort(arr, 26, sizeof(Letter), compare);//排序
	for (int i = 0; i < 26; ++i) {
		printf("%c:%d\n", arr[i].letter, arr[i].count);
	}
	printf("end");
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
