#include<stdio.h>
#include<string.h>
main()
{
	int s=0,i,ch,v;
	char f[20][12];
	do
	{
		w:printf("\n enter the filename:");
		scanf("%s",f[s]);
		i=0;
		while(i<s)
		{
			v=strcmp(f[s],f[i]);
			if(v==0)
			{
				printf("\n file already exist\n please enter other name");
				goto w;
			}
			i++;
			}
			s++;
			printf("\n do you want to create another file(1/0)?");
			scanf("%d",&ch);
		}while(ch!=0);
	printf("\n the file in the file sytems are:");
	for(i=0;i<s;i++)
	printf("\n %d\t%s",i+1,f[i]);
	printf("\n");
	return 0;
	}
