/*
백준 온라인 저지
1086번 박성원
https://www.acmicpc.net/problem/1086
k로 나눠지는 순열의 갯수 / 모든 순열의 갯수
15!아닌가? 15!면... 1,307,674,368,000 너무 경우의 수가 많다.
k로 먼저 나누고 생각하자. 그럼 각각이 50자리의 수가 100 이하의 수가 될 것이다...
그래도 그 자리의 수는 10의 몇십승을 곱해야 하는데?
풀이를 보니, 진짜 그 괴랄한 방법으로 풀고 있다? 으악.
정신이 멍해진다. 이게 왜 플5 문제지????
제정신을 차리고 보니 그렇게 막 빡센 문제는 또 아닌거 싶기도 하고? 제대로
이해한다면. 근데 내 생각에 플2 ~ 3은 된다고 본다...
*/
#include <iostream>
using namespace std;

template <typename T> void testPrint(T value) { cout << value << endl; }

// 팩토리얼 구하기
long long factorial(int n) {
  if (n == 1)
    return 1;
  return factorial(n - 1) * n;
}
// 최대 공약수 구하기
long long gcd(long long x, long long y) {
  if (y == 0)
    return x;
  return gcd(y, x % y);
}

int main() {
  //입력 받기 및 초기화
  int n;
  cin >> n;
  // dp[i][j]에서 i는 비트마스크로 n개의 집합을 나타내고, j는 k로 나눴을 때의
  // 나머지이다. 그때의 dp는 가능한 경우의 수이고, dp[1 << n][0]가 답이 된다.
  // 참고로 long long [1 << 15][100]는 2^15 * 100으로
  // vscode에서 실행했을 때는 너무 큰 공간을 잡아먹어 빌드가 되질 않는다.
  // 0으로 초기화한다.
  long long dp[1 << 15][100];
  fill(&dp[0][0], &dp[0][0] + (1 << 15) * 100, 0);
  string puts[15];
  int putsSize[15];
  int preprocessedPuts[15];
  // twoPower[i]는 2^i 값이다.
  int twoPower[16];
  twoPower[0] = 1;
  for (int i = 1; i < 16; i++)
    twoPower[i] = twoPower[i - 1] * 2;
  // mod[i][j]는 10^i를 j로 나눈 나머지 값.
  int mod[51][101];
  for (int i = 0; i < n; i++) {
    cin >> puts[i];
    putsSize[i] = puts[i].size();
  }
  int k;
  cin >> k;
  // 전처리 - mod 구하기
  for (int i = 0; i <= 50; i++) {
    for (int j = 1; j <= 100; j++) {
      if (i == 0) {
        mod[i][j] = 1 % j;
      } else {
        mod[i][j] = (mod[i - 1][j] * 10) % j;
      }
    }
  }
  // 전처리 - preprocessedPuts 구하기
  // preprocessedPuts는 puts를 k로 나눈 값이다.
  // char 자료형 1은 int 49에 대응된다는 점을 기억하자.
  for (int i = 0; i < n; i++) {
    preprocessedPuts[i] = 0;
    for (int index = 0; index < putsSize[i]; index++) {
      preprocessedPuts[i] +=
          ((puts[i][index] - 48) * mod[putsSize[i] - index - 1][k]) % k;
    }
    preprocessedPuts[i] %= k;
  }
  // dp 값 계산하기
  // i의 포함되지 않는 녀석을 무조건 '뒤'에 붙여준다. 뒤에 붙여주는게 포인트다.
  // 또한, 무조건 i보다 큰 녀석들에 더해주기 때문에 i를 할 때는 그 이전의 것들을
  // 다 했다는 확신을 가질 수 있다. 예를 들어, 11100을 통해 만들 때는 11000,
  // 10100, 01100의 11100보다 작은 녀석들로 이미 11100이 다 만들어져 있다는
  // 확신을 가질 수 있기 때문에 걱정 안 해도 된다는 것이다. dp[0][0]을
  // 해줌으로써 1개를 넣는 경우를 다 넣을 수 있다.
  dp[0][0] = 1;
  for (int i = 0; i < (1 << n); i++) {
    for (int bit = 0; bit < n; bit++) {
      if (i & (1 << bit))
        continue;
      for (int m = 0; m < k; m++) {
        if (dp[i][m] == 0)
          continue;
        int newm = (mod[putsSize[bit]][k] * m + preprocessedPuts[bit]) % k;
        dp[i | (1 << bit)][newm] += dp[i][m];
      }
    }
  }
  // 정답 구하기
  long long divideNum = gcd(factorial(n), dp[(1 << n) - 1][0]);
  cout << dp[(1 << n) - 1][0] / (divideNum) << "/"
       << factorial(n) / (divideNum);
}
