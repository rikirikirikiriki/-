#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//#define _CRT_SECURE_NO_WARNINGS，第一行（一定第一行）写这个，不用换成scanf_s
// （仅vs用，无法跨平台写代码）
//源文件用.c后缀，否则按照c++语法了


/*
#include<stdio.h>//包含头文件，类似函数引入，std-标准，i-input，o-output
int main()//标准主函数写法，不建议void main()
{

	int a = 0;//好习惯：在定义变量同时初始化
	int b = 0;

	scanf("%d %d", &a, &b);//输入函数，用&取地址
	int sum = a + b;
	printf("%d\n", sum);//仅一个值不用&

	return 0;

}
*/

//ctrl+f5快捷运行





//变量
//1.局部变量
//2.全局变量：用extern声明，会自动在所有文件中检索
//


//常量
//1.字面常量：直接写出数字，字符（单引号）
//2.const修饰的常变量：const int a//用const不允许改变量a,有着常量的属性（常变量）
//3.define定义的标识符常量

//
//#define MAX 100//定义MAX符号为100，宏定义不用等号,且不可再赋值
//#define S "abc"
//int main()
//{
//	printf("%d\n", MAX);
//	int a = MAX;
//	printf("%d\n", a);
//	printf("%s\n", S);
//	return 0;
//}


//4.枚举变量

//性别举例，enum是枚举关键字，列举出来方便调用
/*
enum Sex
{
	MALE,
	FEMALE,
	SECRET
};

int main()
{
	enum Sex a = MALE;
	//MALE=10//错误，常量不能改
	return 0;
}
*/

//括号中的MALE,FEMALE,SECRET是枚举常量



//字符，字符串
//1.字符，单引号，类型char，保存在变量中：
//char a = 'w';
//2.字符串,双引号,无类型，保存在数组中：
//char b[]="abcde",中括号可写数字范围，不写则根据后面来
//字符串末尾隐藏\0，为结束标志，这样写则打印混乱：
//char b[]={'a','b','c','d','e'}
//可手动加上\0:
//char b[] = { 'a','b','c','d','e','\0'}

/*
int main()
{
	char b1[] = "abcde";
	char b2[] = { 'a','b','c','d','e' };
	char b3[] = { 'a','b','c','d','e','\0' };
	printf("%s\n", b1); //打印出：abcde
	printf("%s\n", b2);//打印出：abcde烫烫烫烫烫蘟bcde
	printf("%s\n", b3);//打印出：abcde
	return 0;
}
*/



//3.空格也是字符
/*
int main()
{
	printf("%d\n", strlen("abc"));//3长度
	printf("%d\n", strlen("a b c"));//5长度
	return 0;
}
*/


//转义符号
//1.\ddd ddd表示1-3个八进制的数字。 如：\130 打印出 ASCLL码值X
/*int main()
{
	printf("%d\n",'\130')；//\130是一个字符，不是三个
	return 0；
}
*/
//2.\xdd dd表示2个十六进制数字。 如：\x30  打印出打印出 ASCLL码值0
//3.\t制表符，代表四个空格



//选择分支语句
/*
int main()
{
	int a = 0;
	printf("是否好好学习？1/0\n");
	scanf("%d", &a);
	if (a == 1)
	{
		printf("成功");
	}
	else
	{
		printf("失败");
	}
	return 0;

}
*/


//while循环语句
/*
int main()
{
	int line = 0;
	while (line < 10)
	{
		printf("%d继续加油\n", line);
		line++;
	}
	if (line = 10)
	{
		printf("成功");

	}
	return 0;
}
*/


//函数
/*
int SUM(int a,int b)
{

	return a+b;
}

int main()
{
	int a = 0;
	int b = 0;

	scanf("%d %d",&a,&b);
	int sum = SUM(a,b);
	printf("%d", sum);
	return 0;
}
*/

//数组:一组相同类型的元素
/*
int main()
{
	int arr[] = { 11,22,33,44,55 };
	printf("d%",arr[2]);
	return 0;
}
*/
//1.arr[]中括号中必须为常量，如int n = 10, int arr[n] = {0}错误
//2.arr只是一个名称，可随意，如char x[]="hello world"或者 char x[12]="hello world"（十一个位置，加上\0十二个）
//3.[]里面数字表个数，不写则根据后面自动创建内存
//创建大了多出的默认初始化0，小了报错 


//操作符
//1.算术操作符
///：除-除号两端有浮点数才会出现小数，否则为整除
//%：取余数-取模操作符两端必须整数
//2.移位操作符<<,>>
//3.位操作符&，|，∧
//4.赋值操作符：=,+=,-=,*=,/=,|=, ∧=,<<=,>>=(a=a+3同等于a+=3,更简洁)

//5.单目操作符
//!           逻辑反操作（真假互变）
//-           负值
//+           正值
//&           取地址
//sizeof      操作数的类型长度（以字节为单位）
// 如printf("%d",sizeof(int))或printf("%d",sizeof 1)（括号可省去）输出为4，int类型占四个字节
//~           对一个数的二进制按位取反
//--          前置（先加后使用）、后置--（先使用后加）
//++          前置、后置++
//*           间接访问操作符(解引用操作符)
//(类型)       强制类型转换，int a=(int)3.14,强制取整数部分

