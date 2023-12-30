/*程序的编译文件，主要文件
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#define _CRT_SECURE_NO_WARNINGS
这些都是使用Visual Studio留下的后遗症，在一般的Dev C++或gcc编译的话这些不需要也没关系

#pragma warning(disable : 4996)和#pragma warning(disable : 6031)是防止scanf莫名在vs内报warning的
本人有点强迫症，所以加了一下

#define _CRT_SECURE_NO_WARNINGS是保证vs能够正常编译scanf，因为要使用vs默认认为scanf不安全，而scanf_s其他编译器不一定能通过
*/

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "struct.h"
#include "func.h"

struct rent_house rented[40];

int initialize()//初始化，打开文件的操作
{
	FILE* fp = fopen("rent.csv", "r");//声明文件指针，以只读形式打开
	int i = 0;
	if (fp == NULL)//判断文件是否正常
	{
		fprintf(stderr, "test for fopen() failed.\n");
		exit(EXIT_FAILURE);
	}
	while (!feof(fp))//逐行检查，直到EOF
	{
		char ssss[4000];//ssss看下面，它的意思主要是replaceCommaWithSpace()处理文本使用的字符数组
		fscanf(fp, "%s\n", ssss);
		//fscanf(fp, "%s,%d,%s,%d,%d,%d,%s,%s,%l32d\n", &rented[i].name, &rented[i].code, &rented[i].location, &rented[i].house_type, &rented[i].price, &rented[i].is_rent, &rented[i].time, &rented[i].number);
		//上面一行注释是失败品，这就是为什么要转空格，读者可以自行尝试带逗号的扫描输入
		char* inputString = ssss;
		char* result = replaceCommaWithSpace(inputString);
		//printf("%s\n", result);
		//上面一行测试使用，以确保没问题，对于C语言的断点测试，弱类型语言基本很抽象
		sscanf(result, "%s %d %s %d %d %d %d %l32d\n", rented[i].name, &rented[i].code, rented[i].location, &rented[i].house_type, &rented[i].price, &rented[i].is_rent, &rented[i].time, &rented[i].number);
		i++;
	}
	/*for (size_t i = 0; i < 40; i++) {
		printf("Name: %s, Code: %d, house_type: %d, Price: %d\n", rented[i].name, rented[i].code, rented[i].house_type, rented[i].price);
	}*/
	return 0;
}

void countElements(int arr[], int n)//统计数组中各个元素的个数，方便计算占比
{
	// 创建一个新的数组用于存储各元素的个数
	int count[100] = { 0 }; // 假设数组元素的取值范围在0到99之间

	// 统计各元素的个数
	for (int i = 0; i < n; ++i)
	{
		count[arr[i]]++;
	}

	int nonZeroCount = countNonZeroElements(arr, n);

	// 输出结果
	for (int i = 1; i < 100; ++i)
	{
		if (count[i] > 0)
		{
			printf("房屋类型 %d 租赁了 %d 次，占比为 %f\n", i, count[i], (double)count[i] / nonZeroCount);
		}
	}
}

int main()
{
	initialize();
	designer();

	int menu_0 = 0;
	scanf("%d", &menu_0);
	//下面的代码完全可以用switch case来简便使用hhhhh
	if (menu_0 == 1)
	{
		system("cls");//清屏，如果不需要可以将本行代码注释掉
		query();
		int query_0 = 0;
		scanf("%d", &query_0);
		if (query_0 == 1)
		{
			system("cls");
			int code_input = 0;
			printf("请输入房屋编号:");
			scanf("%d", &code_input);
			for (size_t i = 0; i < 1000; i++)
			{
				if (rented[i].code == code_input)
				{
					printf("%s", rented[i].name);
				}
			}
		}
		else if (query_0 == 2)
		{
			system("cls");
			int type_input = 0;
			printf("请输入房屋类型（编号）:");
			scanf("%d", &type_input);
			for (size_t i = 0; i < 1000; i++)
			{
				if (rented[i].house_type == type_input)
				{
					printf("%s\n", rented[i].name);
				}
			}
		}
	}
	else if (menu_0 == 2)
	{
		system("cls");
		typeq();
		int typeqn = 0;
		scanf("%d", &typeqn);
		if (typeqn == 1)
		{
			size_t numRent = sizeof(rented) / sizeof(rented[0]);
			qsort(rented, numRent, sizeof(struct rent_house), compareHouseCode);

			for (size_t i = 0; i < numRent; i++)
			{
				if (rented[i].code != 0)
				{
					printf("Name: %s, Code: %d, house_type: %d, Price: %d\n", rented[i].name, rented[i].code, rented[i].house_type, rented[i].price);
				}
			}
		}
		else if (typeqn == 2)
		{
			
			system("cls");
			upOrDown();
			int choser = 0;
			scanf("%d", &choser);
			if (choser == 1)
			{
				size_t numRent = sizeof(rented) / sizeof(rented[0]);
				qsort(rented, numRent, sizeof(struct rent_house), compareHousePriceUp);//排序
				for (size_t i = 0; i < numRent; i++)
				{
					if (rented[i].code != 0)
					{
						printf("Name: %s, Code: %d, house_type: %d, Price: %d\n", rented[i].name, rented[i].code, rented[i].house_type, rented[i].price);
					}
				}
			}
			else if(choser == 2)
			{
				size_t numRent = sizeof(rented) / sizeof(rented[0]);
				qsort(rented, numRent, sizeof(struct rent_house), compareHousePriceDown);
				for (size_t i = 0; i < numRent; i++)
				{
					if (rented[i].code != 0)
					{
						printf("Name: %s, Code: %d, house_type: %d, Price: %d\n", rented[i].name, rented[i].code, rented[i].house_type, rented[i].price);
					}
				}
			}
		}
	}
	else if (menu_0 == 3)
	{
		int fw_count[40];
		for (size_t i = 0; i < 40; i++)
		{
			fw_count[i] = rented[i].house_type;
		}
		//for (size_t i = 0; i < 40; i++)
		//{
		//	printf("%d ", fw_count[i]);
		//}
		int n = sizeof(fw_count) / sizeof(fw_count[0]);
		countElements(fw_count, n);
	}
	return 0;
}