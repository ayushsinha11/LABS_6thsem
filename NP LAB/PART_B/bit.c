#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void recieve(int *res,int l2){
    int msg[50],j=0,count=0;
    for (int i = 8; i <l2-8; i++)
    {
        if (res[i]==0)
        {
            if (count==5)
            {   
                i++;
                msg[j]=res[i];
                j++;
                count=0;
            }
            else{
                msg[j]=res[i];
                j++;
                count=0;
            }
            
        }
        else{
            msg[j]=res[i];
            j++;
            count++;
        }
        
    }
    printf("The reviever side message is :");
    for (int i = 0; i <j; i++)
    {
        printf("%d",msg[i]);
    }
    
    
}

void send(){
    //lamba wala
    int n,count=0,msg[50],res[50],zero=0,zerocount=0;
    printf("Enter the number of bits ");
    scanf("%d",&n);
    printf("Enter the bits");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&msg[i]);
    }
    res[0]=0;
    res[1]=1;
    res[2]=1;
    res[3]=1;
    res[4]=1;
    res[5]=1;
    res[6]=1;
    res[7]=0;
    int j=8;
    for ( int i = 0; i < n; i++)
    {
        if (msg[i]==0)
        {
                res[j]=msg[i];
                j++;
                count=0;
                zero=1;
        }else{
            if (count==5)
            {
                res[j]=0;
                zerocount++;
                res[j]=msg[i];
                j++;
                count=0;
            }
            else{
                res[j]=msg[i];
                j++;
                count++;
            }
            
        }
        
    }
    res[j++]=0;
     res[j++]=1;
    res[j++]=1;
     res[j++]=1;
     res[j++]=1;
     res[j++]=1;
     res[j++]=1;
     res[j++]=0;
     int l1=n+zerocount+16;
     printf("The length of the msg is :%d",l1);
     printf("The frame is :");
     for (int i = 0; i < j; i++)
     {
        printf("%d",res[i]);
     }
     recieve(res,l1);
     
}

int main()
{
     send();
    return 0;
}