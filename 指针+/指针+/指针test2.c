#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#define IO 996
#define N 10
#define input "%d,%d,%d,%d\n\n"

//void product();
//void sortReplication();
//void sort();
//void swap(int *, int);
//void exchange();
//void frequency();
//int subString(char *, char *);

int product(){
	//��֪һ����������X[4]����Ԫ��ֵ�ֱ�Ϊ3/10/4/20��ʹ��ָ���������Ԫ�صĻ���
	int x[] = { 3, 10, 4, 20 }, i, product = 1, *xp = &x[0];
	for (i = 0; i<4; i++){
		product *= *(xp + i);//*xp+i
		//printf("%d\n",i);
		//printf("%d\n",*xp);
		//printf("%d\n",*xp+i);
		//printf("%d\n\n",product);
	}
	system("pause");
	printf("%d\n\n", product);
}


int sortReplication(){

	//���ĸ��ַ�����ʵ�ֽ����ǰ����ַ����е��ַ�������С��������
	//�ٷֱ�ȡ��ÿ���ַ����ĵ�������ĸ�γ�һ���µ��ַ�������������������ַ������*����
	//Ҫ�������ַ���ָ���ָ��������ɡ�

	char *array[5] = { "yangmufa", "shuai", "de", "chaojishuai", }\
		, (*tem) = NULL, t[5] = { NULL };
	int i = 0, j = 0, k = 0;

	for (i = 0; i<4; i++){//i<4-1��ʾ�ӵ�һ����ʼ�������ڶ�������(4������)
		k = i;//��¼С��
		for (j = 0; j<4; j++){//��ʾ�ӵڶ�����ʼ��������һ��������ÿһ�α���һ�αȽϴ�����һ	
			if (strlen(array[k])>strlen(array[j])){
				k = j;//��¼С��
			}
			if (i != k){//����
				tem = array[i];
				array[i] = array[k];
				array[k] = tem;
			}
		}
	}
	//�ֱ�ȡ��ÿ���ַ����ĵ�������ĸ�γ�һ���µ��ַ���
	for (i = 0; i<4; i++){
		puts(*(array + i));
		if (strlen(*(array + i))>2){
			//*(*(array+4)+i)=*(*(array+1)+2);
			//�˷�������ȡ��Ϊ"String"�Ǵ��ھ�̬�洢���ģ������ַ�е�ֵ���ܱ��޸ġ�
			t[i] = *(*(array + i) + 2);
		}
		else if (strlen(*(array + i))<3){
			t[i] = '*';
		}
	}
	system("pause");
	printf("\n���ַ���:%s\n\n", t);
}


int sort(){

	//����һ����̬���鳤��Ϊn�����������������Ԫ�ظ�ֵ��
	//Ȼ����������Ԫ���򣬶���swap�����������ݵ�Ԫ��Ҫ�����ʹ��ָ�봫�ݡ�

	int n, i, *array;
	printf("���볤�ȣ�");
	scanf_s("%d", &n);
	array = (int*)malloc(n*sizeof(int));//��NΪ������̬����N��int���ʹ�С���ڴ�
	srand((unsigned)time(NULL));//������ʱ��Ϊ�������
	printf("���������ǰ��");
	for (i = 0; i<n; i++){
		array[i] = rand();//��ȡ��ʱ��Ϊ���ӵ������������ֵ��array
		printf(" %d ", array[i]);
	}
	system("pause");
	printf("\n");
	swap(array, n);
}
int swap(int * array, int lenth){
	int i = 0, j = 0, k = 0, temp;
	printf("\n����������");
	for (i; i<lenth; i++){
		k = i;
		for (j = 0; j<lenth; j++){
			if (array[k]<array[j]){ k = j; }
			if (k != i){
				temp = array[k];
				array[k] = array[i];
				array[i] = temp;
			}
		}
	}
	for (i = 0; i<lenth; i++){
		printf(" %d ", array[i]);
	}
	system("pause");
	printf("\n\n");
}


int exchange(){

	//����N����������������С�������һ�����Ի�������������������������������

	int array[8], i, j, k, temp = 0, max = 0, min = 0;
	srand((unsigned)time(NULL));//����ʱ������
	printf("�����:");
	for (i = 0; i<8; i++){
		array[i] = rand();//��ȡ��ʱ��Ϊ���ӵ������������ֵ��array
		printf(" %d ", array[i]);
		system("pause");
	}

	printf("\n������:");
	max = array[0];
	min = array[0];
	for (i = 0; i<8 - 1; i++){
		if (max<array[i]){
			max = array[i];
		}//������Ԫ��
		if (min>array[i]){
			min = array[i];
		}//�����СԪ��
	}
	array[0] = min;//��������С�������һ�����Ի���
	array[7] = max;//����������������������������
	for (i = 0; i<8; i++){
		printf(" %d ", array[i]);
	}
	for (i = 0; i<8; i++){
		k = i;
		for (j = 0; j<8; j++){
			if (array[k]<array[j]){ k = j; }
			if (k != i){
				temp = array[k];
				array[k] = array[i];
				array[i] = temp;
			}
		}
	}
	printf("\n�����:");
	for (i = 0; i<8; i++){
		printf(" %d ", array[i]);
	}
	system("pause");
	printf("\nmax:%d\nmin:%d\n", max, min);
}



int frequency(){

	//�����ַ������Ӵ����ֵĴ�����Ҫ����һ��subString����ʵ�֣�
	//����Ϊָ���ַ��������ַ�����ָ�룬���ش�����

	char array[] = { "yangmufchaojiwudidashuaigeyangmufachaojishuai" }, \
		SubString[] = { "chaoji" };
	printf("�ַ�����");
	puts(SubString);
	printf("���ַ�����");
	puts(array);
	printf("�г����ˣ� ");
	system("pause");
	printf(" %d ��\n", subString(array, SubString));
}
int subString(char *a, char *s){

	int i = 0, j = 0, count = 0, alen = strlen(a), slen = strlen(s);
	while (i<alen){
		if (a[i] == s[j]){
			//����Ӵ���j��Ԫ�غ�ĸ���ĵ�i��Ԫ������򶼼���ָ����һ��Ԫ�ؽ��бȽ�
			i++;
			j++;
		}
		else{
			//����Ӵ���ĸ�����ֲ�ƥ����ĸ���ص����ֱȽ�֮ǰ���Ӵ�����
			i = i - j + 1;
			j = 0;
		}
		if (j == slen){
			//��������Ӵ������һ��Ԫ�ؾ���ĸ����ȵ��������ִ�����һ���Ӵ����������һ�ֱȽϡ�
			count++;
			j = 0;
		}
	}
	system("pause");
	return count;
}

int main(int argc, char *argv[]){

	product();
	sortReplication();
	sort(5);
	exchange();
	frequency();
	system("pause");
}