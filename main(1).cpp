#include<stdio.h>
struct stduent
{
	char ID[15];
	int test;
	int final;


}
int main()
{
	int n;
	int m;
	int a;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s %d %d",&stu[i].ID,&stu[i].test,&stu[i].final);
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a);
		for(int j=0;j<n;j++)
		{
			if(stu[j].test==a)
			{
				printf("%s %d\n",stu[j].ID,stu[j].final);break;
			}
		}
	}
return 0;
}
