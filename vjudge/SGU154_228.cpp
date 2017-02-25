// SGU154
//undefined154


#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int fun(int x)
{
    int sum = 0;
    while(x)
    {
        sum+= x/5;
        x /= 5;
    }
    return sum;
}
int main()
{
    int Q;
    while(cin>>Q)
    {
        if(Q == 0)
        {
            printf("1\n");
            continue;
        }
      int N = Q * 4 / 5 * 5;      //依据公式先大致算到4*Q（除5乘5是为了N正好是5的倍数），然后再往后推
        while(fun(N) < Q)
        {
            N += 5;
        }
       if(fun(N) == Q) cout<<N<<endl;
        else cout<<"No solution"<<endl;
    }
    return 0;
}