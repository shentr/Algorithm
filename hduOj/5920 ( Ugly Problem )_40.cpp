// 5920 ( Ugly Problem )
//acm.hdu.edu.cn/showproblem.php?pid=5920


#include"bits/stdc++.h"
using namespace std;
const int N=1e3+100;
char *s,*small,ss[N],sm[N];

void delete0()
{
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]!='0')
        {
            s=&s[i];
            return ;
        }
    }
    s[0]=0;
}

void delete0_2()
{
    for(int i=0;i<strlen(small);i++)
    {
        if(small[i]!='0')
        {
            small=&small[i];
            return ;
        }
    }
    small=NULL;
}


void sub(int lens)
{
    delete0();
    delete0_2();
    bool flag=0;
    int cha=strlen(s)-strlen(small);
    for(int i=lens-1;i>=0;i--)
    {
        if(flag==1)
        {
            if(s[i]=='0')
                s[i]='9';
            else
                s[i]=s[i]-1,flag=0;
        }
        if(i-cha<0)
            break;
        if(s[i]>=small[i-cha])
            s[i]=s[i]-small[i-cha]+'0';
        else
        {
            s[i]=s[i]+10-small[i-cha]+'0';
            flag=1;
        }
    }
}

void find_s()
{
    int lens=strlen(s);
    if(lens%2==0)
    {
        if(s[lens/2-1]>=s[lens/2])       //中间左大于右     未考虑10
        {
            int key;
            for(int i=lens/2-1;i>=0;i--)
                if(s[i]!='0')
                {
                    key=i;
                    break;
                }
            if(key==0)
            {
                small[0]='0';
                for(int i=1;i<lens;i++)
                {
                    small[i]='9';
                }
                return ;
            }
            for(int i=0;i<=key;i++)
            {
                small[i]=small[lens-i-1]=s[i];
                if(i==key)
                    small[i]=small[lens-i-1]=s[i]-1;
            }
            for(int i=key+1;i<lens/2;i++)
                small[i]=small[lens-i-1]='9';
        }
        else
        {
            for(int i=0;i<lens/2;i++)
                small[i]=small[lens-i-1]=s[i];
        }
    }
    else            //lens奇数
    {
        if(lens==1)
        {
            small[0]=s[0];
            return ;
        }
        if(s[(lens+1)/2-1]!='0')
        {
            for(int i=0;i<(lens+1)/2;i++)
            {
                small[i]=small[lens-i-1]=s[i];
                if(i==(lens+1)/2-1)
                    small[i]=s[i]-1;
            }
        }
        else
        {
            if(s[(lens+1)/2-2]>=s[(lens+1)/2])       //中间左大于右
            {
                int key;
                for(int i=(lens+1)/2-2;i>=0;i--)
                    if(s[i]!='0')
                    {
                        key=i;
                        break;
                    }
                if(key==0)
                {
                    small[0]='0';
                    for(int i=1;i<lens;i++)
                    {
                        small[i]='9';
                    }
                    return ;
                }
                for(int i=0;i<=key;i++)
                {
                    small[i]=small[lens-i-1]=s[i];
                    if(i==key)
                        small[i]=small[lens-i-1]=s[i]-1;
                }
                for(int i=key+1;i<(lens+1)/2;i++)
                    small[i]=small[lens-i-1]='9';
            }
            else
            {
                for(int i=0;i<lens/2;i++)
                    small[i]=small[lens-i-1]=s[i];
                small[lens/2]='0';
            }
        }
    }
}

char ans[60][N];
int main()
{
    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++)
    {
        memset(ans,0,sizeof(ans));
        scanf("%s",ss);
        s=ss;
        small=sm;
        int lens,cnt=0;
        while(true)
        {
            memset(sm,0,sizeof(sm));
            small=sm;
            delete0();
            lens=strlen(s);
            if(s[0]=='0'||lens==0)
                break;
            find_s();
            delete0_2();
            for(int i=0;i<strlen(small);i++)
                ans[cnt][i]=small[i];
            cnt++;
            sub(lens);
        }
        printf("Case #%d:\n",kase);
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++)
            printf("%s\n",ans[i]);
    }
}


