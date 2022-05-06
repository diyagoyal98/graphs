#include<bits/stdc++.h>
using namespace std;

const int n=1e3+10;
int graph[n][n];//global and global things are always zero
//space comp O(n^2)
int main()
{
    int n,m;//vertices,edges
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1][v2]=1;
        graph[v2][v1]=1;//undirected graph

    }
    cout<<"Our graph .........."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(graph[i][j]==1)
            cout<<i<<"--->"<<j<<endl;
        }
    }
}

//advantages
/*
1-> i,j are connected or not ?? or i,j weight???? 
ans->O(1)
if(graph[i][j]==1)
{
    cout<<"Yes connnected";
}
We can't store bigger graph here */