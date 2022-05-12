//finding cycle in directed graph dfs

#include<iostream>
#include<vector>

using namespace std;
const int n=1e3+10;
vector<int>adj[n];
vector<int>visited(n,0);
vector<int>dfs_vis(n,0);

bool is_cycle(int i)
{
    visited[i]=1;
    dfs_vis[i]=1;
    for(int child:adj[i])
    {
        if(!visited[child])
        {
            if(is_cycle(child))
            return true;
        }
        else if(dfs_vis[i])
        return true;    
    }
    dfs_vis[i]=0;
    return false;
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(is_cycle(i))
            {
                cout<<"Yes cycle is present "<<endl;
                exit(0);
            }
        }
    }
    cout<<"Not present ";
    return 0;
}