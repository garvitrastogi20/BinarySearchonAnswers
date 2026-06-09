#include<bits/stdc++.h>
using namespace std;

int sumw(vector<int>& weights,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=weights[i];
    }
    return sum;
}

int func(vector<int>& weights,int cap,int n)
{
    int day=1,load=0;

    for(int i=0;i<n;i++)
    {
        if(load+weights[i]>cap)
        {
            day++;
            load=weights[i];
        }
        else
        {
            load+=weights[i];
        }
    }

    return day;
}

int shipWithinDays(vector<int>& weights,int days)
{
    int n=weights.size();
    int ans=-1;

    int low=*max_element(weights.begin(),weights.end());
    int high=sumw(weights,n);

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        int daysr=func(weights,mid,n);

        if(daysr<=days)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int> weights(n);

    for(int i=0;i<n;i++)
    {
        cin>>weights[i];
    }

    int days;
    cin>>days;

    cout<<shipWithinDays(weights,days);

    return 0;
}