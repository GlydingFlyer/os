#include<stdio.h>
typedef struct file
{
	char fname[10];
	int start,size,block[10];
	
}file;
int main()
{
	file f[10];
	int i,j,n;
	printf("\n enter no of files:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n enter filename:");
		scanf("%s",&f[i].fname);
		printf("\n enter the starting block:");
		scanf("%d",&f[i].start);
		f[i].block[0]=f[i].start;
		printf("\n enter the size of block:");
		scanf("%d",&f[i].size);
		for(j=0;j<f[i].size;j++)
		{
			printf("\n enter block numbers:");
			scanf("%d",&f[i].block[j]);
		}
	}
	printf("\n file\tstart\tsize\tblock\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t%d\t",f[i].fname,f[i].start,f[i].size);
	    for(j=0;j<f[i].size;j++)
	    printf("%d-->",f[i].block[j]);
	    printf("-1\n");
	}
	printf("\n");
}
