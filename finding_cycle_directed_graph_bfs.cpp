//finding cycle in directed graph bfs (kahn's algorithm)

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int n=1e3+10;
vector<int>adj[n];
vector<int>indegree(n,0);

bool is_cycle(int n)
{
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        for(int child:adj[i])
        indegree[child]++;
    }
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }

    int count=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        count++;
        for(int child:adj[node])
        {
            indegree[child]--;
            if(indegree[child]==0)
            q.push(child);
        }
    }
    if(count==n)
    return true;
    return false;

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
    }
    bool a;
    a=is_cycle(n);
    if(a==true)
    cout<<"No cycle is not present";
    else
    cout<<"Yes cycle is present ";
    return 0;
}
