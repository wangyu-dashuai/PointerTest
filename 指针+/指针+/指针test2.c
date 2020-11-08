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
	//已知一个整形数组X[4]，其元素值分别为3/10/4/20，使用指针求个数字元素的积。
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

	//有四个字符串，实现将他们按照字符串中的字符个数从小到大排序，
	//再分别取出每个字符串的第三个字母形成一个新的字符串输出（若少于三个字符的输出*），
	//要求：利用字符串指针和指针数组完成。

	char *array[5] = { "yangmufa", "shuai", "de", "chaojishuai", }\
		, (*tem) = NULL, t[5] = { NULL };
	int i = 0, j = 0, k = 0;

	for (i = 0; i<4; i++){//i<4-1表示从第一个开始到倒数第二个结束(4个数组)
		k = i;//记录小串
		for (j = 0; j<4; j++){//表示从第二个开始到倒数第一个结束，每一次比上一次比较次数减一	
			if (strlen(array[k])>strlen(array[j])){
				k = j;//记录小串
			}
			if (i != k){//交换
				tem = array[i];
				array[i] = array[k];
				array[k] = tem;
			}
		}
	}
	//分别取出每个字符串的第三个字母形成一个新的字符串
	for (i = 0; i<4; i++){
		puts(*(array + i));
		if (strlen(*(array + i))>2){
			//*(*(array+4)+i)=*(*(array+1)+2);
			//此方法不可取因为"String"是存在静态存储区的，这个地址中的值不能被修改。
			t[i] = *(*(array + i) + 2);
		}
		else if (strlen(*(array + i))<3){
			t[i] = '*';
		}
	}
	system("pause");
	printf("\n新字符串:%s\n\n", t);
}


int sort(){

	//定义一个动态数组长度为n，用随机数给各数组元素赋值，
	//然后对数组各单元排序，定义swap函数交换数据单元，要求参数使用指针传递。

	int n, i, *array;
	printf("输入长度：");
	scanf_s("%d", &n);
	array = (int*)malloc(n*sizeof(int));//以N为基数动态反配N个int类型大小的内存
	srand((unsigned)time(NULL));//设置以时间为随机种子
	printf("随机数排序前：");
	for (i = 0; i<n; i++){
		array[i] = rand();//获取以时间为种子得来的随机数后赋值给array
		printf(" %d ", array[i]);
	}
	system("pause");
	printf("\n");
	swap(array, n);
}
int swap(int * array, int lenth){
	int i = 0, j = 0, k = 0, temp;
	printf("\n随机数排序后：");
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

	//输入N个整数，将其中最小的数与第一个数对换，将自重最大的数与与最大的数交换。

	int array[8], i, j, k, temp = 0, max = 0, min = 0;
	srand((unsigned)time(NULL));//设置时间种子
	printf("随机数:");
	for (i = 0; i<8; i++){
		array[i] = rand();//获取以时间为种子得来的随机数后赋值给array
		printf(" %d ", array[i]);
		system("pause");
	}

	printf("\n交换后:");
	max = array[0];
	min = array[0];
	for (i = 0; i<8 - 1; i++){
		if (max<array[i]){
			max = array[i];
		}//求出最大元素
		if (min>array[i]){
			min = array[i];
		}//求出最小元素
	}
	array[0] = min;//将其中最小的数与第一个数对换，
	array[7] = max;//将其中最大的数与与最大的数交换。
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
	printf("\n排序后:");
	for (i = 0; i<8; i++){
		printf(" %d ", array[i]);
	}
	system("pause");
	printf("\nmax:%d\nmin:%d\n", max, min);
}



int frequency(){

	//计算字符串中子串出现的次数，要求用一个subString函数实现，
	//参数为指向字符串和子字符串的指针，返回次数。

	char array[] = { "yangmufchaojiwudidashuaigeyangmufachaojishuai" }, \
		SubString[] = { "chaoji" };
	printf("字符串：");
	puts(SubString);
	printf("在字符串：");
	puts(array);
	printf("中出现了： ");
	system("pause");
	printf(" %d 次\n", subString(array, SubString));
}
int subString(char *a, char *s){

	int i = 0, j = 0, count = 0, alen = strlen(a), slen = strlen(s);
	while (i<alen){
		if (a[i] == s[j]){
			//如果子串第j个元素和母串的第i个元素相等则都继续指向下一个元素进行比较
			i++;
			j++;
		}
		else{
			//如果子串和母串出现不匹配则母串回到挡轮比较之前，子串归零
			i = i - j + 1;
			j = 0;
		}
		if (j == slen){
			//如果出现子串到最后一个元素均与母串相等的情况则出现次数加一，子串归零继续下一轮比较。
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