#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int n=1e5+10;
vector<int>g[n];
int vist[n];
int level[n];
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    vist[source]=1;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        cout<<curr<<"   ";
        for(int child :g[curr])
        {
            if(!vist[child])
            {
                q.push(child);
                vist[child]=1;
                level[child]=level[curr]+1;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bfs(1);
    for(int i=0;i<=n;i++)
    {
        cout<<i<<": "<<level[i]<<endl;
    }
}


//bfs gives us shortest path between source and destination and *condition applied - all the edges are weight less or equal weight
