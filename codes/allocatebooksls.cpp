#include <bits/stdc++.h>
using namespace std;

int func(vector<int>&arr, int n, int mid)
{
    int stu= 1, noofpages= 0;
    for(int i=0;i<n;i++)
    {
        if(noofpages+arr[i]<=mid)
        {
            noofpages+= arr[i];
        }
        else{
            stu++;
            noofpages=arr[i];
        }
    }
    return stu;
}

int findPages(vector<int>& arr, int n, int m)
{
    int s= arr.size();
    if(n<m) return -1;
    int low= *max_element(arr.begin(), arr.end());
    int high= 0;
    for(int i=0;i<s;i++)
    {
        high+= arr[i];
    }
    for(int i=low;i<high;i++)
    {
        int cnt= func(arr, n, i);
        if(cnt==m) return i;
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
    cout << findPages(arr, n, m) << endl;
    return 0;
}