#include "header.h"

char a[]="FF";
char s[]="F[+X][-X]FX";
void repeat(char *t) { 
    static int n=5;
    char *b=(char *)malloc(sizeof(b)*100000);
    int k=0;
    if(n==0)  
	{
         return;}
    for(int i=0;t[i]!='\0';i++) { 
      if(t[i]=='F') { 
        for(int j=0;a[j]!='\0';j++)
          b[k++]=a[j];  
        }
        else if(t[i] == 'X') {
          for( int j = 0; s[j] != '\0'; j++) {
            b[k++] = s[j];
          }
        }
      else
      b[k++]=t[i];   
  }
 if(n==1)  
	{FILE *fp;
        fp=fopen("string.txt","w");
        
          fputs(b,fp);
        
        fclose(fp);
        }

  n--;
  printf("%s \n",b);
  printf("``````````````````````````````````````````````````````\n\n");
  repeat(b); 
}
    
