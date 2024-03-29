// 2011.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//输出 1000 - 9999 中满足以下条件的所有数：
//该数是素数.
//十位数和个位数组成的数是素数，百位数和个位数组成的数是素数.
//个位数和百位数组成的数是素数，个位数和十位数组成的数是素数.比如 1991 ，个位和十位组成的数就是19 .

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

bool isPrime(int a) {
	if (a < 2)
		return false;
	for (int i = 2; i <= sqrt(a); i++){
		if (a % i == 0)
			return false;
	}
	return true;
}
int main()
{

	for (int i = 1000; i < 10000; i++){
		if (!isPrime(i))
			continue;
		int ge = i % 10;
		int shi = (i / 10) % 10;
		int bai = (i / 100) % 10;
		int a = shi * 10 + ge;
		int b = bai * 10 + ge;
		int c = ge * 10 + bai;
		int d = ge * 10 + shi;
		if (!isPrime(a) || !isPrime(b) || !isPrime(c) || !isPrime(d)) {
			continue;
		}
		printf("%d ", i);
		
	}
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
