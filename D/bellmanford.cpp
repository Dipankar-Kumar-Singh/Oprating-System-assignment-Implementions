#include <bits/stdc++.h>
using namespace std;
int const INF = 1e9 ;

signed main()
{   
    int n ; cin >> n ; // No of Vertex
    int m ; cin >> m ; // NO of Edges 

    vector<tuple<int, int, int>> edge;  // vector of edge[a ,b, wt] 
    vector<int> dis(n + 1, INF);

    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        edge.push_back({x, y, wt});
    }

    dis[1] = 0 ;
    bool relaxDone = 0;

    for (int i = 0; i < n; ++i)
    {
        relaxDone = 0 ; // if at Last Itration => relaxation happnes ---> negavive cycle
        for (auto [x, y, wt] : edge)
        {
            if (dis[x] < INF)
                if (dis[x] + wt < dis[y])
                    dis[y] = dis[x] + wt  , relaxDone = 1;
        }
    }

    if(relaxDone == true)
        cout << "negative cycle" ;

    else 
        for(int i = 1; i <= n ;i++) 
            cout << dis[i] << " " ;
}