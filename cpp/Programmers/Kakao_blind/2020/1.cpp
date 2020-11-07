#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
  string answer = "";
  answer = new_id;
  for (int i = 0; i < answer.size(); i++) {
    if (answer[i] >= 'A' && answer[i] <= 'Z')
      answer[i] += 32;
  }
  //cout << answer << endl;
  for (int i = 0; i < answer.size(); i++) {
    if (!((answer[i] >= 'a' && answer[i] <= 'z') ||
          (answer[i] >= '0' && answer[i] <= '9') || (answer[i] == '-') ||
          (answer[i] == '_') || (answer[i] == '.'))) {
      answer.erase(i, 1);
      i--;
    }
  }
  //cout << answer << endl;
  for (int i = 0; i < answer.size(); i++) {
    if (answer[i] == '.' && i + 1 < answer.size()) {
      if (answer[i + 1] == '.') {
        answer.erase(i, 1);
        i--;
      }
    }
  }
  //cout << answer << endl;
  if (answer[0] == '.')
    answer.erase(0, 1);
  if (answer[answer.size() - 1] == '.')
    answer.erase(answer.size() - 1, 1);
  //cout << answer << endl;
  if (answer == "")
    answer = "a";
  if (answer.size() >= 16)
    answer.erase(15);
  if (answer[answer.size() - 1] == '.')
    answer.erase(answer.size() - 1, 1);
  if (answer.size() <= 2)
    answer += answer[answer.size() - 1];
      if (answer.size() <= 2)
    answer += answer[answer.size() - 1];
      if (answer.size() <= 2)
    answer += answer[answer.size() - 1];
  return answer;
}

int main() {
  string a;
  cin >> a;
  cout << solution(a);
  return 0;
}

// cout<<int('a')<<endl;
// cout<<int('A')<<endl;
// cout<<int('Z')<<endl;
// cout<<int('z')<<endl;
//     cout<<int('0')<<endl;
// cout<<int('9')<<endl;
//     cout<<int('-')<<endl;
//     cout<<int('_')<<endl;
//     cout<<int('.')<<endl;