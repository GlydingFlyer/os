#include<stdio.h>
#include<string.h>
void display();
typedef struct
{
	char uname[15];
	char fname[20][12];
	int size;
}subdir;
subdir user[20];
int n=0;
void main()
{
	int i,j,k,ch;
	char id[12];
	printf("\n enter your choice:");
	printf("\n 1.logging in for the first time \n2.already have login id\n3.display\n4.exit\n");
	scanf("%d",&ch);
	do
	{
		switch(ch)
		{
			case 1:printf("\n enter the username login id");
			scanf("%s",user[n].uname);
			createfiles(n);
			n++;
			break;
			case 2:printf("\n enter your login id");
			scanf("%s",id);
			for(i=0;i<n;i++)
			{
				k=strcmp(user[i].uname,id);
				if(k==0)
				{
					createfiles(i);
					break;
				}
			}
			if(i==n)
			printf("\n no such login id in the file system");
			break;
			case 3:display();
			break;
		}
		printf("\n enter your choice:");
		scanf("%d",&ch);
	}while(ch!=4);
}
createfiles(int id)
{
	int i,v,ch,size;
	size=user[id].size;
	do
	{
		w:printf("\n enter the filename:");
		scanf("%s",user[id].fname[size]);
		i=0;
		while(i<size)
		{
			v=strcmp(user[id].fname[i],user[id].fname[size]);
			if(v==0)
			{
				printf("\n file already exist \n please enter other name");
				goto w;
			}
			i++;
		}
		size=++user[id].size;
		printf("\n do you want to create another file(yes 1/no 0)?");
		scanf("%d",&ch);
	}while(ch!=0);
	return 0;
}
void display()
{
	int i,j;
	printf("\n the contents of the file system are:");
	printf("\n user name\t files\n");
	printf("================================================\n");
	for(i=0;i<n;i++)
	{
		printf("\n%s",user[i].uname);
		for(j=0;j<user[i].size;j++)
		printf("\t\t%s\n",user[i].fname[j]);
		printf("----------------------------\n");
			}
}
