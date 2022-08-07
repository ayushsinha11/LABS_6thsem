#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define N strlen(g)

int a,c,e;
char t[120],cs[120],g[]="100000111";


void xor(){
    for(c=1;c<N;c++){
        cs[c] = ((cs[c]==g[c]?'0':'1'));
    }
}

void crc(){
    for(e=0;e<N;e++){
        cs[e] = t[e]; 
    }
    do{
        if(cs[0]=='1')
        xor();
        for(c=0;c<N-1;c++){
            cs[c] = cs[c+1];
        }
        cs[c] = t[e++];
    }while(e<=a+N-1);
}

void main(){
    printf("Enter the polynomial:- ");
    scanf("%s",t);
    a = strlen(t);
    printf("Generated polynomial is %s\n",g);
    for(e=a;e<a+N-1;e++){
        t[e] = '0';
    }

    printf("Modified polynomial is %s\n",t);
    crc();

    printf("CheckSum:- %s\n",cs);
    for(e=a;e<a+N-1;e++){
        t[e] = cs[e-a];
    }
    printf("Final codeword:- %s\n",t);

    printf("Enter a position to introduce an error");
    scanf("%d",&e);
    
    t[e] = (t[e]=='0'?'1':'0');
    printf("Errorneous data :- %s",t);
}