#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void printinfo(struct dirent *entry,int depth){
    struct stat statbuf;
    lstat(entry->d_name,&statbuf);
    //访问权限，硬链接数，文件所有者，文件所属组，文件大小，最后修改时间，文件名
    char right[11]={'\0'};
    switch(statbuf.st_mode & S_IFMT){
        case S_IFSOCK:{
            right[0]='s';
            break;
        }
        case S_IFLNK:{
            right[0]='l';
            break;
        }
        case S_IFREG:{
            right[0]='-';
            break;
        }
        case S_IFBLK:{
            right[0]='b';
            break;
        }
        case S_IFCHR:{
            right[0]='c';
            break;
        }
        case S_IFIFO:{
            right[0]='p';
            break;
        }
        case S_IFDIR:{
            right[0]='d';
            break;
        }
    }
    right[1]=statbuf.st_mode&S_IRUSR ? 'r':'-';
    right[2]=statbuf.st_mode&S_IWUSR ? 'w':'-';
    right[3]=statbuf.st_mode&S_IXUSR ? 'x':'-';

    right[4]=statbuf.st_mode&S_IRGRP ? 'r':'-';
    right[5]=statbuf.st_mode&S_IWGRP ? 'w':'-';
    right[6]=statbuf.st_mode&S_IXGRP ? 'x':'-';

    right[7]=statbuf.st_mode&S_IROTH ? 'r':'-';
    right[8]=statbuf.st_mode&S_IWOTH ? 'w':'-';
    right[9]=statbuf.st_mode&S_IXOTH ? 'x':'-';
    unsigned long nlink=statbuf.st_nlink;
    char *uid=getpwuid(statbuf.st_uid)->pw_name;
    char *gid=getgrgid(statbuf.st_gid)->gr_name;
    long size=statbuf.st_size;
    char *time=ctime(&statbuf.st_mtime);
    char tim[100]="\0";
    strncpy(tim,time,strlen(time)-1);
    printf("%*s",depth," ");
    printf("%s %4lu %10s %10s %6ld %-20s %-15s\n",right,nlink,uid,gid,size,tim,entry->d_name);
}

void printdir(char *dir,int depth){
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    //成功返回dir结构体指针
    if((dp=opendir(dir))==NULL){
        printf("Dir open error!\n");
        return;
    }
    //将dir设置为当前目录
    chdir(dir);
    while((entry=readdir(dp))!=NULL){
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode)){
            if(strcmp(entry->d_name,"..")==0 || strcmp(entry->d_name,".")==0){
                continue;
            }
            //打印目录项深度，目录名等信息
            printinfo(entry,depth);
            printdir(entry->d_name,depth+4);
        }else{
            //访问权限，硬链接数，文件所有者，文件所属组，文件大小，最后修改时间，文件名
            printinfo(entry,depth);
        }
    }
    chdir("..");
    closedir(dp);
    return;
}

int main(int argc,char *argv[]){
    int i=1;
    while(argc>i){
        printf("%s:\n",argv[i]);
        printdir(argv[i],0);
        printf("\n");
        i+=1;
    }
    if(argc==1){
		char a[10]={'\0'};
		strncpy(a,"..",2);
		printf("%s:\n",a);
		printdir(a,0);
	}
    return 0;
}
