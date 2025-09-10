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
    struct pro * temp;
    for (int i=0;i<len;i++)
    {
        for (int j=0;j<len;j++)
        {
            if ()
        }
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
        printf("%d    |%d   |",a[i]->tat,a[i]->ct);
        ct+=a[i]->ct;
        tat+=a[i]->tat;
    }
    printf("the average completion time is :%.3f",ct/n);
    printf("the average turn around time is :%.3f",tat/n);
    return 0;
}
