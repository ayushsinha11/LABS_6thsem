// count the frame and send to reciever

#include <stdio.h>
#include <string.h>
#include <unistd.h>
char frame[1024];
void recieve()
{
    int i = 0, ipvar, framelen;
    char charinlen;
    printf("\nReciver side\n");
    printf("\nThe received message is %s", frame);
    while (frame[i] != '\0')
    {
        charinlen = frame[i];
        framelen = (int)charinlen - (int)'0';
        ipvar = i + framelen;
        i += 1;
        printf("\nThe length of the message %d", framelen);
        printf("\nFrames -->");
        while (i < ipvar+1)
        {
            printf("%c", frame[i++]);
        }
        printf("\n");
    }
}
int main()
{
    int n, len = 0, i;
    char buf[256], length[10];
   // bzero(buf, 256);
    printf("\nEnter length of frame:\t");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter frame\t");
        scanf("%s", buf);
        len = strlen(buf);
        // len = len +1;
        sprintf(length, "%d", len);
        strcat(frame, length);
        strcat(frame, buf);
    }
    for (i = 0; frame[i] != '\0'; i++)
    {
        printf("%c", frame[i]);
    }
    recieve();
    return 0;
}