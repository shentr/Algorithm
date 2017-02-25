// Gym100801H
//undefined100801H


#include"bits/stdc++.h"
using namespace std;
typedef long long LL;
vector<string> vec;
string st[3] = {"edHs", "fEHs", "edIT"};

void dfs(int i, string tmp)
{
    if(i == 7)
    {
        vec.push_back(tmp);
        return ;
    }
    for(int j = 0; j < 3; j ++)
        dfs(i + 1, tmp + st[j]);
}

void init()
{
    vec.clear();
    dfs(0, "");
}
int main()
{
    ifstream fin("hash.in");
    ofstream fout("hash.out");
    init();
    int k;
    while(fin>>k)
    {
        for(int i = 0; i < k; i ++)
            fout << vec[i] << endl;
    }
    return 0;
}

