// UVA10815
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=10815


/*********************************
   日期：2015-04-05
   作者：matrix68
   题号: UVA 10815 - Andy's First Dictionary
   总结：set使用练习
   Tricks：
**********************************/
#include <cstdio>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <cmath>
#define MP(a, b) make_pair(a, b)
#define PB push_back
#define Lowbit(x) ((x) & (-x))
#define Rep(i,n) for(int i=0;i<n;i++)
#define mem(arr,val) memset((arr),(val),(sizeof (arr)))
#define LL long long
const double PI = acos(-0);
const int MAXN = 1000 + 10;
const int MOD = 1000007;
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };




using namespace std;
set<string>jihe;


int main()
{


//    freopen("in.txt","r",stdin);


    string sen;
    while(getline(cin,sen))
    {
        for(int i=0;i<sen.size();i++)
        {
            if(!isalpha(sen[i])) continue;
            string tmp;
            while(isalpha(sen[i]))
            {
                tmp+=tolower(sen[i]);
                i++;
            }
            jihe.insert(tmp);
        }
    }
    for(set<string>::iterator it=jihe.begin();it!=jihe.end();it++)
    {
        cout<<*it<<endl;
    }
    return 0;
}

