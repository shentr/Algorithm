// Gym100801A
//undefined100801A


#include"bits/stdc++.h"
using namespace std;

int main()
{
    double w,h;
    ifstream fin("alex.in");
    //while(fin>>w>>h)
    //{
        fin>>w>>h;
        double ans1,ans2;
        double ma=max(w,h),mi=min(w,h);
        ans1=ma;
        ans1/=3;
        if(mi<ans1)
            ans1=mi;

        ans2=mi;
        ans2/=2;
        ofstream fout("alex.out");
        fout<<max(ans1,ans2)<<endl;
    //}
}
