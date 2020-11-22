//基本数据类型有一个对齐值
//自定义类型有一个对齐值
//程序指定对齐值
//程序有效对齐值

typedef struct Test
{
	short a;
	struct
	{
		int b;
		double c;
		long d;
	};
	int e;
}Test;

void main()
{
	printf("size = %d\n", sizeof(Test));
}

/*
#pragma pack(8)
typedef struct Test
{
char a;    //1 + 3
int c;     //4
double b;  //8
}Test;
void main()
{
printf("size = %d\n", sizeof(Test));
Test t;
t.a = 'A';
t.b = 12.34;
t.c = 100;
}
/*
typedef struct Test
{
char a;    //1 + 7
double b;  //8
int c;     //4 + 4
}Test;
void main()
{
printf("size = %d\n", sizeof(Test));
Test t;
t.a = 'A';
t.b = 12.34;
t.c = 100;
}
/*
struct
{
int a;
double b;
struct Test *t;
};
void main()
{
}
/*
struct
{
int a;
char b;
float c;
}x;
struct
{
int a;
char b;
float c;
}*p;
void main()
{
p = &x;
}
/*
typedef struct Test
{
char a;
double b;
int c;
}Test;
void main()
{
Test t;
}
/*
int main()
{
int n = 9;
float *pFloat = (float *)&n;
printf("n的值为：%d\n", n);   //9
//0 000 0000 0 000 0000 0000 0000 0000 1001
//s    e       m
//0    -126    0.000 0000 0000 0000 0000 1001
printf("*pFloat的值为：%f\n", *pFloat);
*pFloat = 9.0;  //1001.0 => (-1)^0 * 1.001 * 2^3
//0     100 0001 0      001 0000 0000 0000 0000 0000
//0100 0001 0001 0000 0000 0000 0000 0000
//  4   1     1   0    0    0     0    0
printf("num的值为：%d\n", n); //
printf("*pFloat的值为：%f\n", *pFloat);
return 0;
}
/*
void main()
{
float f = 10.125;  //1010.001  (-1)^s * m *2^e
//1.010001  (-1)^s *
float f1 = 12.5;
}
/*
int main()
{
int n = 9;
float *pFloat = (float *)&n;
printf("n的值为：%d\n", n);   //9
printf("*pFloat的值为：%f\n", *pFloat);
*pFloat = 9.0;
printf("num的值为：%d\n", n);
printf("*pFloat的值为：%f\n", *pFloat);
return 0;
}
/*
unsigned char i = 0; //0 ~ 255
int main()
{
for (i = 0; i <= 255; i++)
{
printf("hello world\n");
}
return 0;
}
/*
int main()
{
char a[1000];
int i;
for (i = 0; i < 1000; i++)
{
a[i] = -1 - i; //-1 -2 ..........-128 127 126 .......1 0
}
printf("%d", strlen(a));
return 0;
}
/*
void main()
{
unsigned int i;
for (i = 9; i >= 0; i--)
{
printf("%u\n", i); //9 8 7 6 5 4 3 2 1 0
}
}
/*
void main()
{
int i = -20;
//1111 1111 1111 1111 1111 1111 1110 1100
unsigned int j = 10;
//0000 0000 0000 0000 0000 0000 0000 1010
//1111 1111 1111 1111 1111 1111 1111 0110
//1111 1111 1111 1111 1111 1111 1111 0101
//1000 0000 0000 0000 0000 0000 0000 1010
printf("%u\n", i + j); //-10
}
/*
int main()
{
char a = 128;  //-128
printf("%u\n", a);
return 0;
}
/*
int main()
{
char a = -128; // 1000 0000
// 1000 0000 0000 0000 0000 0000 1000 0000
// 1111 1111 1111 1111 1111 1111 0111 1111
// 1111 1111 1111 1111 1111 1111 1000 0000
printf("%d\n", a); //128
return 0;
}
/*
int main()
{
char a = -1;
signed char b = -1;
unsigned char c = -1;   //1000 0001
//1111 1110
//1111 1111 FF
printf("a=%d,b=%d,c=%d\n", a, b, c);
return 0;
}
/*
void main()
{
union
{
short k;
char i[2];
}*s, a;
s = &a;
s->i[0] = 0x39;
s->i[1] = 0x38;
printf("%x\n", a.k); //
}
/*
bool check_mode()
{
union
{
int i;
char ch;
}un;
un.i = 1; //00 00 00 01
return un.ch == 1;
}
void main()
{
bool flag = check_mode();
if(flag)
printf("This is little.\n");
else
printf("This is big.\n");
}
/*
void main()
{
union
{
short k;
char i[2];
}*s, a;
s = &a;
s->i[0] = 0x39;
s->i[1] = 0x38;
printf("%x\n", a.k);
}
/*
bool check_mode()
{
int a = 1;
return (*(char*)&a) == 1;
}
void main()
{
bool flag = check_mode();
if(flag)
printf("This is little.\n");
else
printf("This is big.\n");
}
/*
//人看
void main()
{
int a = -10;
//1000 0000 0000 0000 0000 0000 0000 1010 原
//1111 1111 1111 1111 1111 1111 1111 0101 反
//1111 1111 1111 1111 1111 1111 1111 0110 补
// F    F    F    F    F     F   F    6
printf("%d\n", a); //
}
/*
void main()
{
//char ch = 4791491;
char ch = 195;
printf("%d\n", ch);  //-128 ~ 127
}
/*
void main()
{
long long a = 100;
printf("size = %d\n", sizeof(long long));
long long b = 200;
}
/*
//  0  1 2
// dir a b
//xx.exe op1 op2
//Linux
int main(int argc, char *argv[])
{
if(argc != 3)
{
printf("argument error.\n");
return;
}
int result = atoi(argv[1]) + atoi(argv[2]);
printf("%d + %d = %d\n", atoi(argv[1]), atoi(argv[2]), result);
return 0;
}
/*
void main(int argc, char *argv[])
{
//int result = atoi(argv[1]) + atoi(argv[2]);
char *str = "123";
int x = atoi(str);
printf("x = %d\n", x);

}
/*
//命令行参数
//argc argument count
//argv argument value
void main(int argc, char *argv[])
{
printf("argc = %d\n", argc);
for(int i=0; i<argc; ++i)
printf("%s\n", argv[i]);
}
/*