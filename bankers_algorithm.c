/*
Author: Gouhar Khlaid Harris
Year:2023
Topic:DeadLock Prevention{operating System}
*/
#include <stdio.h>
int main()
{
    int p,r;
    printf("enter the no of process");
    scanf("%d",&p);
    printf("enter the no of resouces");
    scanf("%d",&r);
    int t[p][r],n[p][r];
    for (int i=0;i<p;i++)
    {
        for (int j=0;j<r;j++)
        {
            printf("enter the allocated resouce of %d to the process %d",j,i);
            scanf("%d",&t[i][j]);
        }
    }
    for (int i=0;i<p;i++)
    {
        for (int j=0;j<r;j++)
        {
            printf("enter the need of resouce  %d to the process %d",j,i);
            scanf("%d",&n[i][j]);
            n[i][j]=n[i][j]-t[i][j];
        }
    }
    
    int rr[r];
    for (int i=0;i<r;i++ )
    {
        printf("enter the resouce to be allocated of %d",i);
        scanf("%d",&rr[i]);
    }
    int nf=0,i,ff;
    int k=0;
    while(k<p)
    {   
        nf=1;
        i=0;
        while(nf==1 && i<p)
        {
            ff=0;
// logic for finding the dead lock and display if it occurs 
            for (int k=0;k<r;k++)
            {
                if ( rr[k]>=n[i][k] && n[i][k]!=-1 && k==r-1 && ff==0)
                {
                    printf("p %d ->",i);
                    for (int k=0;k<r;k++)
                    {
                        rr[k]=t[i][k]+rr[k];
                        n[i][k]=-1;
                    }
                    nf=0;
                }
                else if (rr[k]<n[i][k])
                {
                    ff=1;
                }
            }
            i++;
        }
        if (nf==1)
        {
            printf("deadlock");
        }
        k++;
    }
    return 0;
}
