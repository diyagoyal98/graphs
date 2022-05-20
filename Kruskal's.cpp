//Krushkal's

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v1;
    int v2;
    int wt;
    node(int first,int second,int weight)
    {
        v1=first;
        v2=second;
        wt=weight;
    }
};

bool comp(node a,node b)
{
    return a.wt<b.wt;
}

int findpar(int u,vector<int>&parent)
{
    if(u==parent[u])
    return u;
    return findpar(parent[u],parent);
}

void unionn(int u,int v,vector<int>&parent,vector<int>&rank)
{
    u=findpar(u,parent);
    v=findpar(v,parent);
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v]=u;
    }
    else
    {
        parent[v]=u;
        rank[u]++;
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<node>edges;
    for(int i=0;i<m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        edges.push_back(node(v1,v2,wt));
        //edges.push_back(node(v2,v1,wt));

    }
    sort(edges.begin(),edges.end(),comp);
    vector<int>parent(n);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    
    vector<int>rank(n,0);

    int cost=0;
    vector<pair<int,int>>mst;
    for(auto it:edges)
    {
        if(findpar(it.v1,parent)!=findpar(it.v2,parent))
        {
            cost+=it.wt;
            mst.push_back({it.v1,it.v2});
            unionn(it.v1,it.v2,parent,rank);
        }
    }
    cout<<"Cost "<<cost<<endl;
    for(auto it :mst)
    {
        cout<<it.first<<"->"<<it.second<<endl;
    }
    return 0;
}