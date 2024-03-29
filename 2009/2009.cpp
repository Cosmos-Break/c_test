// 2009.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//用 IE 浏览器从 FTP 上下载 org.dat ，并保存在 D 盘的根目录下.
//此文件中按文本方式存放了一段其他文章，其中有若干长度小于 15 的十进制或八进制数字，数字之间用 ,
//分开，数字内部存在且仅存在空格.
//八进制数以起始位 0 作为标示与十进制数区分.
//顺序读取这些数字将他们转变为十进制数后按从大到小的顺序排序后，输出到 D 盘根目录下 new.txt ，每个
//数字一行.
//eg ： _235_,34__2,_043_1_,1_3 ，分别是：十进制 235 ，十进制 342 ，八进制 431 ，十进制 13 ， _ 代表
//空格.
#include "pch.h"
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int calcOct(char num[15], int count) {//从一个字符数组计算八进制数
	int ret = 0;
	for (int i = 1; i < count; i++) {
		ret = ret * 8 + (num[i]-'0');
	}
	return ret;
}
int calcDec(char num[15], int count) {//从一个字符数组计算十进制数
	int ret = 0;
	for (int i = 0; i < count; i++)
	{
		ret = ret * 10 + (num[i]-'0');
	}
	return ret;

}
int getnum(char num[15], int count) {//去掉字符数组的空格 并计算对应的十进制int值
	int ret = 0;
	char newnum[15] = { 0 };
	int newcount = 0;
	for (int i = 0; i < count; ++i) {
		if (num[i] == ' ')
			continue;
		else {
			newnum[newcount] = num[i];
			++newcount;
		}
	}
	if (newnum[0] == '0') {//八进制数
		ret = calcOct(newnum, newcount);
	}
	else {//十进制数
		ret = calcDec(newnum, newcount);
	}
	return ret;
}
int compare(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}
int main()
{
	FILE* fp = fopen("org.dat", "r");
	if (!fp) {
		printf("can't open file");
		return EXIT_FAILURE;
	}
	char number[15] = { 0 };
	int arr[128] = { 0 };
	int arrCount = 0;
	char ch;
	char i = 0;
	while ((ch = fgetc(fp)) != EOF) {
		if (ch != ',') {
			number[i] = ch;
			++i;
		}
		else {
			arr[arrCount] = getnum(number, i);
			++arrCount;
			i = 0;//初始化
			memset(number, 0, sizeof(char) * 15);//初始化
		}
	}
	arr[arrCount] = getnum(number, i);//遇到EOF,然而还剩下最后一个数
	++arrCount;
	fclose(fp);
	qsort(arr, arrCount - 1, sizeof(int),compare);
	fp = fopen("new.txt", "w");
	for (int i = 0; i < arrCount; i++)
	{
		printf("%d ", arr[i]);
		fprintf(fp, "%d\n", arr[i]);
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
