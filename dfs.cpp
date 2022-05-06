#include<bits/stdc++.h>
using namespace std;
const int n=1e3+10;
vector<int>g[n];
bool status[n];

void dfs(int vertex)
{
    cout<<vertex<<endl;
    status[vertex]=true;
    //Take action on vertex after entering the vertex
    for(int child:g[vertex])
    {
        cout<<"Parent "<<vertex<<" "<<"Child "<<child<<endl;
        if(status[child]) continue;
        //Take action on child before entering the child node
        dfs(child);
        //Take action on child after existing chil node
    }
    //Take action on vertex before existing the vertex
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
    dfs(0);
    return 0;
}