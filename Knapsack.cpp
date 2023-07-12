#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int val[N],wt[N];
int dp[N][N];
int knapsack(int n,int w)
{
    if(w<=0)
    {
        return 0;
    }
    if(n<=0)
    {
        return 0;
    }
    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }
    if(wt[n-1]>w)
    {
        dp[n][w]= knapsack(n-1,w);
    }
    else
    {
        dp[n][w]= max(knapsack(n-1,w),knapsack(n-1,w-wt[n-1])+val[n-1]);
    }

    return dp[n][w];
}
int main()
{
    freopen("knap.txt", "r", stdin);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>wt[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>val[i];
    }
    int w;
    cin>>w;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<knapsack(n,w)<<endl;
}

