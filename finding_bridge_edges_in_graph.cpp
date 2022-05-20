//Finding bridge edges in graph

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int>&visited, vector<int>&tin, vector<int>&low, int &timer, vector<int>adj[])
{
    visited[node]=1;
    tin[node]=low[node]=timer++;
    for(auto it:adj[node])
    {
        if(it==parent) continue;
        if(!visited[it])
        {
            dfs(it,node,visited,tin,low,timer,adj);
            low[node]=min(low[node],low[it]);
            if(low[it]>tin[node])
            {
                cout<<node<<"   "<<it<<endl;
            }
        }
        else
        {
            low[node]=min(low[node],tin[it]);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    vector<int>tin(n,-1);
    vector<int>low(n,-1);
    vector<int>visited(n,0);
    int timer=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        dfs(i,-1,visited,tin,low,timer,adj);
    }
    return 0;
}





