#ifndef __STUDENT_H
#define __STUDENT_H
#include <stdio.h>
#include <string.h>

//定义一个结构体，即定义一个类型
struct student
{
	char id[9];//存数学号
	char name[13];//存储姓名
	char sex;//性别
	unsigned int age;//年龄
};

void setS(struct student *,char *,char *,char,unsigned int);

void putS(const struct student *);
#endif
