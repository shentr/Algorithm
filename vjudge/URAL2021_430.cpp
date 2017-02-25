// URAL2021
//http://acm.timus.ru/problem.aspx?space=2.021&num=2021


#include"bits/stdc++.h";
using namespace std;
const int N=1010;
struct team
{
    int id;
    int score;
}ta[N],tb[N];

bool cmp1(const team &a,const team &b)  //up
{
    return a.score<b.score;
}

bool cmp2(const team &a,const team &b)  //down
{
    return a.score>b.score;
}

int main()
{
    int n,sa=0,sb=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ta[i].score;
        ta[i].id=i;
        sa+=ta[i].score;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>tb[i].score;
        tb[i].id=i;
        sb+=tb[i].score;
    }
    if(sa>sb)
    {
        sort(ta+1,ta+n+1,cmp1);
        sort(tb+1,tb+n+1,cmp2);
        for(int i=1;i<=n;i++)
            cout<<ta[i].id<<' '<<tb[i].id<<endl;
    }
    else
    {
        sort(ta+1,ta+n+1,cmp2);
        sort(tb+1,tb+n+1,cmp1);
        for(int i=1;i<=n;i++)
            cout<<ta[i].id<<' '<<tb[i].id<<endl;
    }

}
