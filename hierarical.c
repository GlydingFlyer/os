#include<stdio.h>
struct st
{
	char dname[10];
	char sdname[10][10];
	char fname[10][10][10];
	int ds,sds;
}
dir[10];
main()
{
	int i,j,k,n;
	printf("\n enter the number of directories:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n enter directory %d name",i);
		scanf("%s",dir[i].dname);
		printf("\n enter the size of directory:");
		scanf("%d",&dir[i].ds);
		for(j=0;j<dir[i].ds;j++)
		{
		printf("\n enter subdirectory name");
		scanf("%s",dir[i].sdname[j]);
		printf("\n enter the size of subdirectory:");
		scanf("%d",&dir[i].sds);
		for(k=0;k<dir[i].sds;k++)
		{
			printf("\n enter the filename");
			scanf("%s",dir[i].fname[j][k]);
			}	
		}
	}
	printf("\n DIRNAME \t SIZE \t SUBDIRNAME\t SIZE \tFILES\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t\t%d",dir[i].dname,dir[i].ds);
		for(j=0;j<dir[i].ds;j++)
		{
			printf("\t\t\t%s\t%d\t",dir[i].sdname[j],dir[i].sds);
			for(k=0;k<dir[i].sds;k++)
			printf("%s",dir[i].fname[j][k]);
			printf("\n\t");
		}
		printf("\n");
	}
}
