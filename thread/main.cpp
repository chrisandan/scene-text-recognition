    #include<stdio.h>  
    #include<pthread.h>  
    #include<string.h>  
#include<sys/types.h>  
#include<unistd.h>  

    #include<pthread.h>  
    #include<string.h>  
    #include<sys/types.h>  
    #include<unistd.h>
#include <iostream>  

using namespace std;

string str;
pthread_t main_tid;  


    void print_ids(const char *str)  
    {  
  	str="espeak 11111";
			for(int i=0;i<5;i++)
			{
				system(str.c_str());
				usleep(2500000);
			}
    }  
    void *func(void *arg)  
    {  
        print_ids("new  thread:");  
        return ((void *)0);  
    }  
    int main()  
    {  
        int err;  
        err = pthread_create(&main_tid, NULL, func, NULL); //创建线程  
        if(err != 0){  
            printf("create thread error: %s/n",strerror(err));  
            return 1;  
        }  
        printf("main thread: pid: %u tid: %u (0x%x)/n",   
                    (unsigned int)getpid(),  
                    (unsigned int)pthread_self(),  
                    (unsigned int)pthread_self());  
        print_ids("main thread:");  
        sleep(1);  
        return 0;  
    }  
