/*
백준 온라인 저지
14942번 개미
https://www.acmicpc.net/problem/14942
희소 테이블 문제.
int 범위로 해결 가능하다.
막막한 부분은, 한 굴에서 갈 수 있는 굴이 다양하다는 점이다. 어디쪽이 1에 가까운지 알 수 없다.
n-1이라는 것으로 트리라는 것을 알 수 있다. 방향을 알기 위해서 dfs부터 하고 방향을 정한 뒤에,
원래 희소 테이블을 활용해주면 된다.
20200416
*/
#include <iostream>
#include <cstdio>
#include <vector>
#define mp make_pair 
using namespace std;
pair<int,int> denDirection[100001][20];
int antEnergy[100001];
bool isChecked[100001];
vector<pair<int,int>> adj[100001]; 
int n;

void dfs(int start){
isChecked[start]=1;
for(int i=0;i<adj[start].size();i++)
{
int end = adj[start][i].first;
int energy=adj[start][i].second;
if(isChecked[end]==0){denDirection[end][0]=mp(start,energy);dfs(end);}
}
}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>n;
for(int i=1;i<=n;i++)
{cin>>antEnergy[i];isChecked[i]=0;}
for(int i=1;i<=n-1;i++)
{int a,b,e;
cin>>a>>b>>e;
adj[a].push_back(mp(b,e));  
adj[b].push_back(mp(a,e));  
}
denDirection[1][0]=mp(1,0);
dfs(1);
for(int i=1;i<=19;i++)
for(int j=1;j<=n;j++)
{
denDirection[j][i].first=denDirection[denDirection[j][i-1].first][i-1].first;
denDirection[j][i].second=denDirection[denDirection[j][i-1].first][i-1].second + denDirection[j][i-1].second;
}
for(int i=1;i<=n;i++)
{
    int now=i;
    int energyleft=antEnergy[i];
    for(int j=19;j>=0;j--)
        {
        if(denDirection[now][j].second<=energyleft)
            {
            energyleft-=denDirection[now][j].second;
            now=denDirection[now][j].first;
            }
        if(energyleft==0) break;
        }
    cout<<now<<"\n";
}
return 0;
}