// Gym100801H
//undefined100801H


#include"bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    ifstream fin("hash.in");
    ofstream fout("hash.out");
    while(fin>>n)
    {
        for(int i=0; i<1000; i++)
            fout<<"B";
            fout<<endl;
            int sum=1;
        for(int i=0; i<1000; i++)
        {
            if(sum>=n)
                break;
            for(int j=1; j<=i; j++)
            {
                fout<<"B";
            }
            fout<<"Aa";
            for(int j=i+2;j<1000;j++)
                fout<<"B";
            fout<<endl;
            sum++;
        }
       // fout<<sum<<endl;
    }

    return 0;
}
