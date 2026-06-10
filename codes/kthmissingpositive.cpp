#include<bits/stdc++.h>
using namespace std;

int kthmissingpositive(vector<int> a, int k)
{
    int n= a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]<=k)
        {
            k++;
        }
        else{
            break;
        }
    }
    return k;
}

int main()
{
    vector<int> a= {2,3,4,7,11};
    int k;
    cin>>k;
    int m= kthmissingpositive(a,k);
    cout<<m;
    return 0;
}