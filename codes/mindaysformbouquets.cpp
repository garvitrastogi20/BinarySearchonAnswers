
// if we dont use the binary search, the range for this problem will be (minimum element)-> (maximum array)
// we use bs for range optimization

#include<bits/stdc++.h>
using namespace std;

int possible(vector<int>& arr, int day, int k, int m, int n)
{
	int cnt=0,num=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<= day){
			cnt++;
		}
		else{
			num+= (cnt/k);
			cnt=0;
		}
	}
	num+=(cnt/k);
	if(num>=m) return true;
	else{
		return false;
	}

}

int roseGarden(vector<int>& arr,int k,int m)
{
	int n= arr.size();
	int ans=-1;
	int low= *min_element(arr.begin(), arr.end());
	int high= *max_element(arr.begin(), arr.end());
	if((long long) m*k>n) return -1;

	while(low<= high)
	{
		int mid= low+(high-low)/2;
		if(possible(arr, mid,k,m,n)== true){
			ans= mid;
			high= mid-1;			
		}
		else{
			low= mid+1;
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
    int k,m;
    cin>>k>>m;
    cout<<roseGarden(arr,k,m);
    return 0;
}