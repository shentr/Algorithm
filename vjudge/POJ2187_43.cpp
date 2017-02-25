// POJ2187
//http://poj.org/problem?id=2187


#include<iostream>
#include<algorithm>
using namespace std;
const int inf=10001;
struct node
{
    int x,y;
};

int distsquare(node A,node B)
{
	return (B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y);
}

int det(int x1,int y1,int x2,int y2)
{
	return x1*y2-x2*y1;
}

int cross(node A,node B,node C,node D)
{
	return det(B.x-A.x , B.y-A.y , D.x-C.x , D.y-C.y);
}

node* p;
int cmp(const void* a,const void* b)
{
	node* s=(node*)a;
	node* t=(node*)b;

	int temp=cross(*p,*s,*p,*t);
	if(temp>0)
		return -1;

	else if(temp==0)
		return distsquare(*p,*t)-distsquare(*p,*s);

	else
		return 1;
}

int main(int i,int j)
{
	int n;
	while(cin>>n)
	{
		node* farm=new node[n+1];
		int* conbag=new int[n+2];


		int min_x=inf;
		int fi=0;
		for(i=1;i<=n;i++)
		{
			cin>>farm[i].x>>farm[i].y;

			if(min_x > farm[i].x)
			{
				min_x = farm[i].x;
				fi=i;
			}
			else if(min_x == farm[i].x)
			{
				if(farm[fi].y > farm[i].y)
					fi=i;
			}
		}
		farm[0]=farm[n];
		farm[n]=farm[fi];
		farm[fi]=farm[0];
        p=&farm[n];
		qsort(farm+1,n,sizeof(node),cmp);
		int pc=1;
		conbag[1]=n;
		conbag[++pc]=1;
		conbag[0]=2;

		for(i=2;i<=n;)
			if(cross(farm[ conbag[pc-1] ],farm[ conbag[pc] ],farm[ conbag[pc] ],farm[i]) >= 0)
			{
				conbag[++pc]=i++;
				conbag[0]++;
			}
			else
			{
				pc--;
				conbag[0]--;
			}
		int maxdist=0;
		for(i=1;i<=conbag[0]-2;i++)
			for(j=i+1;j<=conbag[0]-1;j++)
			{
				int temp=distsquare(farm[ conbag[i] ],farm[ conbag[j] ]);
				if(maxdist < temp)
					maxdist = temp;
			}
		cout<<maxdist<<endl;
		delete farm;
		delete conbag;
	}
	return 0;
}
