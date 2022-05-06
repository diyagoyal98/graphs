//Finding connected Compontens in an undirected graph using dfs
//Finding a loop in a graph using dfs

#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<int>g[n];


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    return 0;
}