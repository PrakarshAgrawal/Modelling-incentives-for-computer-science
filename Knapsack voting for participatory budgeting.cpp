
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=10;
    int val[] = {4,3,2,0,5,4,3,0,1,0};
    int cst [] = {30,20,20,5,35,35,10,10,20,15};
    int amt = 120;
    
    int dp[n+1][amt+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=amt;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
            else if(cst[i-1]>j||val[i-1]==0)
            {
                dp[i][j] = dp[i-1][j];
            }
            else 
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-cst[i-1]]+val[i-1]);
        }
    }
    vector<int> r;
    int res = dp[n][amt];
    int j=amt;
    for(int i=n;i>0&&res>0;i--)
    {
        if(res==dp[i-1][j])
        continue;
        else
        {
            r.push_back(i);
            res = res - val[i-1];
            j = j-cst[i-1];
        }
    }
    for(int i=0;i<r.size();i++)
    cout<<r[i]<<" "<<val[r[i]-1]<<endl;
    cout<<endl<<dp[n][amt];
    return 0;
}
