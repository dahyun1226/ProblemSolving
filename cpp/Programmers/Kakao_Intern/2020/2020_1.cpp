/*
2020 카카오 인턴십
키패드 누르기
*/
#include <iostream>
#include <vector>
using namespace std;
int main() { return 0; }
string solution(vector<int> numbers, string hand) {
  string answer = "";
  int ly = 3, lx = 0, ry = 3, rx = 2;

  for (int i = 0; i < numbers.size(); i++) {
    if (numbers[i] == 1) {
      answer += "L";
      lx = 0;
      ly = 0;
    } else if (numbers[i] == 4) {
      answer += "L";
      lx = 0;
      ly = 1;
    } else if (numbers[i] == 7) {
      answer += "L";
      lx = 0;
      ly = 2;
    } else if (numbers[i] == 3) {
      answer += "R";
      rx = 2;
      ry = 0;
    } else if (numbers[i] == 6) {
      answer += "R";
      rx = 2;
      ry = 1;
    } else if (numbers[i] == 9) {
      answer += "R";
      rx = 2;
      ry = 2;
    } else if (numbers[i] == 2) {
      if (abs(lx - 1) + abs(ly - 0) < abs(rx - 1) + abs(ry - 0)) {
        answer += "L";
        lx = 1;
        ly = 0;
      } else if (abs(lx - 1) + abs(ly - 0) > abs(rx - 1) + abs(ry - 0)) {
        answer += "R";
        rx = 1;
        ry = 0;
      } else {
        if (hand == "right") {
          answer += "R";
          rx = 1;
          ry = 0;
        } else {
          answer += "L";
          lx = 1;
          ly = 0;
        }
      }
    } else if (numbers[i] == 5) {
      if (abs(lx - 1) + abs(ly - 1) < abs(rx - 1) + abs(ry - 1)) {
        answer += "L";
        lx = 1;
        ly = 1;
      } else if (abs(lx - 1) + abs(ly - 1) > abs(rx - 1) + abs(ry - 1)) {
        answer += "R";
        rx = 1;
        ry = 1;
      } else {
        if (hand == "right") {
          answer += "R";
          rx = 1;
          ry = 1;
        } else {
          answer += "L";
          lx = 1;
          ly = 1;
        }
      }
    } else if (numbers[i] == 8) {
      if (abs(lx - 1) + abs(ly - 2) < abs(rx - 1) + abs(ry - 2)) {
        answer += "L";
        lx = 1;
        ly = 2;
      } else if (abs(lx - 1) + abs(ly - 2) > abs(rx - 1) + abs(ry - 2)) {
        answer += "R";
        rx = 1;
        ry = 2;
      } else {
        if (hand == "right") {
          answer += "R";
          rx = 1;
          ry = 2;
        } else {
          answer += "L";
          lx = 1;
          ly = 2;
        }
      }
    } else if (numbers[i] == 0) {
      if (abs(lx - 1) + abs(ly - 3) < abs(rx - 1) + abs(ry - 3)) {
        answer += "L";
        lx = 1;
        ly = 3;
      } else if (abs(lx - 1) + abs(ly - 3) > abs(rx - 1) + abs(ry - 3)) {
        answer += "R";
        rx = 1;
        ry = 3;
      } else {
        if (hand == "right") {
          answer += "R";
          rx = 1;
          ry = 3;
        } else {
          answer += "L";
          lx = 1;
          ly = 3;
        }
      }
    }
  }
  return answer;
}
