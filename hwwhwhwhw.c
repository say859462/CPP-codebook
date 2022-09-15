#include <stdio.h>
#include <stdarg.h>
#define INT_MAX 2147483647
void myprintf(const char *format, ...){
	va_list args;
	char ch;
	va_start(args,format);
	while(*format!='\0'){
      
	    if(*format=='%'){
	        format++;
    	    if(*format=='d'){
    	        int i=va_arg(args,int);
    	        int len=0;
              	char num[10]={0};
              	int tmp=i;
              while(tmp){
              	num[len++]=(tmp%10+'0');
                tmp/=10;
              }
              	for(int i=len-1;i>=0;i--){
                	putchar(num[i]);
                }
    	    }
    	    if(*format=='c'){
    	        int c=va_arg(args,int);
    	        putchar(c);
    	    }
    	    if(*format=='s'){
    	        char *s=va_arg(args,char *);
    	        while(*s){
    	            putchar(*s++);
    	        }
    	    }
	    }
      
	    else putchar(*format);
      
	    format++;
	}
  return ;
}
int main(){
    myprintf("string test: %s\n", "123456");
    myprintf("int max: %d\n", INT_MAX);
    myprintf("int negative: %d\n", -1243);
    myprintf("char %c %c %c \n", 'a', 'b', 'c');
    myprintf("mixed: %c %s %d \n", 'a', "abc", 1234);
}

