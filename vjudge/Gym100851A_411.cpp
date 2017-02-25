// Gym100851A
//undefined100851A


#include"bits/stdc++.h"
using namespace std;
const int N=1e6+5;
long long c[N],r[N],n,q,ccnt,rcnt,sumr,sumc;

long long query(char ch,long long num)
{
    if(ch=='R')
    {
        if(r[num]==1)
            return 0;
        long long sum=(num+1+num+n)*n/2;
        sum-=(sumc+num*ccnt);
        r[num]=1;
        rcnt++;
        sumr+=num;
        return sum;
    }
    if(ch=='C')
    {
        if(c[num]==1)
            return 0;
        long long sum=(num+1+num+n)*n/2;
        sum-=(sumr+num*rcnt);
        c[num]=1;
        ccnt++;
        sumc+=num;
        return sum;
    }
}

int main()
{
    char ch;
    long long num;
    ifstream fin("adjustment.in");
    ofstream fout("adjustment.out");
    fin>>n>>q;

        ccnt=0,rcnt=0,sumr=0,sumc=0;
        //memset(r,0,sizeof(r));
        //memset(c,0,sizeof(c));
        while(q--)
        {
            fin>>ch>>num;
            fout<<query(ch,num)<<endl;
        }

}
