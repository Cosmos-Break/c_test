// 2007.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//把 10 到 1000 之间满足以下两个条件的数，存到 result.txt 文件中.
//是素数.
//它的反数也是素数，如： 123 的反数是 321 .

#include "pch.h"
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isPrime(int a) {
	if (a < 2)
		return false;
	for (int i = 2; i <= sqrt(a); ++i) {
		if (a%i == 0)
			return false;
	}
	return true;
}
int reverse(int a) {
	int b = 0;
	int digit;
	while (a != 0) {
		digit = a % 10;
		a = a / 10;
		b = b * 10 + digit;
	}
	return b;
}
int main()
{
	printf("%d",reverse(123));
	FILE* fp = fopen("result.txt", "w");
	if (!fp) {
		printf("can't open file");
		return EXIT_FAILURE;
	}
	for (int i = 10; i <= 1000; ++i) {
		if (isPrime(i) && isPrime(reverse(i)))
			fprintf(fp,"%d ", i);
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
