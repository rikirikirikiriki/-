#define _CRT_SECURE_NO_WARNINGS
int m = 2024;
//static int m=2024;//加上static则没有全局变量的外部链接属性了
//作用域只是当前文件，不是整个工程了
int ADD(int x, int y)
{
	return x + y;
}
//同理，加上static，也没有外部链接属性了，只能本文件使用