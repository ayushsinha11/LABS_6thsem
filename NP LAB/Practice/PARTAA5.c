#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x
int main(){
    int cap,orate,ch,i=0,inp[10]={0},nsec,count=0,x,drop=0;
    printf("Enter the bucket size:");
    scanf("%d",&cap);
    printf("Enter the output rate :");
    scanf("%d",&orate);
    do {
        printf("enter the number of packets coming at second %d",i+1);
        scanf("%d",&inp[i]);
        if (inp[i]>cap)

        {
            printf("Bucket overflow");
            printf("Packet Discarded");
            exit(0);
        }
        i++;
        printf("Enter 1 to continue or 0 to exit");
        scanf("%d",&ch);
        
    } while(ch);

    nsec=i;
    printf("\n Second \t Recieved \t Sent \t Dropped \t Remained \n");
    for ( i = 0; i < nsec; i++)
    {
        printf("  %d ",i+1);
        printf(" \t\t%d\t",inp[i]);
        printf(" \t%d\t ",MIN((inp[i]+count),orate));
        if ((x=inp[i]+count-orate)>0)
        {
            if (x>cap)
            {
                count=cap;
                drop=x-cap;
            }
            else{
                count=x;
                drop=0;
            }
            
        }
        else{
            drop=0;
            count=0;
        }
        printf("  \t%d \t %d \n",drop,count);
    }
    return 0;
}