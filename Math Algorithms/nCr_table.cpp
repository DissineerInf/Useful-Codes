/* 

Calculate nCr table with modvalue

Time Complexity : O(n^2)    

Idea : nCr = (n-1)Cr + (n-1)C(r-1) 
       if (r == 0 or n) -> nCr = 1 

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Max n and r (r<=n) values for computation. 
const int maxn = 11;
const int maxr = 11;
const ll modval = pow(10,9)+7;
ll arr[maxn][maxr];
void nCr_table(){
    for(int n = 0; n<maxn;n++)
    {
        for(int r = 0 ;r<=n;r++)
        {
            if (n==r || r == 0) arr[n][r]=1;
            else arr[n][r] = (arr[n-1][r] + arr[n-1][r-1])% modval;
        }
    }
}

int main()
{
    nCr_table();

    for(int n = 0; n<maxn;n++)
    {
        cout<<n<<" : ";
        for(int r = 0 ;r<=n;r++)
        {
            cout<<arr[n][r]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
