/*
백준 온라인 저지
1048번 유니콘
https://www.acmicpc.net/problem/1048
20200713
문제부터 이해해보자.
L이 중요한데, L에 맞춰서 경로를 짜면 된다. 문제는 그 경우의 수가 너무 많다는 점.
경로를 구할 수 있는지 시간복잡도 부터 생각하자.
경로는 유니콘의 무빙을 생각해야하는데, 90000개를 다 본다고 생각하자.
[][]에서 k번째에 갈 수 있는 경우의 수를 생각?
dp로. 그럼 한번씩 만 구하면 되긴 한다.
일단 이 방법을 해보도록 하자.
- 결과는 시간초과. 90000 * 90000 * 50이니까 빡세다. 안될만 했다.
그럼 개선해보자.
여기서 개선점을 찾기 힘들어 '알고리즘 분류'를 확인 - 다이나믹 프로그래밍이었다.
개선할 수 있다는 확신을 주었다.
그러나 포기. 구글링.
2차원 부분합으로 해결되는 문제였다. 미친발상...
마법의 슈퍼마리오에서도 말하길, 풀이를 모르면 모를 수 밖에 없는 문제.
플레4 문제는 아닌거 같은데... 아무튼
0부터 시작해서, 반복적 동적 계획법으로 푼다.
0을 다 한뒤 부분합을 구하고 1을 풀때 써먹어준다. 이걸 계속 반복해주는 것이다.
마지막 디버깅은! 
long 은 long long과 다르다는 점.
또한, 나누는 값 때문에 - 가 될 수 있다는 점을 생각하자.
*/

#include <iostream>
using namespace std;
int N, M, L;
string route;
string board[301];
#define DEVIDENUM 1000000007
long long twoDimensionSum[301][301][50];
// k번째 순서에서 n,m번째 자리에서 앞으로 가능한 경우의 수. 지금은 이미 성공한
// 것이라 가정한다.

// 2차원 부분합을 위한 선행 계산식
void preTwoDimension(int k) {
  for (int i = 1; i <= N; i++)
    for (int j = 2; j <= M; j++)
      twoDimensionSum[i][j][k] += (twoDimensionSum[i][j - 1][k] % DEVIDENUM);
  for (int i = 2; i <= N; i++)
    for (int j = 1; j <= M; j++)
      twoDimensionSum[i][j][k] += (twoDimensionSum[i - 1][j][k] % DEVIDENUM);
}

// 2차원 부분합 계산식
long long twoDimension(int a, int b, int c, int d, int k) {
  return (twoDimensionSum[c][d][k] - twoDimensionSum[a][d][k] -
          twoDimensionSum[c][b][k] + twoDimensionSum[a][b][k] +
          DEVIDENUM * 2) %
         DEVIDENUM;
}

// k번째 순서에 유니콘이 k-1의 유니콘(k-1일 때의 2차원 부분합 영역을 다 더한다.
// )과 연속해서 올 수 있는 경우의 수. 이 값이 새로운 2차원 값이 된다.

void unicorn(int i, int j, int k) {
  long long answer = 0;
  if (i - 2 > 0 && j - 2 > 0) {
    answer += twoDimension(0, 0, i - 2, j - 2, k - 1) -
              twoDimension(i - 3, j - 3, i - 2, j - 2, k - 1);
  }
  answer += DEVIDENUM * 2;
  answer %= DEVIDENUM;
  if (i - 2 > 0 && j + 2 < M + 1) {
    answer += (twoDimension(0, j + 1, i - 2, M, k - 1) -
               twoDimension(i - 3, j + 1, i - 2, j + 2, k - 1));
  }
  answer += DEVIDENUM * 2;
  answer %= DEVIDENUM;
  if (i + 2 < N + 1 && j - 2 > 0) {
    answer += (twoDimension(i + 1, 0, N, j - 2, k - 1) -
               twoDimension(i + 1, j - 3, i + 2, j - 2, k - 1));
  }
  answer += DEVIDENUM * 2;
  answer %= DEVIDENUM;
  if (i + 2 < N + 1 && j + 2 < M + 1) {
    answer += (twoDimension(i + 1, j + 1, N, M, k - 1) -
               twoDimension(i + 1, j + 1, i + 2, j + 2, k - 1));
  }
  answer += DEVIDENUM * 2;
  answer %= DEVIDENUM;
  twoDimensionSum[i][j][k] = answer;
}

int main() {
  fill(&twoDimensionSum[0][0][0], &twoDimensionSum[0][0][0] + 301 * 301 * 50,
       0);
  cin >> N >> M >> L >> route;
  for (int i = 1; i <= N; i++) {
    cin >> board[i];
    board[i] = '0' + board[i];
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      if (board[i][j] == route[0])
        twoDimensionSum[i][j][0] = 1;
    }

  preTwoDimension(0);
  for (int k = 1; k < route.size(); k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        if (route[k] == board[i][j]) {
          unicorn(i, j, k);
        }
      }
    }
    preTwoDimension(k);
  }

  long long answer = twoDimensionSum[N][M][route.size() - 1];
  answer %= DEVIDENUM;
  cout << answer;
  return 0;
}