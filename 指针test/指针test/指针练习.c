#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//���磺2 + 22 + 222 + 2222 + 22222
//������������ɣ���һ���ֻ���������ֵ�ÿһ�����֣��ڶ��������ǽ�ȡ�õ��������������Զ��������������ֱ���ɸ�������
int main(){
	printf("������һ��1~9֮���������\n");
	int a;
	scanf("%d", &a);
	int Sn = 0;
	int i;
	int temp = 0;
	for (i = 0; i < 5; i++){
		Sn = Sn + a*pow(10, i);    //ȡ��ÿһ����
		temp = temp + Sn;        //���Ѿ�ȡ�������ĺ������
	}
	printf("%d\n", temp);
	system("pause");
	return 0;
}