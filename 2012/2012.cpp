// 2012.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//从服务器上下载数据文件 org.dat 文件以二进制方式存放一系列整数，每个整数占 4 个字节.从第一个整数
//开始，第一个整数和第二个整数构成一个坐标点，以此类推，数据文件中保存了许多坐标点数据.
//规定处于第一象限的坐标点为有效点，请问数据文件中所有点的个数 n 为多少？有效点的个数 k 为多少？
//每个有效点与坐标原点构成一个的矩形，请问 k 个有效点与坐标原点构成的 k 个矩形的最小公共区域面积为多少？
//寻找有效点中符合下列条件的点：以该点为坐标原点，其它有效点仍然是有效点即处于第一象限(不包括坐标轴上的点).输出这些点.
//对所有有效点进行分组，每个有效点有且只有属于一个分组，分组内的点符合下列规则：若对组内所有点的x
//坐标进行排序，点 p1(x1, y1) 在点 p2(x2, y2) 后面，即 x1 > x2 那么 y1 > y2 ，请输出所有的分组.



//现在用户从键盘输入一个坐标和一个数字 m ，设计算法输出 m 个离该坐标距离最近的点的坐标和每个坐标到
//该点的距离，写入到 output.txt 文件中.
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
void display(point* arr, int length) {//打印所有的坐标点
	for (size_t i = 0; i < length; i++)
	{
		printf("x:%d,y:%d\n", arr[i].x, arr[i].y);
	}
}
int compare(const void* a, const void* b) {//按照点的x坐标排序 从小到大
	return ((point*)a)->x - ((point*)b)->x;   //这里在用(point*)强制转换之后 要在外面套上括号! 不能缺省.
}
typedef struct {
	int x;
	int y;
	float distance;
}pointDistance;
int compare2(const void* a, const void* b) {
	return ((pointDistance*)a)->distance - ((pointDistance*)b)->distance;
}
int main()
{
	FILE* fp = fopen("org.dat", "rb");
	if (!fp) {
		printf("can't open file");
		return EXIT_FAILURE;
	}
	fseek(fp, 0, SEEK_END);//文件指针定位到文件结尾
	int n = ftell(fp) / sizeof(int) /2;
	point* arr = (point*)malloc(sizeof(point)*n);//动态分配内存
	fseek(fp, 0, SEEK_SET);//文件指针定位到文件开头
	int x, y;
	int k = 0;
	int minx = RAND_MAX;
	int miny = RAND_MAX;
	int minxpointpos, minypointpos;
	for (int i = 0; i < n; ++i) {
		fread(&x, sizeof(int), 1, fp);
		fread(&y, sizeof(int), 1, fp);
		if ((x <= 0) || (y <= 0))
		{
			continue;
		}
		if (minx > x) {
			minx = x;
			minxpointpos = k;
		}
		if (miny > y) {
			miny = y;
			minypointpos = k;
		}
		arr[k].x = x;
		arr[k].y = y;
		++k;
	}
	printf("n:%d\n", n);
	printf("k:%d\n", k);
	display(arr, k);
	printf("minOverlapArea:%d\n", minx*miny);
	if (minxpointpos == minypointpos) {
		printf("valid point:(%d,%d)\n", arr[minxpointpos].x, arr[minxpointpos].y);
	}
	else {
		printf("don't have such valid point\n");
	}
	qsort(arr, k, sizeof(point), compare);
	display(arr, k);
	for (size_t i = 0; i < k-1; i++)
	{
		printf("(%d, %d)", arr[i].x, arr[i].y);
		if (arr[i + 1].y < arr[i].y)
			printf("\n");
	}
	printf("(%d, %d)\n", arr[k-1].x, arr[k-1].y);//最后一个点



	
	point p;
	pointDistance* arr2 = (pointDistance*)malloc(sizeof(pointDistance)*k);
	printf("输入一个坐标x与y坐标用空格隔开:");
	scanf("%d%d", &(p.x), &(p.y));
	for (size_t i = 0; i < k ; i++) {
		arr2[i].distance = sqrt(pow((p.x - arr[i].x), 2) + pow((p.y - arr[i].y), 2));
		arr2[i].x = arr[i].x;
		arr2[i].y = arr[i].y;
	}
	qsort(arr2, k, sizeof(pointDistance), compare2);
	int m;
	printf("\n输出前m个距离最近的点m为:");
	scanf("%d", &m);
	for (size_t i = 0; i < m; i++)
	{
		printf("(%d,%d) 距离:%f\n", arr2[i].x, arr2[i].y, arr2[i].distance);
	}
	

	/*int count = 0;
	while (fgetc(fp) != EOF) {
		count++;
	}
	int pointCount = count / 8;
	fseek(fp, 0, 0);*/

	

	
	/*int* a = (int*)malloc(sizeof(int)*pointCount * 2);
	fread(a, sizeof(int), pointCount * 2, fp);
	for (int i = 0; i < pointCount * 2; i++) {
		printf("%d ", a[i]);
	}*/
	/*fread(arr, sizeof(point), pointCount, fp);
	for (int i = 0; i < pointCount; i++){
		printf("x:%d,y:%d\n", arr[i].x, arr[i].y);
	}*/
	free(arr);
	free(arr2);
	arr = NULL;
	
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
