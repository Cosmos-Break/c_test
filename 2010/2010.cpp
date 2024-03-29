// 2010.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//从 FTP 上下载 make.exe 和 org.dat ，运行 make.exe 输入准考证后三位生成 data.txt ，文件为二进制编码.
//data.txt 内存有 2048 个整数，其中前 n 个为非 0 数，后 2048 - n 个数为 0 ，将其读入数组，计算非零数的个数 n .
//选出 n 个数中的最大数和最小数.
//选出 n 个数中最大素数.
//将 n 个数从大到小排序，并平均分成三段(若 n 非 3 的整数倍，则不考虑最后的 1 - 2 个数)，选出中间段的最大数和最小数.


#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>


bool isPrime(int a) {
	if (a < 2)
		return false;
	for (int i = 2; i <= sqrt(a); ++i) {
		if (a%i == 0)
			return false;
	}
	return true;
}
int compare(const void* a, const void* b) {
	return *(int*)b - *(int*)a;
}
int main()
{
	srand(time(NULL));
	FILE* fp = fopen("data.txt", "wb");
	if (!fp) {
		printf("can't open file");
		return EXIT_FAILURE;
	}
	int arr[2048];
	for (int i = 0; i < 233; i++)
	{
		arr[i] = (rand() % 500) + 1;
		printf("%d ", arr[i]);
	}
	for (int i = 233; i < 2048; i++) {
		arr[i] = 0;
	}
	fwrite(arr, sizeof(int), 2048, fp);
	fclose(fp);
	fp = fopen("data.txt", "rb");
	int buff[2048];
	fread(buff, sizeof(int), 2048, fp);

	int length = 0;
	for (int i = 0; i < 2048; i++)
	{
		if (buff[i] == 0) {
			length = i;
			break;
		}
	}
	printf("\nlength:%d\n", length);
	qsort(buff, length, sizeof(int), compare);
	printf("max:%d\n", buff[0]);
	printf("min:%d\n", buff[length - 1]);
	for (int i = 0; i < length; i++)
	{
		printf("%d ", buff[i]);
	}
	int maxPrime;
	for (int i = 0; i < length; i++)
	{
		if (isPrime(buff[i])) {
			maxPrime = buff[i];
			break;
		}
	}
	printf("maxPrime:%d\n", maxPrime);
	int b = length / 3;
	int c = length / 3 * 2;
	printf("middleMax:%d\n", buff[b]);
	printf("middleMin:%d\n", buff[c - 1]);
	

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
