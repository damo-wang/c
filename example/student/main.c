#include <stdio.h>
#include <string.h>
#include "student.h"

int main()
{
	struct student s[3];
	int i;
	setS(&s[0],"20160001","张三",'f',29);
	setS(&s[1],"20160002","李四",'m',28);
	setS(&s[2],"20160003","王五",'f',30);
	for(i=0;i<3;i++)
	{
		putS(&s[i]);
	}
	return 0;
}




