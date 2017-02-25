// UESTC1215
//http://acm.uestc.edu.cn/#/problem/show/1215


#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int t,a1,a2,a3,a4,b1,b2,b3,b4;
    cin>>t;
    for(int kase=1;kase<=t;kase++)
    {
        cin>>a1>>a2>>a3>>a4>>b1>>b2>>b3>>b4;
        bool flag = false;
        if(a1==b1&&a2==b2&&a3==b3&&a4==b4)
            flag = true;
        else if(a1==b2&&a2==b4&&a3==b1&&a4==b3)
            flag = true;
        else if(a1==b3&&a2==b1&&a3==b4&&a4==b2)
            flag = true;
        else if(a1==b4&&a2==b3&&a3==b2&&a4==b1)
            flag = true;
        printf("Case #%d: ",kase);
        if(flag)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
