// 2017.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//已知：二进制数据文件 data.bin 中存放了若干个整数，请编写程序完成如下功能：
//编写程序读取所有数据.
//以每相邻两个整数为一对按顺序构成二维平面上的坐标点.例如：有数据 12 ， 34 ， 53 ， 25 ， 61 ，
//28 ， 78 等，则构成六个坐标点如下：(12, 34) 、(34, 53) ，(53, 25), (25, 61), (61, 28), (28,
//	78) ；
//	以每个坐标点为圆心，以该点与其后面第一个点的欧氏距离为半径 r.计算每个圆包含的坐标点数.计算最后
//	一个点时以其和第一个点的欧氏距离为半径.
//	例如：
//	坐标点(12, 34) 的圆半径$r = \sqrt{ (12 - 34) ^ 2 + (34 - 53) ^ 2 }$是坐标点(12, 34) 与(34, 53) 的欧式距离.
//	坐标点(28, 78) 的圆半径$r = \sqrt{ (28 - 12) ^ 2 + (78 - 34) ^ 2 }$是坐标点(28, 78) 与(12, 34) 的欧式距离.
//	坐标点 包含点数 点密度
//	(x坐标，y坐标) (占5列，右对齐)(占7列，右对齐，保留2位小数)
//	计算所有圆的点密度值，然后输出点密度值最大的 5 个坐标点以及相应圆中包含的点数和点密度值.输出格式
//	要求：
//	上述文字部分不需要显示.
//	其中：圆的点密度为圆包含的点数除以圆面积，如果点在圆上，则也算圆包含该点，在计算点密度时，圆心也算一
//	个点.计算圆面积时$\pi = 3.14$.例如：坐标点(2, 1) ，则该坐标点也属该坐标点的圆内的一个点.

#include "pch.h"
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct {//坐标结构体
	int x;
	int y;
}point;
typedef struct {
	int pos;//arr中的位置
	float r;//与后一个点组成的圆半径
	int contain;//包含的点数
}status;
void display(point* arr, int length) {//打印所有的坐标点
	for (size_t i = 0; i < length; i++)
	{
		printf("x:%d,y:%d\n", arr[i].x, arr[i].y);
	}
}
int compare(const void* a, const void* b) {
	return ((status*)b)->contain - ((status*)a)->contain;
}
int main()
{
	FILE* fp = fopen("data.bin", "rb");
	if (!fp) {
		printf("can't open file");
		return EXIT_FAILURE;
	}
	fseek(fp, 0, SEEK_END);
	int count = ftell(fp) / sizeof(int);
	int* num = (int*)malloc(sizeof(int)*count);
	fseek(fp, 0, SEEK_SET);
	fread(num, sizeof(int), count, fp);
	//一共应该有count-1个坐标点
	point* arr = (point*)malloc(sizeof(point)*(count - 1));
	for (size_t i = 1; i < count; i++)
	{
		arr[i - 1].x = num[i-1];
		arr[i - 1].y = num[i];
	}
	printf("count:%d\n", count);
	display(arr, count - 1);
	status* arr2 = (status*)malloc(sizeof(status)*(count - 1));
	for (size_t i = 0; i < count-1; i++)
	{
		printf("\n第%d个点与第%d个点构成的圆包含的点:", i + 1, (i + 2) % (count - 1));
		float r = sqrt(pow(arr[i].x - arr[(i + 1) % (count - 1)].x, 2) + pow(arr[i].y - arr[(i + 1) % (count - 1)].y, 2));
		arr2[i].pos = i;
		arr2[i].r = r;
		arr2[i].contain = 0;
		for (size_t j = 0; j < count - 1; j++) {
			float d = sqrt(pow(arr[i].x - arr[j].x, 2) + pow(arr[i].y - arr[j].y, 2));
			if (d < r) {
				printf("(%d,%d) ", arr[j].x, arr[j].y);
				arr2[i].contain++;
				
			}
		}
		printf("contain:%d\n", arr2[i].contain);
	}
	printf("\n");
	for (size_t i = 0; i < count - 1; i++)
	{
		printf("pos:%d r:%f contain:%d\n", arr2[i].pos, arr2[i].r, arr2[i].contain);
	}

	printf("sorted:\n");
	qsort(arr2, count - 1, sizeof(status), compare);
	for (size_t i = 0; i < count-1; i++)
	{
		printf("pos:%d r:%f contain:%d\n", arr2[i].pos, arr2[i].r, arr2[i].contain);
	}
	for (size_t i = 0; i < 5; i++)
	{
		printf("坐标:(%d,%d)包含点数:%5d点密度:%7.10f\n", arr[arr2[i].pos].x, arr[arr2[i].pos].y, arr2[i].contain, (double)arr2[i].contain / (double)(3.14*pow(arr2[i].r, 2)));
	}
	/*printf("%7f\n", (double)((double)43 / (3.14*pow(123.234234, 2))));*/
	free(arr);
	free(arr2);
	fclose(fp);
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
