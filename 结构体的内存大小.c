#include<stdio.h>

union Un1  //4
{
	char c[5];  //5
	int i;      //4
};
union Un2
{
	short c[7];  //14
	int i;       //4
};
void main()
{
	//下面输出的结果是什么？
	printf("%d\n", sizeof(union Un1));
	printf("%d\n", sizeof(union Un2));
}

/*
union Un
{
	int i;
	char c;
};
void main()
{
	union Un un;
	// 下面输出的结果是一样的吗？
	printf("%x\n", &(un.i));
	printf("%x\n", &(un.c));
	//下面输出的结果是什么？
	un.i = 0x11223344;  //44 33 22 11
	un.c = 0x55;        //55 33 22 11
	printf("%x\n", un.i);
}
/*
//自定义类型 struct  enum  union
union Test
{
	int a;
	double b;
	char c;
};
void main()
{
	printf("size = %d\n", sizeof(union Test));
	union Test t;
	t.b = 12.34;
	t.a = 100;
	t.c = 'A';
	printf("%f\n", t.b);
	printf("%d\n", t.a);
}
/*
typedef enum TYPE
{
	ADD, 
	SUM,
	MUL, 
	DIV,
	MOD,
	SQU
}TYPE;
void fun(TYPE ty)
{}
void main()
{
	printf("%d %d %d %d\n", ADD, SUM, MUL, DIV);
	printf("size = %d\n", sizeof(enum TYPE));
	TYPE myt;
	myt = ADD;
	//myt = 60;
}
/*
#define SIZE 10
enum {CAPACITY = 100};
void main()
{
	int n = SIZE; //宏 常量
	int m = CAPACITY;  //枚举 常量
	const int sz = 20; //
}
/*
//1、基本数据类型的自身对齐值：
//2、自定义类型的自身对齐值
//3、程序的指定对齐值
//4、自定义类型的有效对齐值
#pragma pack(4)
struct S
{
	char a : 3;
	char   : 4;
	char b : 1;
	char c : 5;
	char d : 4;
};
#pragma pack()
void main()
{
	struct S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
}
/*
int main()
{
	unsigned char puc[4];
	struct tagPIM
	{
		unsigned char ucPim1;
		unsigned char ucData0 : 1;
		unsigned char ucData1 : 2;
		unsigned char ucData2 : 3;
	}*pstPimData;
	pstPimData = (struct tagPIM*)puc;
	memset(puc, 0, 4);
	pstPimData->ucPim1 = 2;
	pstPimData->ucData0 = 3;
	pstPimData->ucData1 = 4;
	pstPimData->ucData2 = 5;
	printf("%d %d %d %d\n", puc[0], puc[1], puc[2], puc[3]);
	return 0;
}
/*
#pragma pack(4)
struct tagAAA
	{
		unsigned char ucld : 1;
		unsigned char ucPara0 : 2;  //1
		unsigned char ucState : 6;  //1
		unsigned char ucTail : 4;   //1
		unsigned char ucAvail;      //1
		unsigned char ucTail2 : 4;  //1
		unsigned char ucData;       //1
}AAA_S;
void main()
{
	printf("%d\n", sizeof(AAA_S));
}
/*
typedef struct Test
{
	char a : 1;
	int  b : 1;
}Test;
void main()
{
	printf("%d\n", sizeof(Test));
}
/*
//节省空间
typedef struct Test
{
	char a : 1; // 0 1  开关值  位域
	char b : 6; // 0 1
	char c : 3; // 0 1=
}Test;
void main()
{
	printf("%d\n", sizeof(Test));
}
/*
#pragma pack(4)
struct tagAAAA
{
	struct
	{
		char ucFirst;   //1 + 1
		short usSecond; //2
		char ucThird;   //1 + 1
	}half;
	short kk;          //2
}number;
//8
struct tagBBBB
{
	char ucFirst;   //1 + 1
	short usSecond; //2
	char ucThird;   //1 + 1
	short usForth;  //2
}half;
//8
struct tagCCCC
{
	struct
	{
		char ucFirst;  //1 + 1
		short usSecond; //2
		char ucThird;  //1 +1
	}half;
	long kk;           //4 + 2
};
//12
void main()
{
	printf("%d\n", sizeof(struct tagAAAA));
	printf("%d\n", sizeof(struct tagBBBB));
	printf("%d\n", sizeof(struct tagCCCC));
}
/*
#pragma pack(4)
unsigned short *pucCharArray[10][10];
typedef struct unRec
{
	unsigned long ullndex;     //4
	unsigned short usLevel[7];    //14
	unsigned char ucPos;       //1+1
}REC_S;
REC_S stMax, *pstMax;
void main()
{
	printf("%d\n", sizeof(pucCharArray));//400
	printf("%d\n", sizeof(stMax));       //20
	printf("%d\n", sizeof(pstMax));      //4
	printf("%d\n", sizeof(*pstMax));     //20  
}
/*
struct S1
{
	char c1; //1 +3
	int i;   //4
	char c2; //1 + 3
};
void main()
{
	printf("%d\n", sizeof(struct S1));
}
/*
struct S2
{
	char c1; //1
	char c2; //1 + 2
	int i;   //4
};
//16
struct S3
{
	double d; //8
	char c;   //1 + 3
	int i;    //4
};
struct S4
{
	char c1;       //1 + 7
	struct S3 s3;  //16
	double d;      //8
};
void main()
{
	printf("%d\n", sizeof(struct S4));
}
/*
struct S1
{
	char c1; //1 + 3
	int i;   //4
	char c2; //1 + 3
};
void main()
{
	printf("%d\n", sizeof(struct S1));
}
/*
#pragma pack(2)
typedef struct Test
{
	short a;      //2 + 6
	struct      //类型  C  C++
	{
		double c;     //8   哑成员
		int b;        //4
		char d;       //1+3
	};
	int e;        //4 + 4
}Test;
//20
void main()
{
	printf("%d\n", sizeof(Test));
}
/*
typedef struct Test
{
	short a;      //2 
	struct
	{
		int b;        //4 
		double c;     //8
		char d;       //1 + 1
	};
	int e;        //4 
}Test;
//20
void main()
{
	printf("%d\n", sizeof(Test));
}
/*
typedef struct Test
{
	short a;      //2 + 6
	struct
	{
		int b;        //4 + 4
		double c[10]; //80
		char d;       //1 + 7
	};
	int e;        //4 + 4
}Test;
//112
void main()
{
	printf("%d\n", sizeof(Test));
}
/*
typedef struct Test
{
	short a;      //2 + 6
	struct
	{
		int b;    //4 + 4
		double c; //8
		char d;   //1 + 7
	};
	int e;        //4 + 4
}Test;
//40
void main()
{
	printf("%d\n", sizeof(Test));
	Test t;
}
/*
#pragma pack(1)
typedef struct Test
{
	char  a;    //1
	int c;      //4
	double b;   //8
}Test;
void main()
{
	printf("%d\n", sizeof(Test));
	Test t;
}
/*
#pragma pack(2)
typedef struct Test
{
	char  a;    //1
	char b;
	char c;
}Test;
void main()
{
	printf("%d\n", sizeof(Test));
	Test t;
}
/*
typedef struct Test
{
	char  a;    //1 + 1
	int c;      //4
	double b;   //8
}Test;
void main()
{
	printf("%d\n", sizeof(Test));
	Test t;
}
/*
typedef struct Test
{
	char  a;    //1 + 7
	double b;   //8
	int c;      //4 + 4
}Test;
void main()
{
	printf("%d\n", sizeof(Test));
	Test t;
	t.a = 'A';
	t.b = 12.34;
	t.c = 100;
}
*/
