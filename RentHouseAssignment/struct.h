#pragma once//��֤ͷ�ļ�ֻ������һ��
//�ṹ������
typedef struct rent_house
{
	int code;
	char location[100];
	int house_type;//1-6�ֱ��Ӧ��ͬ�ķ������
	int price;
	int is_rent;
	int time;//8λ��������20020202Ϊ2002��2��2��
	char name[50];
	long int number;
};