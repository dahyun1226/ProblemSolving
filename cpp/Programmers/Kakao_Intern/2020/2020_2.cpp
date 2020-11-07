/*
2020 카카오 인턴십
키패드 누르기
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
string f(string expression, char ex) {
  int index = 0;
  string next = "";
  bool seq = false;
  int saveIndexStart = 0;
  long long save;
  while (index < expression.size()) {
    if (expression[index] != ex &&
        (expression[index] == '+' || expression[index] == '-' ||
         expression[index] == '*')) {
      if (seq == false) {
        next += expression.substr(saveIndexStart, index - saveIndexStart + 1);
        saveIndexStart = index + 1;
        index++;
      } else if(seq == true){
          if(ex=='-'){
            if(save-stol(expression.substr(saveIndexStart, index - saveIndexStart + 1))<0){
                next+='m';
                
            }
          }
      }
    }
  }
}
long long solution(string expression) {
  long long answer = 0;
  char exs[3] = {'+', '-', '*'};
  for (int i = 0; i < 3; i++)
    for (int j = 0; i < 3; i++)
      for (int k = 0; i < 3; i++) {
        if (i == j || i == k || j == k)
          continue;
        long long caseAnswer = 0;
        string ex2;
        string ex3;
        string ex4;
        ex2 = f(expression, exs[i]);
        ex3 = f(expression, exs[j]);
        ex4 = f(expression, exs[k]);
        caseAnswer = stol(ex4);
        answer = max(caseAnswer, answer);
      }
  return answer;
}