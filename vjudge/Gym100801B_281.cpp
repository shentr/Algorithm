// Gym100801B
//undefined100801B


#include"bits/stdc++.h"

using namespace std;

int main()
{
    ifstream fin("black.in");
    ofstream fout("black.out");
    int b,w;
    while(fin>>b>>w)
    {
        int ans=(max(b,w)-min(b,w))*2+min(b,w)*2;
        fout<<ans<<" "<<11<<endl;
        int bb=b;
        int ww=w;
        while(bb<ww)
        {
            for(int i=0;i<=10;i++)
                fout<<"@";
            fout<<endl;
            fout<<".";
            for(int i=1;i<=10;i++)
                fout<<"@";
            fout<<endl;
            ww--;
        }
        while(ww<bb)
        {
            for(int i=0;i<=10;i++)
                fout<<".";
            fout<<endl;
            fout<<"@";
            for(int i=1;i<=10;i++)
                fout<<".";
            fout<<endl;
            bb--;
        }
        while(ww==bb&&ww>0)
        {
            if(w>b)
            {
                //for(int i=0;i<=10;i++)
                    //fout<<"@";
                    //fout<<endl;
                    while(ww)
                    {
                        for(int i=0;i<=10;i++)
                            fout<<"@";
                        fout<<endl;
                        for(int i=0;i<=10;i++)
                            fout<<".";
                        fout<<endl;
                        ww--;
                    }
            }
            else if(w<b)
            {
                //for(int i=0;i<=10;i++)
                   // fout<<".";
                    //fout<<endl;
                    while(ww)
                    {
                        for(int i=0;i<=10;i++)
                            fout<<".";
                        fout<<endl;
                        for(int i=0;i<=10;i++)
                            fout<<"@";
                        fout<<endl;
                        ww--;
                    }
            }
            else
            {
                while(ww)
                    {
                        for(int i=0;i<=10;i++)
                            fout<<"@";
                        fout<<endl;
                        for(int i=0;i<=10;i++)
                            fout<<".";
                        fout<<endl;
                        ww--;
                    }
            }
        }
        /*fout<<-100<<endl;
        int ans=0;
        if(b-w>=2&&b>1&&w>=1)
        {
            while(b>w&&b>1&&w>=1)
            {
                for(int i=0; i<=10; i++)
                    fout<<".";
                fout<<endl;

                for(int i=0; i<5; i++)
                    fout<<"@";
                fout<<".";
                for(int i=6; i<=10; i++)
                    fout<<"@";
                fout<<endl;
                for(int i=0; i<=10; i++)
                    fout<<".";
                fout<<endl;
                b-=2;
                ans+=3;
            }
              if(w-b==1)
            {
                for(int i=0; i<=10; i++)
                    fout<<"@";
                fout<<endl;
                w--;
                ans++;
            }
            else if(b-w==1)
            {
                for(int i=0; i<=10; i++)
                    fout<<".";
                fout<<endl;
                b--;
                ans++;
            }
            else if(b==w&&b>0&&w>0)
            {
                for(int i=0; i<=10; i++)
                    fout<<"@";
                fout<<endl;
                for(int i=0; i<=10; i++)
                    fout<<".";
                fout<<endl;
                b--;
                w--;
                ans+=2;

            }
        }
        else if(w-b>=2&&b>=1&&w>1)
        {
            while(w>b>=2&&b>=1&&w>1)
            {
                for(int i=0; i<=10; i++)
                    fout<<"@";
                fout<<endl;
                for(int i=0; i<5; i++)
                    fout<<".";
                fout<<"@";
                for(int i=6; i<=10; i++)
                    fout<<".";
                fout<<endl;
                for(int i=0; i<=10; i++)
                    fout<<"@";
                fout<<endl;
                w-=2;
                ans+=3;
            }
            if(w-b==1)
            {
                for(int i=0; i<=10; i++)
                    fout<<".";
                fout<<endl;
                w--;
                ans++;
            }
            else if(b-w==1)
            {
                for(int i=0; i<=10; i++)
                    fout<<"@";
                fout<<endl;
                b--;
                ans++;
            }
            else if(b==w&&b>0&&w>0)
            {
                for(int i=0; i<=10; i++)
                    fout<<".";
                fout<<endl;
                for(int i=0; i<=10; i++)
                    fout<<"@";
                fout<<endl;
                b--;
                w--;
               ans+=2;
            }
        }
        if(w-b==1)
            {
                for(int i=0; i<=10; i++)
                    fout<<".";
                fout<<endl;
                w--;
                ans++;
            }
            else if(b-w==1)
            {
                for(int i=0; i<=10; i++)
                    fout<<"@";
                fout<<endl;
                b--;
                ans++;
            }
            else if(b==w&&b>0&&w>0)
            {
                for(int i=0; i<=10; i++)
                    fout<<".";
                fout<<endl;
                for(int i=0; i<=10; i++)
                    fout<<"@";
                fout<<endl;
                b--;
                w--;
               ans+=2;
            }*/
    }
    return 0;
}
