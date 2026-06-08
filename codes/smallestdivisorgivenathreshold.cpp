// threshold-> given a number 
// the problem is that:
// suppose the array: 1 2 5 9  threshold= 6
// try while taking any integer
// 1/4 2/4 5/4 9/4
// now we take the ceil value of the result
// 0.25 0.5 1.25 2.25
// ceil values: 1 1 2 3 
// if we sum them the value comes out to be 7> threshold
// now solve using taking 5 and so on while you got your answer

#include<bits/stdc++.h>
using namespace std;

int possible(vector<int>& arr,int limit,int l,int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=ceil((double)arr[i]/l);
	}
	if(sum<=limit) return true;
	else{
		return false;
	}
}
int smallestDivisor(vector<int>& arr,int limit)
{
	int n=arr.size();
	int ans=-1;
	int mx=*max_element(arr.begin(),arr.end());
	int low=1,high=mx;
	while(low<=high)
	{
		int mid=low+(high-low)/2;

		if(possible(arr,limit,mid,n)==true)
		{
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int limit;
	cin>>limit;
	cout<<smallestDivisor(arr,limit);
	return 0;
}

