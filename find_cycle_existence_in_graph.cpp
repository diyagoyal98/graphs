// Find cylce in the graph
#include<iostream>
#include<vector>
using namespace std;
const int N=1e3+10;
vector<int>g[N];
bool status[N];

bool dfs(int vertex,int par)
{
    
    status[vertex]=true;
    bool isloop_exists=false;
    //Take action on vertex after entering the vertex
    for(int child:g[vertex])
    {
        if(status[child]==1 && child==par) continue;
        if(status[child]) return true;
        //Take action on child before entering the child node
        isloop_exists|=dfs(child,vertex);
        //Take action on child after existing chil node
    }
    //Take action on vertex before existing the vertex
    return isloop_exists;
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool loop_exists=false;
    for(int i=1;i<=n;i++)
    {
        if(status[i])continue;
        if(dfs(i,0))
        {
            loop_exists=true;
            break;
        }
    }
    cout<<loop_exists;
}