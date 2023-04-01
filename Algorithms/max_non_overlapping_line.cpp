/* 

Given a number of line segments with start and end on x-axis,
find the maximum  number of non-overlapping lines.

Idea: 
    -- Sort line segments according to end
    -- Loop all line segments and add each if its start is not overlapping 
       with previously added end.

Time Complexity : O(n logn)  n = # line segments  

Problems : 
    -- Attending workshops : https://www.hackerrank.com/challenges/attending-workshops/problem

*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define FOR(n) for(int i=0;i<(n);i++)

typedef vector<int> vi;

class Line{
public:
    int start;
    int end;
    Line(int start, int end):start(start),end(end){}
};

int max_non_overlapping_line(vector<Line> & v)
{
    int count = 0;
    int last =0;
    sort(v.begin(),v.end(),[](Line x, Line y){return x.end < y.end;});

    for(auto x: v){
        if(x.start >= last)
        {
            count++;
            last=x.end;
        }
    }
    return count;
}

int main()
{
    // number of line segments
    int n; cin>>n;
    
    int start[n];
    vector<Line> lines;
    
    // read start of line segments
    FOR(n) cin>>start[i];

    // read length of line segments and create vector of Line objects.
    int temp;
    FOR(n) 
    {
        cin>>temp;
        lines.emplace_back(start[i],start[i]+temp);
    }

    // max line segments
    cout<<max_non_overlapping_line(lines)<<endl;
    
    return 0;
}