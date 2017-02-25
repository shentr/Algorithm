// URAL2020
//http://acm.timus.ru/problem.aspx?space=2.02&num=2020


#include"bits/stdc++.h";
using namespace std;
const int N=1010;

int main()
{
    char s1[N], s2[N];
    cin>>s1>>s2;
    int len1=strlen(s1),len2=strlen(s2),pos1=0,pos2=0,ans=0;
    while(!(pos1==len1&&pos2==len2))
    {
        if(pos1==len1)
        {
            ans++;
            pos2++;
            continue;
        }
        if(pos2==len2)
        {
            ans++;
            pos1++;
            continue;
        }
        if(s1[pos1]=='F'&&s2[pos2]=='F')
        {
            pos1++, pos2++;
            ans++;
            continue;
        }
        if(s1[pos1]=='R'&&s2[pos2]=='R')
        {
            pos1++, pos2++;
            ans++;
            continue;
        }
        if(s1[pos1]=='R'&&s2[pos2]=='F')
        {
            pos1++, pos2++;
            ans++;
            continue;
        }
        if(s1[pos1]=='F'&&s2[pos2]=='R')
        {
            pos1++,pos2++;
            ans++;
            continue;
        }
        if(s1[pos1]=='L'&& s2[pos2]=='L')
        {
            pos1++, pos2++;
            ans++;
            continue;
        }
        if(s1[pos1]=='L')
        {
            pos2++;
            ans++;
            continue;
        }
        if(s2[pos2]=='L')
        {
            pos1++;
            ans++;
            continue;
        }
    }
    cout<<ans<<endl;
    return 0;
}
