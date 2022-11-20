#include<bits/stdc++.h>
using namespace std ;
#define int long long

signed main()
{
    int n , capacity ; 
    cin >> n >> capacity ;

    vector<vector<int>> dp(n + 10 , vector<int>(capacity + 10)) ;
    
    vector<int> v(n + 1) , w(n + 1) ;

    for(int i = 1 ; i <= n; i++)
        cin >> w[i] >> v[i] ;
    
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= capacity ; j++)
        {
            if(j - w[i] >= 0)
                dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int ans = dp[n][capacity] ;
    cout << ans << endl ;

    // vector<int> taken ;

    // int currsize = capacity ;
    // for(int i = 1 ; i <= n ;i++)
    // {
    //     if (dp[i][currsize] == dp[i - 1][currsize]) continue ;
    //     taken.push_back(i) ;
    //     currsize -= w[i] ;
    // }


    // cout << "Item Taken " << endl ;
    // for(auto item : taken) 
    //     cout << item << " w = " << w[item] << " v = " << v[item] << endl ;

}