// Gym100531G
//undefined100531G


#include"bits/stdc++.h"
using namespace std;

int main()
{
    ifstream fin("grave.in");
    ofstream fout("grave.out");
    int x1,x2,x3,x4,y1,y2,y3,y4,w,h;
    fin>>x1>>y1>>x2>>y2;
    fin>>x3>>y3>>x4>>y4;
    fin>>w>>h;
    if(x2-x1>=w&&y2-y4>=h)
    {
        fout<<"Yes"<<endl;
        return 0;
    }
    if(x2-x4>=w&&y2-y1>=h)
    {
        fout<<"Yes"<<endl;
        return 0;
    }
    if(x2-x1>=w&&y3-y1>=h)
    {
        fout<<"Yes"<<endl;
        return 0;
    }
    if(x3-x1>=w&&y2-y1>=h)
    {
        fout<<"Yes"<<endl;
        return 0;
    }
    fout<<"No"<<endl;
    return 0;
}