#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void check_receiver(char d[],int total,int n )
{
	if(strlen(d)!=total)
    	printf("Wrong number of bits.");
    else {
	int temp2[30],b[n];
	int k,i,m=n-1,sum=0,t,j,pos=0;
	for(i=0,j=total-1;i<total;i++,j--)
    {
        temp2[i]=d[j];
    }
    sum=0;
    for(k=0;k<n;k++)
    {
        t=pow(2,k)-1;

        for(i=t;i<total;)
        {
            for(j=0;j<=t;j++)
            {
                sum=sum+temp2[i];
                i++;
                if(i>=total)
                    break;
            }

            if(i>=total)
                break;

            for(j=0;j<=t;j++)
            {
                i++;
                if(i>=total)
                    break;
            }

            if(i>=total)
                break;
        }
        b[m]=sum%2;
        sum=0;
       printf("P%d: %d\n",t+1,b[m]);
        m--;
    }
    for(m=n;m>=0;m--)
    {
        pos=pos+b[n-m-1]*pow(2,m);
    }
    if(pos==0)
    printf("No Error in Transmission.\n");
    else
    printf("Position of Error: %d\n",pos);
	}
	
}
void main()
{
    int maxp=6;
    int a[50],temp[70],temp2[70];
    int t,i,j,k,len,n,total,r,sum=0,pos=0;
	char d[40];
    printf("Enter the data word: ");
    scanf("%s",d);
    len=strlen(d);
    for(i=0,j=len-1;i<len;i++,j--)
    {
    	if(d[j]=='0')
    		a[i]=0;
    	else
    		a[i]=1;
	}
    for(i=0,j=0;i<len;i++)
    {
        for(k=0;k<maxp;k++)
        {
            t=pow(2,k)-1;
            if(j==t)
            {
                temp[j]=0;
                j++;
            }
        }
        temp[j]=a[i];
        j++;
    }
    total=j;
   printf("----------------------------------------------\nLength of Hamming code: %d bits\n",total);
    n=total-len;
    printf("Number of Parity Bits: %d \n",n);
    int m=n-1;
    for(k=0;k<n;k++)
    {
        t=pow(2,k)-1;
        for(i=t;i<total;)
        {
        	
            for(j=0;j<=t;j++)
            {
                sum=sum+temp[i];
                i++;
                if(i>=total)
                    break;
            }

            if(i>=total)
                break;

            for(j=0;j<=t;j++)
            {
                i++;
                if(i>=total)
                    break;
            }

            if(i>=total)
                break;
        }
        temp[t]=sum%2;
        sum=0;
        //printf("R%d: %d\n",t+1,temp[t]);
    }
    printf("Code word sent by the sender is: ");
    for(i=total-1;i>=0;i--)
    {
    	
        printf("%d",temp[i]);
    }
    printf("\nCode word received at the receiver is: ");
    scanf("%s",d);
    check_receiver(d,total,n);
}


