#include<stdio.h>
#include<string.h>
int main()
{
	char p1[1000],p2[10] = { 0 },p3=[100],p4[100];
	char* p1 = p1, * p2 = p2, * p3 = p3, * p4 = p4;
	int i=0, num = 0,a = 0,b = 0;
	printf(" ‰»Î\n");
	gets(p1);
	gets(p2);
	a = strlen(p1);
	b = strlen(p2);
	strcpy(p4, p1);
    for(i = 0; p4 != NULL; i++)
	{
		if((p3 = strstr(p4,p2)) !=NULL)
		{
			num++;
			p3 +=b;
		}
		p4 = p3;
	}
	printf("%d",num);
	return 0;
}