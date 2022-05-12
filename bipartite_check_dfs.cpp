//bipartite graph dfs
#include<iostream>
#include<vector>
using namespace std;


const int n=1e3+10;
vector<int>adj[n];
vector<int>colour(n,-1);

bool is_bipartite(int i)
{
    if(colour[i]==-1)
    colour[i]=1;
    for(int child:adj[i])
    {
        if(colour[child]==-1)
        {
            colour[child]=1-colour[i];
            if(!is_bipartite(child))
            return false;
        }
        else if(colour[child]==colour[i])
        return false;
    }
    return true;
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
        if(colour[i]==-1)
        {
            if(!is_bipartite(i))
            {
                cout<<"Not bipartite ";
                exit(0);
            }
        }
    }
    cout<<"Yes bipartite";
    return 0;
}