#include<bits/stdc++.h>
using namespace std ;

int n ; 
vector<int> queen ;

bool check(int row , int col){
    for(int i = 0 ; i < row ; i++){
        int j = queen[i] ;
        if( j == col or abs(row - i ) == abs(col - j)) return 0 ;
    }
    return 1 ;
}

int solve(int currRow)
{
    if(currRow == n)  return 1 ;
    int ans = 0 ;
    for(int c = 0 ; c < n ; c++){
        if(check(currRow,c)){
            queen[currRow] = c ;
            ans += solve(currRow  + 1) ;
            queen[currRow] = -1 ;
        }
    }
    return ans ;
}

int main()
{
    cin >> n; 
    queen = vector<int> (n,-1) ;
    cout << solve(0)  << endl ;
}