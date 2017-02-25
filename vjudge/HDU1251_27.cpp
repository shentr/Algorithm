// HDU1251
//http://acm.hdu.edu.cn/showproblem.php?pid=1251


#include<cstdio>
#include<cstring>
struct node
{
    int count;
    node* next[26];
    node(){
        count=0;
        memset(next,0,sizeof(next));
    }

};
  node* root=NULL;
  void build(char* s)
  {
      node* p=root;
      int len;
      len=strlen(s);
      int i;
      for(i=0;i<len;i++)
      {
          if(!p->next[s[i]-'a'])

             {
                p->next[s[i]-'a']=new node;
             }
          p=p->next[s[i]-'a'];
          p->count++;
      }
  }
  void find(char* s)
  {
      int i;
      node* p=root;
      int len=strlen(s);
      for(i=0;i<len;i++)
      {
          if(!p->next[s[i]-'a'])
          {
              printf("0\n");
              return ;
          }
          else
          p=p->next[s[i]-'a'];
       }
      printf("%d\n",p->count);
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
      root=new node;
      char str[30];
      while(gets(str))
      {
          if(!strcmp(str,""))

            {
              break;
            }
              build(str);
      }

      while(gets(str))
     {
          find(str);
     }
     del(root);
      return 0;
  }

