//把一个数表示成若干个素数的和.
#include "pch.h"
#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool isPrime(int a) {//判断素数
	if (a < 2) 
		return false;
	for (int i = 2; i*i <= a; ++i) {
		if (a%i == 0)
			return false;
	}
	return true;
}
int* getPrimes(int target, int &num) {//测试:返回一个变长数组
	int* primes;
	primes = (int *)malloc(sizeof(int));
	int primeCount = 0;
	for (int i = 2; i <= target; ++i) {
		if (isPrime(i)) {
			primes = (int*)realloc(primes, (primeCount+1) * sizeof(int));
			primes[primeCount] = i;
			primeCount++;
		}
	}
	
	num = primeCount;
	return primes;
}
void printArray(int* arr,int num) {
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
}
bool splitIntoTwoPrimes(int target) {//分成两个素数
	if (target < 2)
		return false;
	if (isPrime(target)) {
		printf("%d ", target);
		return true;
	}
	for (int i = target-1; i >= 2; --i) {//递归分成更多素数
		if (isPrime(i) && splitIntoTwoPrimes(target - i)) {
			printf("%d ", i);
			return true;
		}
	}
}
int main() {
	int target;
	while (scanf("%d", &target)) {
		if (splitIntoTwoPrimes(target))
			printf("success");
		else printf("fail");
		printf("\n");
	}
	/*int primeCount = 0;
	int *primes = getPrimes(target, primeCount);
	printArray(primes, primeCount);
	free(primes);*/
	
	return 0;
}