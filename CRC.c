
#include<stdio.h>
void division(int temp[],int gen[],int n,int r)
{
	 int i,j,k;
	 for(i=0;i<n;i++)
	 {
		 if (gen[0]==temp[i])
		 {
		 for(j=0,k=i;j<r+1;j++,k++)
		 temp[k]=temp[k]^gen[j];
		 }
	 }
}
void main()
{
	int n,r,i,fr[50],gen[50],temp[50];
	printf("Enter the number of frame bits: ");
	scanf("%d",&n);
	printf("Enter the frame: ");
	for(i=0;i<n;i++)
		scanf("%d",&fr[i]);
	printf("Enter the number of generator bits: ");
	scanf("%d",&r);
	printf("Enter the generator: ");
	for(i=0;i<r;i++)
		scanf("%d",&gen[i]);
	r--;
	for(i=0;i<r;i++)
		fr[n+i]=0;
	for(i=0;i<n+r;i++)
		temp[i]=fr[i];
	division(temp,gen,n,r);
	printf("CRC: ");
	for(i=0;i<r;i++)
	{
		printf("%d ",temp[n+i]);
		fr[n+i]=temp[n+i];
	}
	printf("\nEnter the transmitted message: ");
	for(i=0;i<n+r;i++)
		scanf("%d",&fr[i]);
	for(i=0;i<n+r;i++)
		temp[i]=fr[i];
	printf("---------------------------------\nDecoding\n");
	division(temp,gen,n,r);
	printf("CRC: ");
	for(i=0;i<r;i++)
	{
		printf("%d ",temp[n+i]);
		fr[n+i]=temp[n+i];
	}
	printf("\n");
	for(i=0;i<r;i++)
	{
		if(temp[n+i])
		{
		printf("Error detected in transmitted message!");
		return;
		}
		
	}
	printf("No error in received Message.\nAfter decoding crc is ");
	for(i=0;i<r;i++)
	{
		printf("%d ",temp[n+i]);
	}
	printf("\nReceived message: ");
	for(i=0;i<n;i++)
	printf("%d ",fr[i]);
	printf("\nExecuted successfully.");
}

