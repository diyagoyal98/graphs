//checking cylce in undirected graph using bfs

#include<iostream>
#include<vector>
#include<queue>


using namespace std;

const int n=1e3+10;
vector<int>adj[n];
bool status[n];

bool cycle_bfs(int i)
{
    queue<pair<int,int>>q;
    status[i]=true;
    q.push({i,-1});
    while(!q.empty())
    {
        int node=q.front().first;
        int par=q.front().second;
        q.pop();
        for(int j:adj[node])
        {
            if(!status[j])
            {
                status[j]=true;
                q.push({j,node});
            }
            else if(par!=j)
            {
                return true;
            }
        }    
    }
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
        adj[v2].push_back(v1);
    }

    for(int i=0;i<n;i++)
    {
        if(!status[i])
        {
            if(cycle_bfs(i))
            {
                cout<<"Yes cycle exists ";
                exit(0);
            }
        }
    }
    cout<<"Not exists  ";
    return 0;
}