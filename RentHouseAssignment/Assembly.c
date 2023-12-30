/*Assembly�����������õĺ�������func.h������
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#define _CRT_SECURE_NO_WARNINGS
��Щ����ʹ��Visual Studio���µĺ���֢����һ���Dev C++��gcc����Ļ���Щ����ҪҲû��ϵ
*/

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

char* replaceCommaWithSpace(char* str)//������תΪ�ո񣬷���sscanf()
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

void processString(char* input)//��csv��ʽ�ļ���������replaceCommaWithSpace()
{
	char modifiedString[100];

	// Copy the input string to a new buffer
	strncpy(modifiedString, input, sizeof(modifiedString) - 1);
	modifiedString[sizeof(modifiedString) - 1] = '\0';  // Ensure null-termination

	// Replace commas with spaces
	replaceCommaWithSpace(modifiedString);

	printf("String with commas replaced by spaces: %s\n", modifiedString);
}

void bubbleSort(int arr[], int n)//ð�������㷨
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			// �����ǰԪ�ش�����һ��Ԫ�أ��򽻻�����
			if (arr[j] > arr[j + 1]) 
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void reverseArray(int arr[], int size)//��������
{
	int start = 0;
	int end = size - 1;

	while (start < end)
	{
		// �������������Ԫ��
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;

		// �ƶ�ָ���Լ�����������Ĺ���
		start++;
		end--;
	}
}

// �ȽϺ���������qsort
int compareHousePriceDown(const void* a, const void* b)//qsort��������������ָ�룬��������
{
	return ((struct rent_house*)b)->price - ((struct rent_house*)a)->price;
}

int compareHousePriceUp(const void* a, const void* b)//qsort��������������ָ�룬��������
{
	return ((struct rent_house*)a)->price - ((struct rent_house*)b)->price;
}

int compareHouseCode(const void* a, const void* b)//qsort��������������ָ�룬�������У�codeΪ��������
{
	return ((struct rent_house*)a)->code - ((struct rent_house*)b)->code;
}

int countNonZeroElements(int array[], int size)//ͳ��0������ȥ�������ڵĿռ�
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