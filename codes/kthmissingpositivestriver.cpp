#include<bits/stdc++.h>
using namespace std;

int findmissing(vector<int> a, int k)
{
    int n= a.size();
    int low=0, high= n-1;
    while(low<= high)
    {
        int mid= low+(high-low)/2;
        int missing= a[mid]-(mid+1);
        if(missing<k) low= mid+1;
        else{
            high= mid-1;
        }
    }
    return (low+k);
}

int main()
{
    vector<int> a={2,3,4,7,11};
    int k;
    cin>>k;
    int m= findmissing(a,k);
    cout<<m;
    return 0;
}