#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    int n,a;
    cin>>n>>a;
    string segmenttree[400000];
    string all;
    cin>>all;
    int treenum=1;
    while(treenum<n)treenum*=2;
    for(int i=0;i<treenum;i++)
    {if(i==a){segmenttree[treenum+i]="W";continue;}
        else if(i<n&&i<a)segmenttree[treenum+i]=all[i]string(1, c);
        else if(i<n&&i>a)segmenttree[treenum+i]=all[i-1];
        else segmenttree[treenum+i]="N";}
    for(int i=treenum-1;i>0;i--)
    {
    if(segmenttree[2*i][0]==segmenttree[2*i+1][0])segmenttree[i]="N";
    else if((segmenttree[2*i]=="R"||segmenttree[2*i+1]=="R")&&
        (segmenttree[2*i]=="P"||segmenttree[2*i+1]=="P"))
        {
        segmenttree[i]="P";
        }
    else if((segmenttree[2*i]=="R"||segmenttree[2*i+1]=="R")&&
        (segmenttree[2*i]=="S"||segmenttree[2*i+1]=="S"))
        {
        segmenttree[i]="R";
        }
    else if((segmenttree[2*i]=="S"||segmenttree[2*i+1]=="S")&&
        (segmenttree[2*i]=="P"||segmenttree[2*i+1]=="P"))
        {
        segmenttree[i]="S";
        }
    else if(segmenttree[2*i][0]=='N')
    {segmenttree[i]=segmenttree[2*i+1];}
    else if(segmenttree[2*i+1][0]=='N')
    {segmenttree[i]=segmenttree[2*i];}
    else if(segmenttree[2*i][0]=='W')
    {segmenttree[i]=segmenttree[2*i]+segmenttree[2*i+1];}
    else if(segmenttree[2*i+1][0]=='W')
    {segmenttree[i]=segmenttree[2*i+1]+segmenttree[2*i];}
    }
    int answer=0;
    for(int i=2;i<segmenttree[1].size();i++)
    {if(segmenttree[1][i-1]!=segmenttree[1][i])answer+=1;}
    for(int i=1;i<treenum*2;i++)
    cout<<segmenttree[i]<<endl;
    //cout<<answer;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}