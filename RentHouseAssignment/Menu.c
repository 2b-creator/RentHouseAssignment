/*界面的绘制，应该不难吧
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

void designer()
{
	//要写学号啥的个人信息这里写printf()
	printf("****************************************\n");
	printf("*              主 菜 单                *\n");
	printf("*              1. 查 询                *\n");
	printf("*              2. 排 列                *\n");
	printf("*              3. 统 计                *\n");
	printf("****************************************\n");
}

void query()
{
	printf("****************************************\n");
	printf("*           1.按房屋编号查询           *\n");
	printf("*           2.按房屋类型查询           *\n");
	printf("****************************************\n");
}

void typeq()
{
	printf("****************************************\n");
	printf("*           1.按房屋编号排序           *\n");
	printf("*           2.按房屋价格排序           *\n");
	printf("****************************************\n");
}

void upOrDown()
{
	printf("****************************************\n");
	printf("*           1.升          序           *\n");
	printf("*           2.降          序           *\n");
	printf("****************************************\n");
}