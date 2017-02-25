// UVA11237
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=11237


#include<cstdio>
#include<cstring>
const int ma=100010;
typedef long long ll;
int main()
{
    ll c,n,a[ma],sum[ma];
    int cnt[ma];
    while(~scanf("%lld%lld",&c,&n)&&c&&n)
    {
        memset(cnt,-1,sizeof(cnt));
        sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum[i]=sum[i-1]+a[i];
            sum[i]%=c;
        }
        int flag=0;
        for(int i=0;i<=n;i++)
        {
            if(cnt[sum[i]]!=-1)
            {
                for(int k=cnt[sum[i]]+1;k<=i;k++)
                   printf("%d ",k);
                break;
            }
            cnt[sum[i]]=i;




            /*for(int j=i+1;j<=n;j++)
            {
                if(sum[i]==sum[j])
                {
                    for(int k=i+1;k<=j;k++)
                        printf("%d ",k);
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;*/
        }
            printf("\n");
    }
}
