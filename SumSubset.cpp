#include <iostream>
#include<deque>

using namespace std;
int a[10],count=0
;
void print(deque <int> sub)
{
    count++;
    for(int i=0;i<sub.size();i++)
        cout<<sub[i]<<"  ";
    cout<<endl;
}
int subsum(deque <int> sub)
{
    int sum=0;
    for(int i=0;i<sub.size();i++)
        sum=sum+sub[i];
    return sum;
}
void subset(int n,deque <int> sub,int x,int sum)
{
    if(sum==subsum(sub))
    {print(sub);}
    for(int i=x;i<n;i++)
    {
        sub.push_front(a[i]);
        if(sub[0]!=sub[1])
        {
        subset(n,sub,i,sum);
        sub.pop_front();
        }
        else
          sub.pop_front();
    }
}
int main()
{
    deque <int> sub;
    int x;
    cout<<"enter n"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    subset(n,sub,0,6);
    cout<<count<<endl;
}
