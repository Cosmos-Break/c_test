//找出 100 到 1000 内的不含 9 的素数，存到 result 文件中.
#include "pch.h"
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isPrime(int a) {//是素数
	if (a < 2)
		return false;
	for (int i = 2; i <= sqrt(a); ++i) {
		if (a%i == 0)
			return false;
	}
	return true;
}
bool has9(int a) {//含有9
	if (a <= 0)
		return false;
	int digit = a % 10;
	int remainder = a / 10;
	if (digit != 9 && !has9(remainder)) {
		return false;
	}
	else return true;
}
int main() {
	/*int target;
	while (scanf("%d", &target)) {
		if (has9(target))
			printf("has9");
		else printf("don't has9");
		printf("\n");
	}*/
	FILE* fp = fopen("result", "w");//打开文件
	if (!fp) {
		printf("can't open file");
		return EXIT_FAILURE;
	}
	for (int i = 100; i <= 1000; ++i) {
		if (isPrime(i) && !has9(i)) {
			fprintf(fp, "%d ", i);
		}
	}
	fclose(fp);//不要忘记关闭文件
	return 0;
}