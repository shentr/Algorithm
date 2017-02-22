// 5920 ( Ugly Problem )
//acm.hdu.edu.cn/showproblem.php?pid=5920


#include"bits/stdc++.h"
using namespace std;
const int N=1e3+100;
char *s,*small;                 //指向字符串的指针(为了快速删除前缀0而如此定义)
char ss[N],sm[N];                //给字符串指针 分配初始空间   

void delete0(char * &ps)             //删除前缀0
{
    for(int i=0;i<strlen(ps);i++)
    {
        if(ps[i]!='0')
        {
            ps=&ps[i];
            return ;
        }
    }
    ps[0]=0;
}


void sub(int lens)                              //大数减法
{
    delete0(s);
    delete0(small);
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
        if(s[lens/2-1]>=s[lens/2])       //中间左大于右  其实这不考率也行，毕竟n>50  
        {
            int key;
            for(int i=lens/2-1;i>=0;i--)
                if(s[i]!='0')                       // 0特殊考虑
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
        else                                            ///和偶数时的处理一样
        {
            if(s[(lens+1)/2-2]>=s[(lens+1)/2])          //中间左大于右  
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
            delete0(s);
            lens=strlen(s);
            if(s[0]=='0'||lens==0)
                break;
            find_s();
            delete0(small);
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


