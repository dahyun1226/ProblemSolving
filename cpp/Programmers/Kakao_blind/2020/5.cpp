//라인스위핑
//세그먼트 트리
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int toint(string a) {
  return stoi(a.substr(0, 2)) * 3600 + stoi(a.substr(3, 2)) * 60 +
         stoi(a.substr(6, 2));
}

string solution(string play_time, string adv_time, vector<string> logs) {
  string answer = "";
  int total = toint(play_time);
  int ad = toint(adv_time);
  priority_queue<pair<int, bool>, vector<pair<int, bool>>,
                 greater<pair<int, bool>>>
      pq;
  for (int i = 0; i < logs.size(); i++) {
    pq.push(make_pair(toint(logs[i].substr(0, 8)), 0));
    pq.push(make_pair(toint(logs[i].substr(9, 8)), 1));
  }
  
  for (int i = pq.top().first; i <= total - ad; i++){
      
  }
    return answer;
}