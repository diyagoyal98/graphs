#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<pair<int,int>>graph[n];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back({v2,wt});
        graph[v2].push_back({v1,wt});
    }
    for(auto i:graph)
    {
        cout<<"Vertex "<<i.first<<"  ";
        for(auto j:i.second)
        {
            cout<<"Weight "<<j;
        }
    }
    
}