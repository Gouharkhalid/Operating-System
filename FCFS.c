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
void sch(struct pro* p[],int len)
{
    int t=0;
    int f=0;
    struct pro * temp;
    for (int i=0;i<len;i++)
    {
        f=0;
        temp=p[0];
        for (int j=0;j<len;j++)
        {
            if ((temp->bt== -1 && p[j]->bt!=-1))
            {
                temp=p[j];
            }
            if ((temp->at<=t && p[j]->bt!=-1 && temp->at>=p[j]->at))
            {
                temp=p[j];
                f=1;
            }
        }
        if (f==0)
        {
            for (int k=0;k<len;k++)
            {
                if (temp->at>p[k]->at && p[k]->bt!=-1)
                {
                    temp=p[k];
                }
                t=temp->at;
            }
        }
        t=temp->bt +t;
        temp->ct=t;
        temp->bt=-1;
        temp->tat=temp->ct-temp->at;
    }
}
int main ()
{
    int n;
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
        a[j]->tat=0;
        a[j]->ct=0;
        a[j]->rt=0;
    }
    sch(a,n);
    int ct=0;
    int tat=0;
    for (int i=0;i<n;i++)
    {
        printf("%d (%d)   |",a[i]->pid,a[i]->ct);
        ct+=a[i]->ct;
        tat+=a[i]->tat;
    }
    printf("the average completion time is :%.3f",ct/n);
    printf("the average turn around time is :%.3f",tat/n);
    return 0;
}
