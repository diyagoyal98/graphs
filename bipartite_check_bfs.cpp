//bipartite ???

#include<iostream>
#include<queue>
using namespace std;


const int n=1e3+10;
vector<int>adj[n];
vector<int>colour(n+1,-1);

bool is_bipartite(int i)
{
    queue<int>q;
    q.push(i);
    colour[i]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int child: adj[node])
        {
            if(colour[child]==-1)
            {
                colour[child]=1-colour[node];
                q.push(child);
            }
            else if(colour[child]==colour[node])
            return false;
        }
    }
    return true;
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
        adj[v2].push_back(v1);
    }
    for(int i=0;i<n;i++)
    {
        if(colour[i]==-1)
        {
            if(!is_bipartite(i))
            {
                cout<<"NO biparited ";
                exit(0);
            }
        }
    }
    cout<<"Yes biparted ";
    return 0;
}