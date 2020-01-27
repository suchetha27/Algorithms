#include<iostream>
#include<deque>
using namespace std;
int a[10][10];
int v[10],countt;

void dfs(int x,int n)
{
    deque <int> y;
    countt+=1;
    v[x]=countt;
    for(int i=0;i<n;i++)
    {
        if(a[x][i]==1)
            y.push_back(i);
    }
    cout<<"for"<<x<<endl;
    for(int i=0;i<y.size();i++)
    {
        cout<<y[i]<<"   ";
    }
    cout<<endl;
    for(int i=0;i<y.size();i++)
    {
        if(v[y[i]]==0)
        {
            y.clear();
            dfs(y[i],n);
        }
    }
}
void DFS(int n)
{
    countt=0;
    for(int i=0;i<n;i++)
        v[i]=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            dfs(i,n);
        }
    }
}
int main()
{
    cout<<"enter number of vertex"<<endl;
    int n;
    cin>>n;
    cout<<"enter matrix"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    DFS(n);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<"   "<<i<<endl;
    }
}
