// POJ1185
//http://poj.org/problem?id=1185


#include <iostream>  
#include <vector>  
#include <string>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
#pragma warning(disable:4996)  
using namespace std;  
  
int hang[110];//hang[i]表示第i行的初始状态  
int state[80];//  
int solider[80];  
int dp[110][80][80];  
int row,col,i,j,k,h,he;  
char pb_state[15];  
  
int main()  
{  
    cin>>row>>col;  
  
    memset(hang,0,sizeof(hang));  
    memset(dp,0,sizeof(dp));  
    memset(solider,0,sizeof(solider));  
    memset(state,0,sizeof(state));  
  
    for(i=1;i<=row;i++)  
    {  
        cin>>pb_state;  
        for(j=0; j<col; j++)  
            if(pb_state[j]=='H') hang[i]+=1<<j;   
    }  
  
    he=1;  
    for(i=0;i<(1<<col);i++)  
    {  
        if((i&i<<1)||(i&i<<2)) continue;  
        state[he]=i;  
        int temp=i,num=0;  
        while(temp)  
        {  
            num += temp&1;  
            temp=temp>>1;  
        }  
        solider[he]=num;  
        he++;  
    }  
    for(i=1;i<he;i++)  
    {  
        if(state[i]&hang[1])continue;  
        dp[1][i][0]= solider[i];  
    }  
    for(i=1;i<he;i++)  
    {  
        if(state[i]&hang[2])continue;  
        for(j=1;j<he;j++)  
        {  
            if(state[i]&state[j])continue;  
            if(state[j]&hang[1]) continue;  
            dp[2][i][j]=max(dp[2][i][j],dp[1][j][0]+solider[i]);  
        }  
    }  
    for(h=3;h<=row;h++)  
    {  
        for(i=1;i<he;i++)//  
        {  
            if(state[i]&hang[h])continue;  
            for(j=1;j<he;j++)  
            {  
                if(state[j]&hang[h-1])continue;  
                if(state[j]&state[i])continue;  
                for(k=1;k<he;k++)  
                {  
                    if(state[k]&hang[h-2])continue;  
                    if(state[k]&state[i])continue;  
                    if(state[k]&state[j])continue;  
  
                    dp[h][i][j]=max(dp[h][i][j],dp[h-1][j][k]+solider[i]);  
                }  
            }  
        }  
    }  
    int ans=0;  
    for(i=1;i<he;i++)  
        for(j=0;j<he;j++)//！！！注意啊，这里一定是从0开始的，因为之前设置好的就是0啊。。。。。。。。。。。。。。。。。。  
            ans=max(ans,dp[row][i][j]);  
    cout<<ans<<endl;  
    //system("pause");  
    return 0;  
}  