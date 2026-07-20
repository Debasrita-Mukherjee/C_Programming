#include<stdio.h>
#define MAX 100
struct Item
{
int weight;
int value;
float ratio;
};
int main()
{
int n,i,j;
float capacity,total=0;
printf("Enter number of items: ");
scanf("%d",&n);
struct Item item[MAX],temp;
for(i=0;i<n;i++)
{
printf("Enter Weight and Value of Item %d: ",i+1);
scanf("%d%d",&item[i].weight,&item[i].value);
item[i].ratio=(float)item[i].value/item[i].weight;
}
printf("Enter Capacity: ");
scanf("%f",&capacity);
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(item[i].ratio<item[j].ratio)
{
temp=item[i];
item[i]=item[j];
item[j]=temp;
}
}
}
printf("\nSelected Items:\n");
for(i=0;i<n;i++)
{
if(capacity>=item[i].weight)
{
printf("Weight=%d Value=%d\n",item[i].weight,item[i].value);
capacity-=item[i].weight;
total+=item[i].value;
}
else
{
printf("Weight Taken=%.2f of %d\n",capacity,item[i].weight);
total+=item[i].ratio*capacity;
break;
}
}
printf("\nMaximum Profit = %.2f",total);
return 0;
}

