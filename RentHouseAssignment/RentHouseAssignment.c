/*����ı����ļ�����Ҫ�ļ�
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

#define _CRT_SECURE_NO_WARNINGS
��Щ����ʹ��Visual Studio���µĺ���֢����һ���Dev C++��gcc����Ļ���Щ����ҪҲû��ϵ

#pragma warning(disable : 4996)��#pragma warning(disable : 6031)�Ƿ�ֹscanfĪ����vs�ڱ�warning��
�����е�ǿ��֢�����Լ���һ��

#define _CRT_SECURE_NO_WARNINGS�Ǳ�֤vs�ܹ���������scanf����ΪҪʹ��vsĬ����Ϊscanf����ȫ����scanf_s������������һ����ͨ��
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

int initialize()//��ʼ�������ļ��Ĳ���
{
	FILE* fp = fopen("rent.csv", "r");//�����ļ�ָ�룬��ֻ����ʽ��
	int i = 0;
	if (fp == NULL)//�ж��ļ��Ƿ�����
	{
		fprintf(stderr, "test for fopen() failed.\n");
		exit(EXIT_FAILURE);
	}
	while (!feof(fp))//���м�飬ֱ��EOF
	{
		char ssss[4000];//ssss�����棬������˼��Ҫ��replaceCommaWithSpace()�����ı�ʹ�õ��ַ�����
		fscanf(fp, "%s\n", ssss);
		//fscanf(fp, "%s,%d,%s,%d,%d,%d,%s,%s,%l32d\n", &rented[i].name, &rented[i].code, &rented[i].location, &rented[i].house_type, &rented[i].price, &rented[i].is_rent, &rented[i].time, &rented[i].number);
		//����һ��ע����ʧ��Ʒ�������ΪʲôҪת�ո񣬶��߿������г��Դ����ŵ�ɨ������
		char* inputString = ssss;
		char* result = replaceCommaWithSpace(inputString);
		//printf("%s\n", result);
		//����һ�в���ʹ�ã���ȷ��û���⣬����C���ԵĶϵ���ԣ����������Ի����ܳ���
		sscanf(result, "%s %d %s %d %d %d %d %l32d\n", rented[i].name, &rented[i].code, rented[i].location, &rented[i].house_type, &rented[i].price, &rented[i].is_rent, &rented[i].time, &rented[i].number);
		i++;
	}
	/*for (size_t i = 0; i < 40; i++) {
		printf("Name: %s, Code: %d, house_type: %d, Price: %d\n", rented[i].name, rented[i].code, rented[i].house_type, rented[i].price);
	}*/
	return 0;
}

void countElements(int arr[], int n)//ͳ�������и���Ԫ�صĸ������������ռ��
{
	// ����һ���µ��������ڴ洢��Ԫ�صĸ���
	int count[100] = { 0 }; // ��������Ԫ�ص�ȡֵ��Χ��0��99֮��

	// ͳ�Ƹ�Ԫ�صĸ���
	for (int i = 0; i < n; ++i)
	{
		count[arr[i]]++;
	}

	int nonZeroCount = countNonZeroElements(arr, n);

	// ������
	for (int i = 1; i < 100; ++i)
	{
		if (count[i] > 0)
		{
			printf("�������� %d ������ %d �Σ�ռ��Ϊ %f\n", i, count[i], (double)count[i] / nonZeroCount);
		}
	}
}

int main()
{
	initialize();
	designer();

	int menu_0 = 0;
	scanf("%d", &menu_0);
	//����Ĵ�����ȫ������switch case�����ʹ��hhhhh
	if (menu_0 == 1)
	{
		system("cls");//�������������Ҫ���Խ����д���ע�͵�
		query();
		int query_0 = 0;
		scanf("%d", &query_0);
		if (query_0 == 1)
		{
			system("cls");
			int code_input = 0;
			printf("�����뷿�ݱ��:");
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
			printf("�����뷿�����ͣ���ţ�:");
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
				qsort(rented, numRent, sizeof(struct rent_house), compareHousePriceUp);//����
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