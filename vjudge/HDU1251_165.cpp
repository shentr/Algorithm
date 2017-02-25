// HDU1251
//http://acm.hdu.edu.cn/showproblem.php?pid=1251


#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define maxn 26
using namespace std;
typedef struct TrieNode
{
    int num;
    struct TrieNode *next[maxn];
}Trie;
void insert(Trie *root,char *str){
    if(root==NULL||*str=='\0'){
        return;
    }
    Trie *p=root;
    while(*str!='\0')
    {
        if(p->next[*str-'a']==NULL)
        {
            Trie *temp=(Trie*)malloc(sizeof(Trie));
           temp->num=1;
           for(int i=0;i<maxn;i++)
           {
               temp->next[i]=NULL;
           }
           p->next[*str-'a']=temp;
           p=p->next[*str-'a'];
        }
        else
        {
            p->next[*str-'a']->num++;
            p=p->next[*str-'a'];
        }
        str++;
    }
}
int search(Trie *root,char *str)
{
    Trie *p=root;
    for(int i=0;i<strlen(str);i++)
    {
        p=p->next[str[i]-'a'];
        if(p==NULL)
        {
            return 0;
            }
    }
    return p->num;
}
void del(Trie *root)
{
    for(int i=0;i<maxn;i++)
    {
        if(root->next[i]!=NULL)
        del(root->next[i]);
    }
    free(root);
}
int main()
{
    char str[15];
    memset(str,0,sizeof(str));
    Trie *root=(Trie*)malloc(sizeof(Trie));
    for(int i=0;i<maxn;i++)
   {
     root->next[i]=NULL;
   }
   while(gets(str)&&str[0])
   {
       insert(root,str);
   }
   while(gets(str)&&str[0])
   {
       printf("%d\n",search(root,str));
   }
   del(root);
    return 0;
}
