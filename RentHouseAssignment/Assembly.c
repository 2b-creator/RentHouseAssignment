/*Assembly是整个程序集用的函数，在func.h内声明
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#define _CRT_SECURE_NO_WARNINGS
这些都是使用Visual Studio留下的后遗症，在一般的Dev C++或gcc编译的话这些不需要也没关系
*/

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

char* replaceCommaWithSpace(char* str)//将逗号转为空格，方便sscanf()
{
	int length = strlen(str);
	char* modifiedString = (char*)malloc((length + 1) * sizeof(char));

	if (modifiedString == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	strcpy(modifiedString, str);

	for (int i = 0; i < length; i++)
	{
		if (modifiedString[i] == ',')
		{
			modifiedString[i] = ' ';
		}
	}

	return modifiedString;
}

void processString(char* input)//对csv格式文件处理，调用replaceCommaWithSpace()
{
	char modifiedString[100];

	// Copy the input string to a new buffer
	strncpy(modifiedString, input, sizeof(modifiedString) - 1);
	modifiedString[sizeof(modifiedString) - 1] = '\0';  // Ensure null-termination

	// Replace commas with spaces
	replaceCommaWithSpace(modifiedString);

	printf("String with commas replaced by spaces: %s\n", modifiedString);
}

void bubbleSort(int arr[], int n)//冒泡排序算法
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			// 如果当前元素大于下一个元素，则交换它们
			if (arr[j] > arr[j + 1]) 
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void reverseArray(int arr[], int size)//反向排列
{
	int start = 0;
	int end = size - 1;

	while (start < end)
	{
		// 交换数组的两个元素
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		// 移动指针以继续反向数组的过程
		start++;
		end--;
	}
}

// 比较函数，用于qsort
int compareHousePriceDown(const void* a, const void* b)//qsort函数的逆向链表指针，升序排列
{
	return ((struct rent_house*)b)->price - ((struct rent_house*)a)->price;
}

int compareHousePriceUp(const void* a, const void* b)//qsort函数的正向链表指针，升序排列
{
	return ((struct rent_house*)a)->price - ((struct rent_house*)b)->price;
}

int compareHouseCode(const void* a, const void* b)//qsort函数的正向链表指针，升序排列，code为排序因子
{
	return ((struct rent_house*)a)->code - ((struct rent_house*)b)->code;
}

int countNonZeroElements(int array[], int size)//统计0个数，去除数组内的空集
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] != 0)
		{
			count++;
		}
	}

	return count;
}