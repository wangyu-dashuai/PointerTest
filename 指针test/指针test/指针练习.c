#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//例如：2 + 22 + 222 + 2222 + 22222
//分两部分来完成，第一部分获得这类数字的每一个数字，第二部分则是将取得的数加起来，所以定义两个变量来分别完成各个部分
int main(){
	printf("请输入一个1~9之间的整数：\n");
	int a;
	scanf("%d", &a);
	int Sn = 0;
	int i;
	int temp = 0;
	for (i = 0; i < 5; i++){
		Sn = Sn + a*pow(10, i);    //取得每一个数
		temp = temp + Sn;        //将已经取过的数的和算出来
	}
	printf("%d\n", temp);
	system("pause");
	return 0;
}