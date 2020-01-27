#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<string.h>

using namespace std;

int table[100];

void shifttable(string p,int n)
{
    for(int i=0;i<250;i++)
        table[i]=n-1;
    for(int j=0;j<n-1;j++)
    {
        table[p[j]]=n-1-j;
    }
}
void Horspool(string p,string t)
{
     int i=p.size()-1,m=t.size();
     int n=p.size();
   while(i<=m-1)
   {
       //cout<<i<<endl;
       int k=0;
       while((k<=n-1)&&(p[n-1-k]==t[i-k]))
       {
            k=k+1;
       }
       if(k==n)
       {
           cout<<"the string is found at position"<<i-n+2;
           return;
       }
       else
        {
             i=i+table[t[i]];
        }
   }
   cout<<"no key is found"<<endl;
}
int main()
{
   cout<<"enter the pattern and text"<<endl;
   string p,t;
   getline(cin,p);
   getline(cin,t);
   int n=p.size();
   //cout<<n;
   //cout<<p<<t;
   //cout<<endl<<p<<":"<<t<<endl;
   shifttable(p,n);
   Horspool(p,t);
}
