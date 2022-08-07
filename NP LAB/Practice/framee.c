#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
char frame[1024];

void recieve(){
        int i=0,ipvar,framelen;
        char charinlen;
        printf("\nReciever  side\n");
        printf("\nThe recieved frame is :%s ",frame);
        while (frame[i]!='\0')
        {
            charinlen=frame[i];
            framelen=(int)charinlen-(int)'0';
            ipvar=i+framelen;
            i=i+1;
            //i=i+1 k bad humko length of the frame btana h samjhe babu
            printf("\nThe length of the frame is :%d",framelen);
            printf("\nframe--->");
            //aur in dono print statement k bad hmko while loop lgana h
            while (i<ipvar+1)
            {
                printf("%c",frame[i++]);
            }
            printf("\n");
        }
        
}
int main(){
    int i,n,len=0;
    char buff[256],length[20];

    printf("\nEnter the length of the frame \t:");
    scanf("%d",&n);

    for ( i = 0; i < n; i++)
    {
        printf("Enter the frame :");
        scanf("%s",buff);
        len=strlen(buff);
        sprintf(length,"%d",len);
        strcat(frame,length);
        strcat(frame,buff);
    }
    for ( i = 0; frame[i]!='\0'; i++)
    {
        printf("%c",frame[i]);
    }
    recieve();
    return 0;
    
}