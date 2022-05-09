//To store the connected components 

#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int>g[N];
bool status[N];
vector<vector<int>>connected_components;
vector<int>current_cc;
void dfs(int vertex)
{
    
    status[vertex]=true;
    current_cc.push_back(vertex);
    //Take action on vertex after entering the vertex
    for(int child:g[vertex])
    {
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
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(status[i]) continue;
        current_cc.clear();
        dfs(i);
        connected_components.push_back(current_cc);
        count++;
    }
    cout<<"No of connected components "<<connected_components.size()<<endl;

    for(auto c_cc:connected_components)
    {
        for(int vertex :c_cc)
        {
            cout<<vertex<<" ";
        }
        cout<<endl;
    }
    return 0;
}