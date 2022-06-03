#include<bits/stdc++.h>
using namespace std;

void bfs(int v,vector<int>adj[])
{
    vector<int>bfs_ans;
    vector<int>visited(v,0);
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            queue<int>q;
            q.push(i);
            visited[i]=1;
            
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                bfs_ans.push_back(node);
                
                for(auto child:adj[node])
                {
                    if(!visited[child])
                    {
                        q.push(child);
                        visited[child]=1;
                    }
                }
            }
        }
    }
    
    for(int i=0;i<v;i++)
    {
        cout<<bfs_ans[i]<<"    ";
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
    }
    bfs(n,adj);
    
    return 0;
}