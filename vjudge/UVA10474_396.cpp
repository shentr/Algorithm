// UVA10474
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=10474


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
 using namespace std;
 int main()
 {

	int a[10005],b[10005],hash[10005];
 	int N,Q,t=1;
 	while(cin>>N>>Q)
 	{
 		if((N==0)&&(Q==0))
 		{
 			break;
 		}
 		memset(hash,-1,sizeof(hash));
 		for(int i=0;i<N;i++)
 		{
 			cin>>a[i];
 		}
 		sort(a,a+N);
 		for(int i=0;i<N;i++)
 		{
 			if(a[i]!=a[i-1])
                hash[a[i]]=i+1;
 		}
 		for(int i=0;i<Q;i++)
 		{
 			cin>>b[i];
 		}
 		printf("CASE# %d:\n",t++);
 		for(int i=0;i<Q;i++)
 		{
 			if(hash[b[i]]!=-1)
 			{
 				 printf("%d found at %d\n",b[i],hash[b[i]]);
 			}
 			else
            {
            	printf("%d not found\n",b[i]);
            }
 		}
 	}
 	return 0;
 }
