#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

void swapp(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}

int partition(int a[],int l,int r)
{
    int p=a[l];
    int i=l+1,j=r;
    while(!(i>=j))
    {
        while(!(a[i]>=p && i<=r))
        {
            i+=1;
        }
        while(!(a[j]<=p && j>=l))
        {
            j-=1;
        }
        swapp(a[i],a[j]);
    }
    swapp(a[i],a[j]);
    swapp(a[l],a[j]);
    return j;
}

void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int s=partition(a,l,r);
        quicksort(a,l,s-1);
        quicksort(a,s+1,r);
    }
    cout<<"array after sorting"<<endl;
    print(a,r+1);
}
int main()
{
    cout<<"enter the size of array"<<endl;
    int n;
    cin>>n;
    int *a= new(nothrow) int[n];
    if(!a)
        cout<<"no allocation of memory can occur"<<endl;
    else
    {
         cout<<"enter the elements of array"<<endl;
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<"array before sorting"<<endl;
        print(a,n);
        quicksort(a,0,n-1);
    }

    return 0;
}
