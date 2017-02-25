// POJ1273
//http://poj.org/problem?id=1273


#include <iostream>
#include<cstring>
#include <queue>
using namespace std;
int G[300][300];
int Prev[300];
bool Visited[300];
int n,m;

unsigned Augment()
{
    int v;
    int i;
    deque<int> q;
    memset(Prev,0,sizeof(Prev));
    memset(Visited,0,sizeof(Visited));
    Prev[1] = 0;
    Visited[1] = 1;
    q.push_back(1);
    bool bFindPath = false;
    while( ! q.empty())
    {
    v = q.front();
    q.pop_front();
    for( i = 1;i <= m;i ++)
    {
    if( G[v][i] > 0 && Visited[i] == 0)
    {
    Prev[i] = v;
    Visited[i] = 1;
    if( i == m )
    {
    bFindPath = true;
    q.clear();
    break;
    }
else
    q.push_back(i);
    }
    }
    }
    if( ! bFindPath)
    return 0;
    int nMinFlow = 999999999;
    v = m;
    while( Prev[v] )
    {
    nMinFlow = min( nMinFlow,G[Prev[v]][v]);
    v = Prev[v];
    }
    v = m;
    while( Prev[v] ) {
    G[Prev[v]][v] -= nMinFlow;
    G[v][Prev[v]] += nMinFlow;
    v = Prev[v];
}
return nMinFlow;
}

int main()
{
    while (cin >> n >> m ) {
    int i,j,k;
    int s,e,c;
    memset( G,0,sizeof(G));
    for( i = 0;i < n;i ++ ) {
    cin >> s >> e >> c;
    G[s][e] += c;
}
    unsigned int MaxFlow = 0;
    unsigned int aug;
    while( aug = Augment() )
    MaxFlow += aug;
    cout << MaxFlow << endl;
}
return 0;
}
