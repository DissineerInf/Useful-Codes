/*

Calculate  a^-1  mod m

Idea: 
    -- a^phi(m) = 1 mod m  :   if (a,m) are co prime
    -- a^(m-1) = 1 mod m   :  phi(p)=p-1 if p is prime
    -- a^(m-2) = a^-1 mod m

    Ex: -- 28/7 mod 5 (=4)  
        -- 28mod5(=3) * 7inverse mod5(=3)  ->  3*3 mod 5(=4);

Time Complexity : O(log m)
*/

#include <iostream>
#include<cmath>

using namespace std;

typedef long long ll;

ll mod_expo(ll x, ll n ,ll m)
{
    ll result = 1;
    while(n>0){
        if(n&1) result = (result*x)%m;
        x= (x*x)%m;
        n>>=1;
    }
    return result;
}


ll mod_mul_inv(ll a, ll m)
{
    return mod_expo(a,m-2,m);
}


int main(){

    ll m =5;
    ll temp = (28%m) * mod_mul_inv(7,m);
    cout<<temp%m<<endl;

    return 0;
}
