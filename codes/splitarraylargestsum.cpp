#include<bits/stdc++.h>
using namespace std;
int func(vector<int>& arr, int mid, int n)
{
	int spl= 1;
	long long sum= 0;
	for(int i=0; i<n; i++)
	{
		if(arr[i]+ sum<= mid)
		{
			sum+=arr[i];
		}
		else{
			spl++;
			sum= arr[i];
		}
	}
	return spl;
}
int splitArray(vector<int> &arr, int k) {
	int n= arr.size();
	int low= *max_element(arr.begin(), arr.end());
	int high= 0;
	for(int i=0;i<n;i++)
	{
		high+= arr[i];
	}
	while(low<= high)
	{
		int mid= low+ (high-low)/2;
		int cnt= func(arr, mid, n);
		if(cnt<=k)
		{
			high= mid-1;
		}
		else{
			low= mid+1;
		}
	}
	return low;
}
int main()
{
    int n,k;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>k;
    cout<<splitArray(arr,k);
    return 0;
}