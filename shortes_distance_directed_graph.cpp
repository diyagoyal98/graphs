#include<bits/stdc++.h>
using namespace std;

const int n=1e3+10;
vector<pair<int,int>>adj[n];
vector<int>visited(n,0);
//vector<int>distance(n,1e9);

void toposort(int i,stack<int>&s)
{
    visited[i]=1;
    for(auto child:adj[i])
    {
        if(visited[child.first]==0)
        toposort(child.first,s);
    }
    s.push(i);
}
void find_shortest_path(int src,int n)
{
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            toposort(i,s);
        }
    }    
    int distance[n];
    for(int i=0;i<n;i++)
    {
        distance[i]=1e9;
    }
    distance[src]=0;
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        if(distance[node]!=INT_MAX)
        {
            for(auto child :adj[node])
            {
                if(distance[node]+child.second<distance[child.first])
                {
                    distance[child.first]=distance[node]+child.second;
                }
            }
        }

    }
    for(int i=0;i<n;i++)
    {
        cout<<distance[i]<<"  ";
    }
}







int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        adj[v1].push_back({v2,wt});
    }
    find_shortest_path(0,n);
}
