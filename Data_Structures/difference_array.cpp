/*

Difference Array 

Usage:
    -- All  range update queries are before any get operation.
    -- update operations are commutative 
    -- complementary operation exists ('plus' -> 'minus')

Time Complexity :
    Range updates : O(1)
    Get : O(n)

Space Complexity : O(n) -> Difference array

Idea: 
    1. Update(l,r,k) : update elements from range l to r  with k (add k , subtract k, multiply k ...)
        -- DA[l] += k;
        -- DA[r+1] -= k;
    2. Final array
        -- Prefix sum of DA are the elements of final array;


Problems :
    -- Array Manipulation : https://www.hackerrank.com/challenges/crush/problem

*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>

#define FOR(n) for(int i=0;i<(n);i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int,int>> vii;

int main()
{
    ios_base::sync_with_stdio(0);
    // cin.tie(NULL);

    // read input array
    int n;
    cin>>n;
    int arr[n];
    FOR(n){cin>>arr[i];};

    // Initialize difference array of size n+1 to 0
    ll *DA = new ll[n+1]();

    // read queries (l,r,k)
    int q;
    cin>>q;
    int l,r,k;
    FOR(q)
    {
        cin>>l>>r>>k;

        // Update difference array
        DA[l]+=k;
        DA[r+1]-=k;
    }

    // Final array elements are prefix sum of DA
    ll presum =0;
    vi result;
    FOR(n)
    {
        presum+=DA[i];
        result.push_back(presum + arr[i]);
    }

    // Output array
    for(auto x: result){cout<<x<<" ";}

    delete DA;

    return 0;
}