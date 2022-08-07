#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x
int main(){
    int cap,orate,i=0,inp[10]={0},ch,nsec,count=0,drop=0,x;
    printf("Enter the size of the bucket");
    scanf("%d",&cap);
    printf("Enter the output rate ");
    scanf("%d",&orate);
    do {
        printf("Enter the number of packets in second %d",i+1);
        scanf("%d",&inp[i]);
        if (inp[i]>cap)
        {
            printf("Bucket overflow");
            printf("Packet discarded");
            exit(0);
        }
        i++;
        printf("Enter 1 to continue and 0 to exit");
        scanf("%d",&ch);
        
    } while(ch);
    nsec=i;
    printf("\n Second \t Recieved \t Sent \t Dropped \t Remained \n");
    for ( i = 0; i < nsec; i++)
    {
        printf("  %d",i+1);
        printf(" \t\t%d\t",inp[i]);
        printf(" \t%d\t", MIN((inp[i]+count), orate));
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
         printf("\t %d\t %d\n",drop,count);
    }
    return 0;
    
}