#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char frame[1024];

void recieve(){
    int i=0,ipvar,framelen;
    char charinlen;
    printf("Reciever side\n");
    printf("The recieved message is %s",frame);
    while (frame[i]!='\0')
    {
        charinlen=frame[i];
        framelen=(int)charinlen-(int)'0';
        ipvar=i+framelen;
        i=i+1;
        printf("The length of the message is %d",framelen);
        printf("Frames-->");
        while (i<ipvar+1)
        {
            printf("%c",frame[i++]);
        }
        printf("\n");
    }
    
}


int main()
{   
    int i,n,len=0;
    char buf[256],length[10];
    printf("Enter the number of frames:");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("Enter frames:");
        scanf("%s",buf);
        len=strlen(buf);
        sprintf(length,"%d",len);
        strcat(frame,length);
        strcat(frame,buf);
    }
    for ( i = 0; frame[i]!='\0'; i++)
    {
        printf("%c",frame[i]);
    }
    
    recieve();
     
    return 0;
}