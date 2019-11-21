#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct 
{ 
char fname[12];
 int fstart,length; 
 }direntry[10];
struct 
{ 
int start,size;
}flist[10];
int m=0,n=0,start=500; 
void create(); 
void del(); 
void compaction();
void display();
int main()  
{ 
int ch; 
flist[0].start=0; flist[0].size=start;
 while(1) 
 { 
  printf("1>Create. \n");
printf("2.Delete\n"); 
printf("3.compaction\n");  
printf("4.display\n"); 
printf("5 exit\n");
printf("Enter your choice");
 scanf("%d",&ch); 
switch(ch) 
{ case 1:  create();break; 
    case 2: del(); break;
    case 3:compaction(); break; 
 
	case 4: display(); break; 
    case 5: exit(1); break;
    default: printf("\n ou have entered a WTOing choiceo\n"); 

 }
} 

return 0; 
}



void create() 
{ 
int i,size,flag=0,j,a; 
char name[12]; 
printf("\nEnter the name of file"); 
scanf("%s",name);
printf("\nEnter the size of the file");
scanf("%d",&size); 
for(i=0;i<=m;i++) 
if( flist[i].size >= size) 
a=i,flag=1;
   if(flag) 
   {
    strcpy(direntry[n].fname,name);
	direntry[n].length=size;
	direntry[n].fstart=flist[a] .start;
    flist[a].start+=size;
	flist[a].size-=size;
	 n++; 
   } 
 else
 { 
  printf("\nNo enough space after compaction.\n"); 
  flag=0; 
compaction();
 for(i=0;i<=m;i++) 
 if( flist[i].size >= size) 
 a=i,flag=1; 
 if(flag) 
 { 
 strcpy(direntry[n].fname,name);
  direntry[n].length=size; 
  direntry[n].fstart=flist[a].start;
  flist[a].start+=size; 
  flist[a].size-=size; 
  n++; 
  } 
else 
printf("\nNo enough space after compaction");
}
}


void del()
{

int i,j,k;
char name[12]; 
 printf("enter the file name");
 scanf("%s",name);
 for(i=0;i<n;i++)
 if(!strcmp(direntry[i].fname,name)) 
     break;
  if (i==n) 
	 {
	 printf("No such file exist...."); 
     }

else{
m++;
 flist[m].start=direntry[i].fstart;
 flist[m].size=direntry[i].length;
for(k=i;k<n;k++) 
direntry[k]=direntry[k+1]; 
n--; 
} 
}


void compaction()
 {

 int i,j,sizel=0;
   for(i=0;i<n;i++)
    { 
	 direntry[i].fstart=sizel; 
	 sizel+=direntry[i].length; 
    } 

  flist[0].start=sizel;
  flist[0].size=start-sizel; 
m=0;
}
void display() 
{ int i; 
printf ("\n *** Directory contents *** \n");
printf ( "\n\nNAME STARTING ADDRESS LENGTH \n\n");
 for(i=0;i<n;i++)
   printf ( "%s%10d%10d\n" , direntry [i].fname,direntry[i].fstart, direntry[i] . length) ;
   printf("\n\n");
    printf("\n\n *** FREE SPACE TABLE *** \n\n");
	   printf("FREE START ADDRESS        FREE SIZE \n\n  ");
	   for ( i=0 ; i<=m ; i++ ) 
	    printf ( " %d       %d\n",flist[i].start,flist[i].size);

} 
