#include<bits/stdc++.h>
using namespace std;

int squareroot(int n)
{
    if(n<2) return n;
    int low= 2, high=n/2;
    while(low<= high)
    {
        int mid= low+ (high-low)/2;
        if(mid*mid==n) return mid;
        else if(mid*mid<n){
            low= mid+1;
        }
        else{
            high= mid-1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int answer= squareroot(n);
    cout<<answer;
    return 0;
}