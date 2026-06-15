#include <bits/stdc++.h>
using namespace std;

int func(vector<int>& arr, int n, int mid)
{
    int stu=1;
    long long noofpages= 0;
    for(int i=0;i<n;i++)
    {
        if(noofpages+arr[i]<= mid)
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
    if(n<m) return -1;
    int low= *max_element(arr.begin(), arr.end());
    int high= 0;
    for(int i=0;i<arr.size();i++)
    {
        high+= arr[i];
    }
    while(low<= high)
    {
        int mid= low+(high-low)/2;
        int student= func(arr, n, mid);
        if(student>m) low= mid+1;
        else{
            high= mid-1;
        }
    }
    return low;
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