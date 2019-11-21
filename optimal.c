#include<stdio.h>
int nof,nop,frames[10],pages[30],temp[10],flag1,flag2,flag3,i,j,k,pos,max,faults=0;
int lruvictim();
void main()
{
	printf("\n\t OPA\n");
	printf("\n enter no of frames..");
	scanf("%d",&nof);
	printf("\n enter no of pages in the string..");
	scanf("%d",&nop);
	printf("\n enter the reference string..");
	for(i=0;i<nop;i++)
	{
		scanf("%d",&pages[i]);
	}
	for(i=0;i<nop;i++)
	frames[i]=-1;
	
	for(i=0;i<nop;i++)
	{
	flag1=flag2=0;
	for(j=0;j<nof;j++)
	{
		if(frames[j]==pages[i])
		{
			flag1=flag2=1;
			break;
		}
		}	
		if(flag1==0)
		{
			for(j=0;i<nof;j++)
			{
				if(frames[j]==-1)
				{
					faults++;
					frames[j]=pages[i];
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0)
		{
			flag3=0;
			for(j=0;j<nof;j++)
			{
				temp[j]=-1;
				for(k=i+1;k<nop;k++)
				{
					if(frames[j]==pages[k])
					{
						temp[j]=k;
						break;
					}
				}
			}
			for(j=0;j<nof;j++)
			{
				if(temp[j]==-1)
				{
					pos=j;
					flag3=1;
					break;
				}
			}
			if(flag3==0)
			{
				max=temp[0];
				pos=0;
				for(j=1;j<nof;j++)
				{
					if(temp[j]>max)
					{
						max=temp[j];
						pos=j;
					}
				}
			}
			frames[pos]=pages[i];
			faults++;
		}
		printf("\n");
		printf("no of reference %d->",pages[i]);
		for(j=0;j<nof;j++)
		{
			printf("%4d\t",frames[j]);
		}
	}
	printf("\n\n total page faults=%4d",faults);
	return 0;
	}
