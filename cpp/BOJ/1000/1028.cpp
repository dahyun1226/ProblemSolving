/*
백준 온라인 저지
1028번 다이아몬드 광산
https://www.acmicpc.net/problem/1028
20200413
단순하게 생각해보자. 브루트포스로 푼다고 하면, 대략 750*750*(1+4+9+...375^2)일
것이다.¡ 이는 대충 750*750*375*(375+1)*(375*2+1)/6이다. 물론 택도 없는 숫자가
나온다. 브루트포스로는 안된다. 그렇다면 최적화를 좀 더 해보자. 최대 크기는 뭐
어차피 750이라고 가정한다면 4개의 경우의 수 밖에 없을 것이다. 또, 더 쉽게
다이아몬드는 중앙의 점에서 뻗어나온 형태로 생각해볼 수 있다. 최대 r,c일 때, n은
반지름의 길이라고 할 때 (r-2n)(c-2n)개의 중앙점, 즉, 갯수로 나타낼 수 있다.
중앙점마다 4n개의 1이 있으니까 n이 1에서 대략 375까지일 때, (r-2n)(c-2n)(4n)이
된다. r,c는 최대라고 가정하는게 좋을테니 26,367,000,000 이래도 너무 크다. 다른
최적화를 생각해보면, 한 크기가 통과되면 같은 크기(그것보다 작은 크기들)는 당연히
패스하기 등등이 있다. 근데, 말이 안된다. 부분문제가 없다고 생각했는데, 힌트로
해결법이 dp라는걸 알게 되었다. 곰곰히 생각해보니, dp가 존재했다. 예를 들어, 왼쪽
아래의 갯수는 단순히 왼쪽 위의 갯수 -1이었던 것이다. 나아갈 방향에 맞춰서 오른쪽
아래와 왼쪽 아래에 있는 1의 갯수를 가지는 dp를 하면 된다. 그러면 750*750*2만
계산하게 된다.
*/
#include <iostream>
#include <vector>
using namespace std;
int leftDown[750][750];
int rightDown[750][750];
string board[750];
int R, C;
int checkRight(int r, int c) { //갯수는 [r][c]를 포함한다.
  if (r >= R || c >= C)
    return 0;
  int &ret = rightDown[r][c];
  if (ret != -1)
    return ret;
  ret = 0;
  if (board[r][c] == '0')
    return ret;
  ret += 1;
  if (r + 1 < R && c + 1 < C)
    if (checkRight(r + 1, c + 1) > 0)
      ret = checkRight(r + 1, c + 1) + 1;
  return ret;
}

int checkLeft(int r, int c) { //갯수는 [r][c]를 포함한다.
  if (r >= R || c >= C)
    return 0;
  int &ret = leftDown[r][c];
  if (ret != -1)
    return ret;
  ret = 0;
  if (board[r][c] == '0')
    return ret;
  ret += 1;
  if (r + 1 < R && c - 1 < C && c - 1 >= 0)
    if (checkLeft(r + 1, c - 1) > 0)
      ret = checkLeft(r + 1, c - 1) + 1;
  return ret;
}

int checkDiamond(int r, int c) {
  if (board[r][c] == '0')
    return 0;
  int maxDiamondRank = min(checkLeft(r, c), checkRight(r, c));
  for (int i = maxDiamondRank - 1; i > 0; i--) {
    if (checkRight(r + i, c - i) >= i + 1 && checkLeft(r + i, c + i) >= i + 1) {
      return i + 1;
    }
  }
  return 1;
}

int main() {
  cin >> R >> C;
  for (int i = 0; i < R; i++)
    cin >> board[i];
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      leftDown[i][j] = -1;
      rightDown[i][j] = -1;
    }
  int answer = 0;
  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) {
      answer = max(answer, checkDiamond(i, j));
    }
  cout << answer;
  return 0;
}