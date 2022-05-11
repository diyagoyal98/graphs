//checking cycle in undirected graph using dfs

#include<iostream>
#include<vector>
using namespace std;
const int n=1e5+10;
vector<int>adj[n];
bool status[n];

bool is_cycle(int i , int par)
{
    status[i]=true;
    for(int child:adj[i])
    {
        if(status[child]==false)
        {
            if(is_cycle(child,i))
            return true;
        }
        else if(child!=par)return  true;
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
            if(is_cycle(i,-1))
            {
                cout<<"YES CYCLE EXISTS";
                exit(0);
            }
        }
    }
    cout<<"Not exists ";
}