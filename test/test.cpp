// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int max(int x, int y)
{
	return x > y ? x : y;
}

int main()
{
	/*char a, b, c, d;
	scanf("%c%c", &a, &b);
	c = getchar();
	d = getchar();
	printf("%c%c%c%c\n", a, b, c, d);*/

	/*char s[4];
	int i = 0;
	do {
		scanf("%c", &s[i]);
	} while (s[i++] != '\n');
	s[i] = '\0';
	printf("%s", s);*/

	/*char str[20] = "123456! ";
	printf("%d", strlen(str));*/

	/*char str[20] = "123\0";
	printf("%s", str);*/

	/*struct
	{
		int a;
		char b;
		double c;
	} s1;
	s1.a = 1;
	printf("%d", s1.a);*/

	/*int x = 2;
	int y = (x + 2, x + 3);
	printf("%d", y);*/

	/*int i, j;

	j = 10;
	i = j++, j + 100, 999 + j;

	printf("%d", i);*/

	/*char str[] = "hello,dear" "dear";
	printf("%s", str);*/


	//int  var1 = 1;
	//char var2[10];

	//printf("var1 变量的地址： %p\n", &var1);
	//printf("var1 变量的地址： %p\n", var1);
	//printf("var2 变量的地址： %p\n", var2);
	//printf("var2 变量的地址： %p\n", &var2);

	/*int a;
	float x;
	char c1;
	char ch;
	char buff[100];
	scanf("%d", &a);
	scanf("%f", &x);
	while ((ch = getchar()) == '\n' || ch == ' ');
	c1 = ch;
	gets_s(buff);
	printf("a=%d,x=%f,c1=%c", a, x, c1);
	printf("\n%s", buff);
	return 0;*/

	///* p 是函数指针 */
	//int (*p)(int, int) = &max; // &可以省略
	//int a, b, c, d;

	//printf("请输入三个数字:");
	//scanf("%d %d %d", &a, &b, &c);

	///* 与直接调用函数等价，d = max(max(a, b), c) */
	//d = p(p(a, b), c);

	//printf("最大的数字是: %d\n", d);

	///*/* */*/

	/*int a1, a2;
	char c1, c2;
	scanf("%d%c%d%c", &a1, &c1, &a2, &c2);
	printf("%d, %c, %d, %c", a1, c1, a2, c2);*/

	/*int i;
	char c;
	scanf("%d", &i);
	scanf("%c", &c);
	printf("%d,%c", i, c);*/

	/*int a;
	printf("input a number\n");
	scanf("%d", &a);
	printf("%ld", a);
	return 0;*/

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
