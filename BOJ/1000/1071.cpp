/*
백준 온라인 저지
1071번 소트
https://www.acmicpc.net/problem/1071
어려워서 질문 게시판을 참고했다.
https://www.acmicpc.net/board/view/52926
생각이 난 어려웠는데... 쉬운 문제였나 보다.
+1만 아니면 다 가능하다는 것을 인지함과 동시에 사전순을 제대로 아는지를 묻고있는
듯한 문제.
*/

#include <iostream>
#include <vector>
using namespace std;
int board[1001];
vector<pair<int, int>> v;
vector<int> answer;
int main() {
  int n;
  cin >> n;
  // 입력 받기 및 갯수 행렬 만들기
  fill(&board[0], &board[0] + 1001, 0);
  for (int i = 0; i < n; i++) {
    int put;
    cin >> put;
    board[put]++;
  }
  // 갯수를 가지는 행렬 넣기
  for (int i = 0; i <= 1000; i++) {
    if (board[i] != 0) {
      v.push_back(make_pair(i, board[i]));
    }
  }
  ////소팅
  // 종류가 한 가지인 경우는 당연하다
  if (v.size() == 1) {
    for (int i = 0; i < v[0].second - 1; i++)
      cout << (v[0].first) << " ";
    cout << v[0].first;
    return 0;
  }
  // 여기서는 다음으로 하는 size가 2일때의 순서가 제대로 되도록 보장해야한다.
  while (v.size() > 2) {
    while (v[0].second > 0) {
      answer.push_back(v[0].first);
      v[0].second--;
    }
    v.erase(v.begin());
    if (v.size() >= 2) {
      if (answer[answer.size() - 1] + 1 == v[0].first) {
        answer.push_back(v[1].first);
        v[1].second--;
      }
      if (v[1].second == 0) {
        v.erase(v.begin() + 1);
      }
    }
  }
  // size가 2개일 때.
  if (v[0].first + 1 == v[1].first) {
    for (int i = 0; i < v[1].second; i++) {
      answer.push_back(v[1].first);
    }
    for (int i = 0; i < v[0].second; i++) {
      answer.push_back(v[0].first);
    }
  } else {
    for (int i = 0; i < v[0].second; i++) {
      answer.push_back(v[0].first);
    }
    for (int i = 0; i < v[1].second; i++) {
      answer.push_back(v[1].first);
    }
  }
  // 정답 출력
  for (int i = 0; i < answer.size() - 1; i++) {
    cout << answer[i] << " ";
  }
  cout << answer[answer.size() - 1];
  return 0;
}