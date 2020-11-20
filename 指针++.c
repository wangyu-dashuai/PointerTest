#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a[5][5];
	int(*p)[4];

	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	return 0;
}

/*
int main()
{
int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//int a[3][2] = { {0, 1}, {2, 3}, {4, 5} };
int *p;
p = a[0];
printf("%d", p[0]);
return 0;
}
/*
int main()
{
int a[4] = { 1, 2, 3, 4 };
int *ptr1 = (int *)(&a + 1);
int *ptr2 = (int *)((int)a + 1);
printf("%x,%x", ptr1[-1], *ptr2);
return 0;
}
/*
//20
struct Test
{
int Num;
char *pcName;
short sDate;
char cha[2];
short sBa[4];
};
//假设p 的值为0x100000。 如下表表达式的值分别为多少？
int main()
{
struct Test *p = (struct Test*)0x100000;
printf("%p\n", p + 0x1); //0x100014;
printf("%p\n", (unsigned long)p + 0x1); //0x100001;
printf("%p\n", (unsigned int*)p + 0x1); //0x100004;
return 0;
}
/*
int main()
{
int a[5] = { 1, 2, 3, 4, 5 };
int *ptr = (int *)(&a + 1);
printf("%d,%d", *(a + 1), *(ptr - 1));
return 0;
}
/*
int main()
{
int a[3][4] = { 0 };
printf("%d\n", sizeof(a));      //48
printf("%d\n", sizeof(a[0][0]));//4
printf("%d\n", sizeof(a[0]));   //16
printf("%d\n", sizeof(a[0] + 1)); //4
printf("%d\n", sizeof(*(a[0] + 1))); //4
printf("%d\n", sizeof(a + 1));  //4
printf("%d\n", sizeof(*(a + 1))); //16
printf("%d\n", sizeof(&a[0] + 1)); //4
printf("%d\n", sizeof(*(&a[0] + 1))); //16
printf("%d\n", sizeof(*a));//16
printf("%d\n", sizeof(a[3])); //16
}
/*
void main()
{
char *p = "abcdef";
printf("%d\n", sizeof(p));   //4
printf("%d\n", sizeof(p + 1));//4
printf("%d\n", sizeof(*p));   //1
printf("%d\n", sizeof(p[0]));//1
printf("%d\n", sizeof(&p));  //4
printf("%d\n", sizeof(&p + 1)); //4
printf("%d\n", sizeof(&p[0] + 1));//4
printf("%d\n", strlen(p));   //6
printf("%d\n", strlen(p + 1));//5
//printf("%d\n", strlen(*p));  //
//printf("%d\n", strlen(p[0]));
printf("%d\n", strlen(&p));   //?
printf("%d\n", strlen(&p + 1));//?
printf("%d\n", strlen(&p[0] + 1));//5
}
/*
void main()
{
char arr[] = "abcdef";
printf("%d\n", sizeof(arr));     //7
printf("%d\n", sizeof(arr + 0)); //4
printf("%d\n", sizeof(*arr));    //1
printf("%d\n", sizeof(arr[1]));  //1
printf("%d\n", sizeof(&arr));    //4
printf("%d\n", sizeof(&arr + 1));//4
printf("%d\n", sizeof(&arr[0] + 1)); //4
printf("%d\n", strlen(arr));     //6
printf("%d\n", strlen(arr + 0)); //6
//printf("%d\n", strlen(*arr));    //
//printf("%d\n", strlen(arr[1]));
printf("%d\n", strlen(&arr));    //6
printf("%d\n", strlen(&arr + 1));//?
printf("%d\n", strlen(&arr[0] + 1));//5
}
/*
void main()
{
char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
printf("%d\n", sizeof(arr));      //6
printf("%d\n", sizeof(arr + 0));  //4
printf("%d\n", sizeof(*arr));     //1
printf("%d\n", sizeof(arr[1]));   //1
printf("%d\n", sizeof(&arr));     //4
printf("%d\n", sizeof(&arr + 1)); //4
printf("%d\n", sizeof(&arr[0] + 1));//4

printf("%d\n", strlen(arr));      //?
printf("%d\n", strlen(arr + 0));  //?
//printf("%d\n", strlen(*arr));     //x
//printf("%d\n", strlen(arr[1]));   //x
printf("%d\n", strlen(&arr));     //?
printf("%d\n", strlen(&arr + 1)); //?
printf("%d\n", strlen(&arr[0] + 1));//?
}
/*
void main()
{
int a[] = { 1, 2, 3, 4 };
printf("%d\n", sizeof(a));      //16
printf("%d\n", sizeof(a + 0));  //4
printf("%d\n", sizeof(*a));     //4
printf("%d\n", sizeof(a + 1));  //4
printf("%d\n", sizeof(a[1]));   //4
printf("%d\n", sizeof(&a));     //4
printf("%d\n", sizeof(*&a));    //16   *&a
printf("%d\n", sizeof(&a + 1)); //4
printf("%d\n", sizeof(&a[0]));  //4
printf("%d\n", sizeof(&a[0] + 1)); //4
}
/*
void PrintAr(int ar[], int n)
{
for(int i=0; i<n; ++i)
{
printf("%d ", ar[i]);
}
printf("\n");
}
int comp_int(const void *a, const void *b)
{
return (*(int*)a) - (*(int*)b);
}
void _swap(void *p1, void * p2, int size)
{
int i = 0;
for (i = 0; i < size; i++)
{
char tmp = *((char *)p1 + i);
*((char *)p1 + i) = *((char *)p2 + i);
*((char *)p2 + i) = tmp;
}
}
void my_qsort( void *base, size_t num,
size_t size,
int ( *compare )(const void *elem1, const void *elem2 ) )
{
for (int i = 0; i < num - 1; i++)
{
for (int j = 0; j<num - i - 1; j++)
{
//if(ar[j] > ar[j+1])
if (compare((char *)base + j*size, (char *)base + (j + 1)*size) > 0)
{
_swap((char *)base + j*size, (char *)base + (j + 1)*size, size);
}
}
}
}
int main()
{
int ar[] = {5,8,9,2,3,1,0,4};
int n = sizeof(ar) / sizeof(ar[0]);
PrintAr(ar, n);
my_qsort(ar, n, sizeof(int), comp_int);
PrintAr(ar, n);
}
/*
int comp_int(const void *a, const void *b)
{
const int *pa = (const int*)a;
const int *pb = (const int*)b;
return (*pa - *pb);  //>0 ==0 <0
//return (*(int*)a) - (*(int*)b);
}
int comp_str(const void *a, const void *b)
{
const char **sa = (const char **)a;
const char **sb = (const char **)b;
return strcmp(*sa, *sb);
}
typedef struct Student
{
int id;
char name[10];
char sex;
int age;
}Student;
int comp_stu(const void *a, const void *b)
{
Student *pa = (Student *)a;
Student *pb = (Student *)b;
return (pa->id - pb->id);
}
void main()
{
Student stu[] = {{2000, "附近阿里", "男", 20},
{1000, "婕拉","女", 18},
{3000, "解放啦","女",22}};
qsort(stu, 3, sizeof(Student), comp_stu);
}
/*
int main()
{
char* str[] = {"xyz","lmn", "kfc", "ufe", "abc", "opq"};
int n = sizeof(str) / sizeof(str[0]);
qsort(str, n, sizeof(char*), comp_str);
}
/*
#define ROW 3
#define COL 5
void test(int **ar)
{
int i, j;
int(*par)[COL] = ar;
for(i=0; i<ROW; ++i)
{
for(j=0; j<COL; ++j)
{
printf("%d ", par[i][j]);
}
printf("\n");
}
}
void main()
{
int ar[ROW][COL] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
test(ar);
}
/*
void PrintAr(int ar[], int n)
{
for(int i=0; i<n; ++i)
{
printf("%d ", ar[i]);
}
printf("\n");
}
//void qsort( void *base, size_t num,
//            size_t width,
//            int ( *compare )(const void *elem1, const void *elem2 ) );
int comp_int(const void *a, const void *b)
{
const int *pa = (const int*)a;
const int *pb = (const int*)b;
return (*pa - *pb);  //>0 ==0 <0
//return (*(int*)a) - (*(int*)b);
}
int comp_str(const void *a, const void *b)
{
const char **sa = (const char **)a;
const char **sb = (const char **)b;
return strcmp(*sa, *sb);
}
int main()
{
char* str[] = {"xyz","lmn", "kfc", "ufe", "abc", "opq"};
int n = sizeof(str) / sizeof(str[0]);
qsort(str, n, sizeof(char*), comp_str);
}
/*
int main()
{
int ar[] = {5,8,9,2,3,1,0,4};
int n = sizeof(ar) / sizeof(ar[0]);
PrintAr(ar, n);
qsort(ar, n, sizeof(int), comp_int);
PrintAr(ar, n);
}
/*
int main()
{
int a = 10;
void *pv = &a;
//*pv;
int *pi = (int*)pv;
}
/*
int main()
{
int a = 10;
int *pc = &a;
double d = 12.34;
double *pi = &d;
void *pv = &a;
pv = &d;
void *z;  //无  泛型指针
}
/*
void PrintAr(int ar[], int n)
{
for(int i=0; i<n; ++i)
{
printf("%d ", ar[i]);
}
printf("\n");
}
void Sort(int ar[], int n)
{
for(int i=0; i<n-1; ++i)
{
for(int j=0; j<n-i-1; ++j)
{
if(ar[j] > ar[j+1])
{
int tmp = ar[j];
ar[j] = ar[j+1];
ar[j+1] = tmp;
}
}
}
}
//void qsort( void *base, size_t num,
//            size_t width,
//            int ( *compare )(const void *elem1, const void *elem2 ) );
int comp_int()
int main()
{
int ar[] = {5,8,9,2,3,1,0,4};
int n = sizeof(ar) / sizeof(ar[0]);
PrintAr(ar, n);
//Sort(ar, n);
qsort(ar, n, sizeof(int), );
PrintAr(ar, n);
}
/*
int Find_Max(int ar[], int n)
{
int max_value = ar[0];
for(int i=1; i<n; ++i)
{
if(max_value < ar[i])
max_value = ar[i];
}
return max_value;
}
int Find_Min(int ar[], int n)
{
int min_value = ar[0];
for(int i=1; i<n; ++i)
{
if(min_value > ar[i])
min_value = ar[i];
}
return min_value;
}
/////////////////////////////////////////////////
int Find(int ar[], int n, int(*pfun)(int ar[], int n)) //通用
{
return pfun(ar, n); //
}
int main()
{
int ar[] = {5,8,9,2,3,1,0,4};
int n = sizeof(ar) / sizeof(ar[0]);
//printf("max_value = %d\n", Find_Max(ar, n));
//printf("min_value = %d\n", Find_Min(ar, n));
printf("max_value = %d\n", Find(ar, n, Find_Min));
//printf("min_value = %d\n", Find_Min(ar, n));
}
/*
int main()
{
(*(void (*)())0)();
}
/*
int fun(int a, int b)
{
return  a + b;
}
void main()
{
int(*pfun)(int, int) = &fun;
(*pfun)(10,20);
}
/*
int main()
{
int *pa = NULL;
*pa = 10;
//char *str = "Hello";
}
/*
int fun(int a, int b)
{
return  a + b;
}
int* fun1(int a, int b)  //指针函数
{
static int v = 0;
v = a + b;
return &v;
}
int main()
{
int ar[3] = {10, 20, 30};
int(*pa)[3] = &ar;  //数组指针
int a = 10;
int b = 20;
int c = 30;
int* br[3] = {&a, &b, &c}; //指针数组
int(*pfun)(int, int) = &fun; //函数指针
}
/*
void main()
{
int *pa = NULL;
char *str = "Hello";
}
*/