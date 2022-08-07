#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N strlen(g)

int a,c,e;
char t[120],cs[120],g[]="1000001111";

void xor(){
    for ( c = 1; c < N; c++)
    {
        cs[c]=(cs[c]==g[c]?'0':'1');
    }   
}

void crc(){
    for ( e = 0; e < N; e++)
    {
        cs[e]=t[e];
    }
    do {
            if (cs[0]=='1')
            {
                xor();
            }
            for ( c = 0; c < N-1; c++)
            {
                cs[c]=cs[c+1];
            }
            cs[c]=t[e++];
         
    } while(e<=a+N-1);
}
int main(){
    
    printf("Enter the polynomial :\n");
    scanf("%s",t);
    a=strlen(t);

    //  printf("Generated polynomial is %s",g);
    // for ( e = a; e < a+N-1; e++)
    // {
    //     t[e]='0';
    // }

    printf("The  generarted polynomial is %s\n",g);
    for (e=a;e<a+N-1;e++)
    {
        t[e]='0';
    }

    printf("Modified polynomial is %s\n",t);
    crc();

    printf("Checksum is %s\n",cs);
     for (e=a;e<a+N-1;e++)
    {
        t[e]=cs[e-a];
    }

    printf("Final codeword is :%s",t);

    printf("Enter the position to introduce an error \n");
    scanf("%d",&e);
    t[e]=(t[e]=='0'?'1':'0');
    
}