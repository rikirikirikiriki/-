#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//不好运行可以复制到dev编译器去运行
int main()
{
	//三种结构：顺序，选择分支if,switch(转向break,goto,continue,return)，循环for,while,do wihle

	//1.选择分支
	//1.1选择分支if格式
	//if(条件)
	//{语句;}
	//else if(条件)
	//{语句;}
	//else
	//{语句;}//注意，不用{}包住，只能控制后面第一话

	//（1）以下写法错误
	int age = 0;
	scanf("%d", &age);
	if (18 < age < 30)
	{
		printf("青年\n");
	}
	//运行发现10岁也打印青年，是因为18<age为假0，0<30为真1，故顺序运算18<age<30=0<30=1，判断为真打印青年
	//所以真确写法如下，应该有逻辑符号&&(与),||(或)，记忆：&=and=与，且
	if (18 < age && age < 30)
	{
		printf("青年\n");
	}

	//（2）if和else不是对齐匹配（Python是对齐匹配），else是和距离最近的if匹配！
		//所以加括号，对齐，规范写好阅读

	//（3）使用判断相等==时候，易错写成=赋值且无语法错也可运行，为好发现错误，建议把常量放左边，变量放右边
		//如：if(18==age)

	//练习1：判断奇偶数
	int num = 0;
	scanf("%d", &num);
	if (num % 2 == 1)
		printf("奇数");
	else
		printf("偶数");

	//练习2：输出100内奇数
	int i = 1;
	while (i <= 100)
	{
		if (i % 2 == 1)
		{
			printf("%d\n", i);
		}
		i++;
	}


	//1.2.选择分支Switch语句 
	//switch(整形表达式)
		//{
		//	case (整形常量表达式)://不能变量，必须常量,也可以字符（因为保存也是asmall值）
		//	{语句};
		//	break;//如果不加break，则从某一个case进入一直运行到switch底部
		//	case (整形常量表达式):
		//	{语句}；
		//	break;
		//}

	//练习：输出星期几
	int day = 0;
	scanf("%d", &day);
	switch (day)
	{
	case 1:
		printf("星期一\n");
		break;
	case 2:
		printf("星期二\n");
		break;
	case 3:
		printf("星期三\n");
		break;
	case 4:
		printf("星期四\n");
		break;
	case 5:
		printf("星期五\n");
		break;
	case 6:
		printf("星期六\n");
		break;
	case 7:
		printf("星期天\n");
		break;
		//用好default，case不能匹配的语句全到default这来
	default:
		printf("输入错误\n");
		break;
	}

	//练习变式：利用好无break持续往下走，分出工作日和周末
	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("工作日\n");
		break;
	case 6:
	case 7:
		printf("周末\n");
		break;

	}
	//注：switch语句可嵌套，switch里面可以套switch


	//2.循环语句while，for，do while
//2.1.循环语句while
	/*whlie(表达式)
	{循环语句};*/

	//死循环：
	//while (1)//括号内是1，1为真，满足真则一直运行，打印无限a
	//{
	//	printf("a");
	//}

//（1）.遇到break，永久的终止循环
//（2）.遇到continue，跳过本次循环后面的代码，直接去判断部分，进入下次循环的判断
	//int x = 1;//1.初始化
	//while (x <= 10)//判断进入循环
	//{
	//	if (5 == x)
	//		continue;

	//	printf("%d",x);
	//	x++;//调整
	//}
	//打印出1,2,3,4后，x变成5，无限死循环判断x<=10,无限continue
	// 注意：此处若使用for循环更好，不会无限循环，因为for中continue只跳过了调整，while跳到了判断
	// 
	//变式：
	//int x = 1;
	//while (x <= 10)
	//{
	//	x++;
	//	if (5 == x)
	//		continue;

	//	printf("%d", x);
	//	
	//}
//打印出2,3,4,6,7,8,9,10,11(没有5)






//（2.2）应用1:清理缓冲区
// 

/*
int ch = 0;
while ((ch = getchar()) != EOF)//意思是得到正常字符，则正常打印。打Ctrl+字符停止循环

{
	putchar(ch);

	//putchar是输出刚刚获取字符的函数，等同于代码printf("%c\n",ch);
}
*/

