#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;
int c;
int visited[10];
int v[10][10];
vector< vector<int> > x(10);
void bfs(int a,int n);
void BFS(int n)
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    c=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
            bfs(i,n);
    }
}

void bfs(int a,int n)
{
    c=c+1;
    visited[a]=c;
    deque <int> q;
    q.push_back(a);
    while(!q.empty())
    {
        a=q[0];
        for(int i=0;i<x[a].size();i++)
        {
            cout<<x[a][i]<<"  ";
            if(visited[x[a][i]]==0)
            {
                c++;
                visited[x[a][i]]=c;
                q.push_back(x[a][i]);
            }
        }
       /* for(int k=0;k<q.size();k++)
            cout<<q[k]<<"  ";*/
        cout<<endl;
        q.pop_front();
    }

}

int main()
{
    cout<<"enter the number of vertices"<<endl;
    int n;
    cin>>n;
    cout<<"enter the connection in matrix form"<<endl;

    for(int i=0;i<n;i++)
        {
            //visited[i]=0;
            for(int j=0;j<n;j++)
                cin>>v[i][j];
        }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]==1)
            {
                x[i].push_back(j);
            }
        }
    }
    //adjacent vertices of each vertex
   /* for(int i=0;i<n;i++)
    {
        for(int j=0;j<x[i].size();j++)
        {
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }*/
    BFS(n);
    for(int i=0;i<n;i++)
    {
        cout<<i<<"    "<<visited[i]<<endl;
    }

}
