#pragma once//保证头文件只被编译一次
//结构体声明
typedef struct rent_house
{
	int code;
	char location[100];
	int house_type;//1-6分别对应不同的房屋类别
	int price;
	int is_rent;
	int time;//8位计数例如20020202为2002年2月2日
	char name[50];
	long int number;
};