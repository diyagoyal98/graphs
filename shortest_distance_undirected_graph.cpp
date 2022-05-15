#include<bits/stdc++.h>
using namespace std;

const int n=1e3+10;
vector<int>adj[n];
vector<int>dis(n,INT_MAX);


void bfs(int src,int p)
{
    queue<int>q;
    dis[src]=0;
    q.push(src);
    while(q.empty()==false)
    {
        int node=q.front();
        q.pop();

        for(auto child:adj[node])
        {
            if(dis[node]+1<dis[child])
            {
                dis[child]=dis[node]+1;
                q.push(child);
            }
        }
    }
    for(int i=0;i<p;i++)
    {
        cout<<dis[i]<<"  ";
    }
}



int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    bfs(0,n);


    return 0;
}