//6.关系操作符：==,<,>,!=(不等)
//7.逻辑操作符，&&逻辑与（且），||逻辑或：如if(a&&b),二者都真命题才执行if
//
//8.条件操作符
//exp1？exp2:exp3:表达1为真输出2结果，1为假输出3结果
/*
int main()
{
	int a = 10;
	int b = 20;
	int r = a > b ? a : b;
	printf("d%", r);
	return 0;
}
*/

//9.逗号表达式：逗号隔开表达式，从左到右依次计算，整个结果是最后一个的结果
//int d=(c=a-2,a=b+c,c-3)
//
//10.下标引用:[]
//函数调用操作符:()



//关键字——避免和变量冲突
//auto（被省略）
//for,while,do while,break,continue
//switch,case,default,goto
//char,int,short,long,float,double
//const,修饰变量表示常量
//
//enum枚举
//void无，常用语函数返回类型/参数
//extern声明外部符号
//1.声明外部变量
/*
extern int m;
//变量m在20240801文件中，需要一个声明外部符号,全局变量别的文件也能用，具有外部链接属性
int main()
{
	printf("d\n",m);
	return 0;
}
*/
//2.声明外部函数
/*
extern int ADD(int x, int y);
//函数ADD在20240801文件中，需要一个声明外部符号,函数别的文件也能用，具有外部链接属性
int main()
{
    int a=10;
	int b=20;
	int z=ADD(a,b);
	printf("d\n",z);
	return 0;
}
*/



//register寄存器
//计算机存储设备：寄存器（集成到CPU上），高速缓存，内存，硬盘
//寄存器变量：
//register int x=3;//建议：3放在寄存器中，读取运算速度更快，放不放由编译器自动决定


//static静止的：修饰变量或函数
// 1.修饰局部变量
/*
void text()//void是返回类型，不用函数输出什么,不需要返回，就用void结束
{
	int a = 1;
	a++;
	printf("%d", a);
}
int main()
{
	int i = 0;
	while (i < 10)
	{
		text();
		i++;
	}
	return 0;
}//输出十个2 
*/

/*
void text()
{
	static int a = 1;//使局部变量a不销毁(或写int static a = 1)
	a++;
	printf("%d", a);
}
int main()
{
	int i = 0;
	while (i < 10)
	{
		text();
		i++;
	}
	return 0;
}//输出2 3 4 5 6 7 8 9 10 11
*/

// 2.修饰全局变量
/*
extern int m;
//变量m在20240801文件中，需要一个声明外部符号,全局变量别的文件也能用，具有外部链接属性
//但用static修饰就只有内部连接属性了
int main()
{
	printf("d\n",m);
	return 0;
}
*/
// 3.修饰函数：与上面类似



//struct结构体
//union联合体（共用体）
//sizeof计算大小
//typedef类型重命名：例如：
// 无符号整形为unsigned int x=0;表述太长了改为以下表述：

// typedef unsigned int nuit;//把unsigned int重命名为nuit
// unit x=0;
//unsigned,signed无符号，有符号


//define
//1.定义的标识符常量
//#define MAX 100//定义MAX符号为100，宏定义不用等号,且不可再赋值
//#define S "abc"
//int main()
//{
//	printf("%d\n", MAX);
//	int a = MAX;
//	printf("%d\n", a);
//	printf("%s\n", S);
//	return 0;
//2.定义宏：宏是有参数的,起替换作用，有时比函数简单
/*
#define ADD (x,y) ((x)+(y))//ADD是宏名，xy是参数(无类型)，x+y是宏体
int main()
{
	int a = 10;
	int b = 20;
	int c = ADD (a,b);
	printf("%d\n", c);

	return 0;
}
*/


//
//指针
//内存会划分为一个一个内存单元(1字节,1byte=8bit比特)每个内存单元都有一个编号
// 内存单元——编号——地址——地址也被称为指针
//32位电脑，32根地址线00000000000000000000000000000000，电脉冲有0/1，有2的32次方个地址序列，64位电脑同理
//打印地址：
//int a=10;
//printf("%p",&a);//打印出是2进制转16进制
//int* p=&a;//把a的地址存起来，p就是指针变量（口头简称指针），存放指针/地址的变量成为指针变量
//p类型是int*,int说明p指向的对象是int类型，*表示p是指针变量,又如：
//char ch='w';
//char* p=&ch;
//*p:解引用操作符，通过p中存放的地址，找到p所指向的对象，*p就是p指向的对象，如：
//*p='x'，就把原先的w改成了x，通过地址找对象，才是存地址的意义



//结构体struct,类似于Python中的类
struct Stu
{
	char name[20];//名字
	int age;//年龄
	char sex[10];//性别
	char id[5]; //学号
};

void print(struct Stu* ps)
{
	printf(" % s % d % s % s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).id);
	//或者用结构指针变量->成员名：
	printf(" % s % d % s % s\n", ps->name, ps->age, ps->sex, ps->id);
}
int main()
{
	struct Stu s = { "riki",20,"male","001" };//创建变量s,并且每个值初始化
	printf("%s %d %s %s\n", s.name, s.age, s.sex, s.id);
	print(&s);//调用函数
	return 0;
}