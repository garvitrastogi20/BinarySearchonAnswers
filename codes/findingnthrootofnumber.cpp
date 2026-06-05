#include<bits/stdc++.h>
using namespace std;

int func(int n, int m, int mid)
{
    long long ans= 1;
    for(int i=0;i<n;i++)
    {
        ans= ans* mid;
        if(ans> m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}

int findingnthroot(int n, int m)
{
    int low= 1, high=m;
    while(low<= high)
    {
        int mid= low+(high-low)/2;
        int midn= func(n,m, mid);
        if(midn==1) return mid;
        else if(midn==2) high= mid-1;
        else{
            low= mid+1;
        }      
    }
    return -1;
}

int main()
{
    int n, m;
    cout<<"Enter the number: ";
    cin>>m;
    cout<<"Enter which root you want you want to find: ";
    cin>>n;
    int ans= findingnthroot(n,m);
    cout<<ans;
    return 0;
}