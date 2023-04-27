#include <stdio.h>
#include <setjmp.h>
static jmp_buf buf ;   //buf 用于保存运行环境,并做为 longjmp和setjmp 函数的参数

void second(void)
{
	printf("second\n");
	longjmp(buf, 1); //跳转到调用setjmp函数的语句处,即 第11 行. 
}

void first(void)
{
	second();
	printf("first\n");
}

int main(int argc, char ** argv)
{
	if(! setjmp(buf)) // 原始调用返回0 longjmp 间接调用则返回其提供的值.
	{
		first();

	}
	else {
		printf("maink\n");

	
 }
	return 0 ;
}
