// HDU1075
//http://acm.hdu.edu.cn/showproblem.php?pid=1075


#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>

using namespace std;

struct node{
    char dic[15];
    node * next[26];
    bool flag;
}*root;

node *build()
{
    node *p=(node *)malloc(sizeof(node));
    for(int i=0;i<26;i++)
        p->next[i]=NULL;
    p->flag=false;
    return p;
}

void insert(char *earth,char *mars)
{
    int len=strlen(mars);
    node *p;
    p=root;
    for(int i=0;i<len;i++)
    {
        if(p->next[mars[i]-'a']==NULL)
            p->next[mars[i]-'a']=build();
        p=p->next[mars[i]-'a'];
    }
    p->flag=true;
    strcpy(p->dic,earth);
}

void query(char *earth)
{
    int len=strlen(earth);
    node *p;
    p=root;
    for(int i=0;i<len;i++)
    {
        if(p->next[earth[i]-'a']==NULL)
        {
            printf("%s",earth);
            return;
        }
        p=p->next[earth[i]-'a'];
    }
    if(p->flag)
        printf("%s",p->dic);
    else
        printf("%s", earth);
}

void del(node *p)
{
    if(p==0)
        return ;
    int i;
    for(i=0;i<26;i++)
    {
        del(p->next[i]);
    }
    delete p;
}

int main()
{
    char earth[15],mars[15],ask[3010];
    scanf("%s",earth);
    root=build();
    while(scanf("%s",earth),strcmp(earth,"END"))
    {
        scanf("%s",mars);
        insert(earth,mars);
    }
    scanf("%s",earth);
    getchar();
    while(gets(ask))
    {
        if(ask[0]=='E')
            break;
        int len=strlen(ask);
        for(int i=0;i<len;i++)
        {
            if(islower(ask[i]))
            {
                int j=0;
                memset(earth,'\0',sizeof(earth));
                while(islower(ask[i]))
                    earth[j++]=ask[i++];
                query(earth);
            }
            if(!islower(ask[i]))
                printf("%c",ask[i]);
        }
        printf("\n");
    }
    del(root);
    return 0;
}
