
#include <iostream>
#include<bits/stdc++.h>
#define n 5
#define qt 2
using namespace std;
struct process
{
    int id;
    int at;
    int bt;
    int st;
    int ct;
    int rt;
    int wt;
    int tat;
};
bool comp(process a,process b )
{
    if(a.at<b.at)
    {
        return true;
    }
    else return false;
}
bool iscomplete(process *pt)
{
    for(int i=0;i<n;i++)
    {
        if(pt[i].bt!=0)
        return false;
    }
    return true;
}
int main()
{
    struct process p[n];
    p[0].id=0;p[1].id=1;p[2].id=2;p[3].id=3;p[4].id=4;
    p[0].at=3;p[1].at=1;p[2].at=4;p[3].at=2;p[4].at=5;
    p[0].bt=4;p[1].bt=3;p[2].bt=7;p[3].bt=2;p[4].bt=6;
    vector<int> btt;
     for(int i=0;i<n;i++)
    p[i].st=-1;
    for(int i=0;i<n;i++)
    {
        btt.push_back(p[i].bt);
    }
    sort(p,p+n,comp);
    int gt=0;
    int i=0;
    float avg_wt,avg_rt,avg_tat;
    avg_tat=avg_rt=avg_wt=0;
    while(!iscomplete(p)){
        i=0;
    while(i<n)
    {
        cout<<gt;
        if(p[i].at>gt)
        gt++;
        else if(p[i].bt!=0)
        {
            if(p[i].st==-1)
            p[i].st=gt;

            if(p[i].bt<=qt){
            gt+=p[i].bt;
            p[i].ct=gt;
            p[i].bt=0;
            i++;
            }
            else{
            gt=gt+qt;
            p[i].bt-=qt;
            i++;
            }
            
        }
        else
        i++;
    }}
     for(int i=0;i<n;i++)
    {
        p[i].rt=p[i].st-p[i].at;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }
    for(int i=0;i<n;i++)
    {
        p[i].bt=btt[i];
    }
      cout<<"id\tat\tbt\tst\tct\trt\ttat\twt"<<endl;
    for(int i=0;i<n;i++)
    {
    cout<<p[i].id+1<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].rt<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
    }
    
    return 0;
}