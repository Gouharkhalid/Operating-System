#include<stdio.h>
#include<stdlib.h>
struct pro 
{
    int pid;
    int rt;
    int ct;
    int at;
    int bt;
    int tat;
};
void sch(struct pro* p[],int len,int rq[])
{
    int tn,t=0,c=0,f=0,i;
    struct pro * temp,* tntemp, * u;
    while (c<len)
    {
        i=0;
        int nf=0;
        temp=p[0];
        f=0;
        for (int j=0;j<len;j++)
        {
            if (temp->bt==-1 && p[j]->bt!=-1)
            {
                temp=p[j];
            }
            if (temp->bt!=-1 && p[j]->bt!=-1 && p[j]->at<=t && temp->bt>=p[j]->bt)
            {
                temp=p[j];
                f=1;
            }
        }
        if (f==0)
        {
            for (int t=0;t<len;t++)
            {
                if (temp->at>p[t]->at && p[t]->bt!=-1)
                {
                    temp=p[t];
                }
            }
            t=temp->at;
        }
        while(nf==0 && i<len)
        {
            if(p[i]->at>t && p[i]->bt!=-1)
            {
                tntemp=p[i];
                nf=1;
            }
            i++;
        }
        for (int tt=0;tt<len;tt++)
        {
            if (p[tt]->at>t && tntemp->at>p[tt]->at && p[tt]->bt!=-1)
            {
                tntemp=p[tt]; 
            }
            else if (c==len-1)
            {
                tntemp=temp;
                break;
            }
        }
        if (tntemp->at>=t+temp->bt || nf==0)
        {
            t=t+temp->bt;
            temp->ct=t;
            temp->bt=-1;
            printf("|| %d ||(%d)",temp->pid,t);
            c++;
        }
        else
        {
            temp->bt=temp->bt-(tntemp->at-t);
            t=(tntemp->at);
            printf("|| %d ||(%d)",temp->pid,t);
        }
    }
}
int main ()
{
    int n,rql=0;
    printf("enter the no of process");
    scanf("%d",&n);
    struct pro* a[n];
    for (int j=0;j<n;j++)
    {
        a[j]=(struct pro*)malloc(sizeof(struct pro));
        printf("enter the process id");
        scanf("%d",&a[j]->pid);
        printf("enter the arrival time of the process");
        scanf("%d",&a[j]->at);
        printf("enter the bust time of the process");
        scanf("%d",&a[j]->bt);
        rql+=a[j]->bt;
        a[j]->tat=0;
        a[j]->ct=0;
        a[j]->rt=0;
    }
    int rq[rql];
    sch(a,n,rq);
    for (int j=0;j<n;j++)
    {
        free(a[j]);
    }    
    return 0;
}
