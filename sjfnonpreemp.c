#include<stdio.h>
int main()
{
    int n,at[10],bt[10],ct[10],i,minat,total=0,count=0,minbt=999,pos,temp[10],minat1,minat2;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    printf("AT    BT\n");
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&at[i],&bt[i]);
        temp[i]=at[i];
    }
    minat=at[0];//initialize first at to minat
    for(i=0;i<n;i++)
    {
        if(at[i]<minat)//checking for small at
        minat=at[i];
    }
    total=minat;//initialize total with minat
    printf("%d minat\n",minat);
    
    while(count!=n)
    {
        minbt=999;
        for(i=0;i<n;i++)
        {
            if(at[i]<=minat)//process came within minat
            {
                if(bt[i]<minbt)//finding the process having less burst time
                {
                    minbt=bt[i];
                    pos=i;//saving its position
                }
            }
        }
        if(minbt==999)//haven't found any process within minat(all at's are greater than minat)
        {
          minat1=999;//To exclude completed processes
          minat2=999;
          for(i=0;i<n;i++)
          {
              if(at[i]<minat1)//not a completed process
              {   //checking at[i]>minat is useless because it would have detected earlier if it is less than minat    
                  if(at[i]<minat2)
                     minat2=at[i];
              }
           }
           total=total+minat2-minat;//Add idle time to total
           minat=minat2;//new minat
           printf("minat1 %d\n",minat);  
        }
        else
        {
        total+=minbt;//assign cpu to process and add its bt to total minbt or bt[pos]
        ct[pos]=total;//update completion time
        at[pos]=999;
        count++;//one process completed
        minat=total;//update minat
        }
    }
    printf("P\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,temp[i],bt[i],ct[i],ct[i]-temp[i],ct[i]-temp[i]-bt[i]);
    }
}