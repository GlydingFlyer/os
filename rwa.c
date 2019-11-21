#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
char block[1024];
int in,out;
int nread;
in=open(“argv[1]”,O_RDONLY);
out=open(“argv[2]”,O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
if(in==-1||out==-1)
{
printf("Unable to open..ERROR in opening file");
 exit(0);
}
while(nread=read(in,block,sizeof(block))>0)
write(out,block,nread);
printf(“file copied successfully”);
close(in);
close(out);
return;
}
