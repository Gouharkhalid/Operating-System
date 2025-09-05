/*
Author: Gouhar Khlaid Harris
Date:2023
Topic:Page Replacement Algorithm
*/
#include<stdio.h>
int main()
{
    int fn,pq;
    printf("enter the no of frame");
    scanf("%d",&fn);
    printf("enter the no of page request");
    scanf("%d",&pq);
    int p[pq],cp[fn];
    printf("enter the page requests");
    for (int i=0;i<pq;i++)
    {
        scanf("%d",&p[i]);
    }
    for(int i=0;i<fn;i++)
    {
        cp[i]=-1;
    }
    int a[pq][fn];
    //lru
    int ph;
    for (int j=0;j<pq;j++)
    {
        ph=0;
        for (int k=0;k<fn;k++)
        {
            if(cp[k]==p[j])
            {
                ph=1;
                break;
            }
        }
        int d=0,cpr[fn],m,y;
        if (ph==0)
        {
    
            for (int h=0;h<fn;h++)
            {
                cpr[h]=cp[h];
                if (cp[h]==-1)
                {
                    cp[h]=p[j];
                    d=1;
                    break;
                }
            }
            if (d==0)
            {
                m=0;
                while (m<fn)
                {
                    y=0;
                    while(y<fn && p[j-1-m]!=cpr[y])
                    {
                        y++;
                    }
                    if(m==fn-1)
                    {
                        cp[y]=p[j];
                    }
                    cpr[y]=-1;
                    m++;
                }
            }
        }
        for(int r=0;r<fn;r++)
        {
            a[j][r]=cp[r];
        }        
    }

    


    //fifo
/*    
    int pp=0,f;
    for (int i=0;i<pq;i++)
    {
        f=0;
        for (int j=0;j<fn;j++)
        {
            if(p[i]==cp[j])
            {
                f=1;
                break;
            }
        }
        if (f==0)
        {
            cp[pp]=p[i];
        }    
        for (int o=0;o<fn;o++)
        {
            a[i][o]=cp[o];
        }
        if(f==0)
        {
            pp=(pp+1)%fn;
        }
    }
*/
    //display
    for (int i=0;i<fn;i++)
    {
        for(int j=0;j<pq;j++)
        {
            printf("| %d |",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}
