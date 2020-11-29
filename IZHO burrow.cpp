#include <bits/stdc++.h>

using namespace std;
int n,m,k,rez;
int prt[1001];
int sz[1001];
vector<int> nextt[1001];
int mat[1001][1001];
int cur[1001];
int findd(int x)
{
    while(x!=prt[x])
    {
        prt[x]=prt[prt[x]];
        x=prt[x];
    }
    return x;
}
void unionn(int x,int y)
{
    x=findd(x);
    y=findd(y);
    if(x==y)return;
    if(sz[x]<sz[y])swap(x,y);
    prt[y]=x;
    sz[x]+=sz[y];
    sz[y]=0;
}
void solve(int ind)
{
   for(int i=0;i<=m;i++)
   {
       nextt[i].clear();
   }
   for(int i=1;i<=n;i++)
   {
       nextt[cur[i]-ind].push_back(i);
   }
   for(int i=1;i<=n;i++)
   {
       prt[i]=-1;
       sz[i]=1;
   }
   for(int j=m;j>=1;j--)
   {
       for(int i=0;i<nextt[j].size();i++)
       {
           int f=nextt[j][i];
           prt[f]=f;
           if(f>1 && prt[f-1]!=-1)
           {
               unionn(f,f-1);
           }
           if(f<n && prt[f+1]!=-1)
           {
               unionn(f,f+1);
           }
           rez=max(rez,j*sz[findd(f)]);
       }
   }
}
int check(int x)
{
    rez=0;
    for(int i=1;i<=n;i++)
    {
        cur[i]=m+1;
    }
    for(int j=m;j>=1;j--)
    {
        for(int i=1;i<=n;i++)
        {
            if(mat[i][j]<x)cur[i]=j;
        }
        solve(j);
    }
    return rez;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> mat[i][j];
        }
    }
    int l=1;
    int r=1000000000;
    int med;
    while(l<=r)
    {
        med=(l+r)/2;
        if(check(med)>=k)
        {
            l=med+1;
        }
        else
        {
            r=med-1;
        }
    }
    cout << l-1 << ' '<<check(l-1);
    return 0;
}