//EOF是end of file文件结束标志，是#define定义的-1，故用int接收
//getchat是获取输入字符的ascll的函数，ascll值是数字，故用int;
//getchar和scanf是一类函数，从输入缓冲区而非键盘获取数据
//getcgar不是直接读取的，是从输入缓冲区里面拿：假设输入a按回车则缓冲区：【a\n】
//运行是：第一次循环——读取a——打印a——第二次循环——读取\n——打印\n（换行）——读取EOF——循环结束
//打印结果：
//a
//a
//


/*
//下面举例1（假设密码是字符串）
	char password[20] = { 0 };
	printf("请输入密码：");
	scanf("%s", password);

	//假设输入abc，输入缓冲区【abc\n】
	//则scanf拿走了abc给password，输入缓冲区还剩：【\n】

	printf("请确认密码（Y/N）：");
	int r = getchar();//getchar函数读取缓冲区，读出来\n,赋值给r
	if ('Y' == r)
		printf("yes\n");
	else
		printf("no\n");
	//r=\n,进入判断后还未输入Y/N，直接打印no了，程序错误，下面更改

//举例2
	char password1[20] = { 0 };
	printf("请输入密码：");
	scanf("%s", password1);

	getchar();//清理缓冲区一个字符，读取输入缓冲区剩下的\n，代码可以用了

	printf("请确认密码（Y/N）：");
	int r1 = getchar();
	if ('Y' == r1)
		printf("yes\n");
	else
		printf("no\n");
	//但是以上程序无法读取有空格的密码，输入abc def，回车后又直接no了，
	//原因是scanf不能读取空格，输入缓冲区【abc def\n】，scanf只读取abc
	//getchar()只能清理缓冲区一个字符，剩下的全给了后面的getchar读，直接判断no
	//清理缓冲区可能需要清理一堆字符，可以使用while循环，以下再更改


//举例3
	char password2[20] = { 0 };
	printf("请输入密码：");
	scanf("%s", password2);

	int ch = 0;
	while ((ch = getchar()) != '\n');
	{

	}
	//清理缓冲区，直到读取并清理输入缓冲区剩下的\n，代码可以用了

	printf("请确认密码（Y/N）：");
	int r2 = getchar();
	if ('Y' == r2)
		printf("yes\n");
	else
		printf("no\n");

*/



//举例2：挑出字符串中的数字字符，并打印
	char ch = '\0';
	while ((ch = getchar()) != EOF)
	{
		if (ch < '0' || ch>'9')
			continue;
		putchar(ch);
	}






	//2.2循环for-用的最多
	//（1）格式
	//	for (表达式1;表达式2;表达式3)
	//	{循环语句;}
	//表达式1为初始化部分，表达式2为条件判断部分，表达式3为调整部分
	//判断部分-省略则条件恒成立，死循环
	//调整部分-循环结束后再进入 
	// 
	// 和while类比：
	//	int x = 1;//初始化部分
	//	while(条件)
	//	{循环体 }//条件判断部分
	//	x++;//调整部分

	//发现for比while更简便，故for更普遍


	//（2）举例：
	//int x = 0;
	//for (x = 1; x <= 10; x++)
	//{
	//	printf("%d", x);
	//}

	//也可以加break，continue
    //int x = 0;
	//for (x = 1; x <= 10; x++)
	//{
	// if (i==5)
	// continue;
	//	printf("%d", x);
	//}

//（3）！！！易错：判断中i==0是i是否为0，i=0是假（同理i=1为真，不是i==1）
//for(int i=0;i=0;i++)不论循环体是什么，循环零次，因为判断部分i=0，0为假，假不进入循环


//
//	2.3循环 - do while循环
//（1）格式-结构上先循环再判断，至少循环一次
//do
//{循环语句};
//while (表达式判断);
//
//（2）举例

//int i = 1;
//do
//{
//	printf("%d", i);
//	i++;
//} 
//while (i <= 10);
//
// 
//加上break/continue
//int i = 1;
//do
//{
// 	i++;
// 	if(i==5)
// 	   continue;
// 
//	printf("%d", i);
//
//} 
//while (i <= 10);
//打印2-11没有5



	return 0;
}


