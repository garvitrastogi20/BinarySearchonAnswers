#include<bits/stdc++.h>
using namespace std;
int maxelement(vector<int>& piles)
{
    int maxi=INT_MIN;
    for(int i=0;i<piles.size();i++)
    {
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}
long long calculatetotalhours(vector<int>& piles,int hourly)
{
    long long totalh=0;
    for(int i=0;i<piles.size();i++)
    {
        totalh+=(piles[i]+hourly-1)/hourly;
    }
    return totalh;
}
int minEatingSpeed(vector<int>& piles,int h)
{
    int low=1;
    int high=maxelement(piles);
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        long long totalh=calculatetotalhours(piles,mid);
        if(totalh<=h)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return low;
}
int main()
{
    int n,h;
    cout<<"Enter number of piles: ";
    cin>>n;
    vector<int> piles(n);
    cout<<"Enter pile sizes: ";
    for(int i=0;i<n;i++)
    {
        cin>>piles[i];
    }
    cout<<"Enter total hours (h): ";
    cin>>h;
    int ans=minEatingSpeed(piles,h);
    cout<<"Minimum Eating Speed = "<<ans<<endl;
    return 0;
}