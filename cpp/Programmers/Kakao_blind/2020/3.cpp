#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> infos[4][3][3][3];
vector<int> solution(vector<string> info, vector<string> query) {
  vector<int> answer;
  for (int i = 0; i < info.size(); i++) {
    int a, b, c, d;
    if (info[i][0] == 'j') {
      a = 1;
      info[i] = info[i].substr(5, info[i].size() - 4);
    } else if (info[i][0] == 'c') {
      a = 0;
      info[i] = info[i].substr(4, info[i].size() - 3);
    } else if (info[i][0] == 'p') {
      a = 2;
      info[i] = info[i].substr(7, info[i].size() - 6);
    }
    ///////1
    if (info[i][0] == 'f') {
      b = 1;
      info[i] = info[i].substr(9, info[i].size() - 8);
    } else if (info[i][0] == 'b') {
      b = 0;
      info[i] = info[i].substr(8, info[i].size() - 7);
    }
    //////2
    if (info[i][0] == 'j') {
      c = 0;
      info[i] = info[i].substr(7, info[i].size() - 6);
    } else if (info[i][0] == 's') {
      c = 1;
      info[i] = info[i].substr(7, info[i].size() - 6);
    }
    /////3
    if (info[i][0] == 'c') {
      d = 0;
      info[i] = info[i].substr(8, info[i].size() - 7);
    } else if (info[i][0] == 'p') {
      d = 1;
      info[i] = info[i].substr(6, info[i].size() - 2);
    }
    for (int q = a; q < 4; q++) {
      for (int w = b; w < 3; w++) {
        for (int e = c; e < 3; e++) {
          for (int r = d; r < 3; r++) {
            infos[q][w][e][r].push_back(stoi(info[i]));
            if (r < 2)
              r = 1;
          }
          if (e < 2)
            e = 1;
        }
        if (w < 2)
          w = 1;
      }
      if (q < 3)
        q = 2;
    }
    for (int q = 0; q < 4; q++)
      for (int w = 0; w < 3; w++)
        for (int e = 0; e < 3; e++)
          for (int r = 0; r < 3; r++)
            sort(infos[q][w][e][r].begin(), infos[q][w][e][r].end());
  }
  //쿼리진행
  int a, b, c, d;
  for (int i = 0; i < query.size(); i++) {
    if (query[i][0] == 'j') {
      a = 1;
      query[i] = query[i].substr(9, query[i].size() - 8);
    } else if (query[i][0] == 'c') {
      a = 0;
      query[i] = query[i].substr(8, query[i].size() - 7);
    } else if (query[i][0] == 'p') {
      a = 2;
      query[i] = query[i].substr(11, query[i].size() - 10);
    } else if (query[i][0] == '-') {
      a = 3;
      query[i] = query[i].substr(6, query[i].size() - 5);
    }
    // 1
    if (query[i][0] == 'b') {
      b = 0;
      query[i] = query[i].substr(12, query[i].size() - 11);
    } else if (query[i][0] == 'f') {
      b = 1;
      query[i] = query[i].substr(13, query[i].size() - 12);
    } else if (query[i][0] == '-') {
      b = 2;
      query[i] = query[i].substr(6, query[i].size() - 5);
    }
    // 2
    if (query[i][0] == 'j') {
      c = 0;
      query[i] = query[i].substr(11, query[i].size() - 10);
    } else if (query[i][0] == 's') {
      c = 1;
      query[i] = query[i].substr(11, query[i].size() - 10);
    } else if (query[i][0] == '-') {
      c = 2;
      query[i] = query[i].substr(6, query[i].size() - 5);
    }
    // 3
    if (query[i][0] == 'c') {
      d = 0;
      query[i] = query[i].substr(8, query[i].size() - 7);
    } else if (query[i][0] == 'p') {
      d = 1;
      query[i] = query[i].substr(6, query[i].size() - 5);
    } else if (query[i][0] == '-') {
      d = 2;
      query[i] = query[i].substr(2, query[i].size() - 1);
    }
    // cout<<a<<b<<c<<d<<" "<<query[i]<<endl;
    // 4
    // bool success = false;
    // for (int sc = 0; sc < infos[a][b][c][d].size(); sc++) {
    //   // cout<<infos[a][b][c][d][sc]<<endl;
    //   if (stoi(query[i]) <= infos[a][b][c][d][sc]) {
    //     success = true;
    //     answer.push_back(infos[a][b][c][d].size() - sc);
    //     break;
    //   }
    // }
    // if (!success)
    //   answer.push_back(0);
    int push = infos[a][b][c][d].size() -
                (lower_bound(infos[a][b][c][d].begin(), infos[a][b][c][d].end(),
                             stoi(query[i])) -
                 infos[a][b][c][d].begin());
    answer.push_back(push);
  }
  return answer;
}