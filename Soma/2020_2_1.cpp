#include <iostream>
#include <vector>
/*
소프트웨어 마에스트로 1번: 가장 맛있는 귤 한 박스
귤 10만개. 당도 백만의 범위. int범위로 안된다는 걸 알 수 있다.
간단하게 풀린다.
*/
using namespace std;
long tangerine[100000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> tangerine[i];
  int l = 0, r = 0;
  int num = 0;
  long sum = tangerine[0];
  long summax = tangerine[0];
  while (1) {
    // cout<<l<<" "<<r<<" "<<sum<<endl;
    if (l == r) {
      if (tangerine[l] <= 0) {
        l++;
        r++;
        sum -= tangerine[l - 1];
        summax = max(summax, sum);
      } else {
        r++;
      }
      if (r == n)
        break;
      sum += tangerine[r];
      summax = max(summax, sum);
    } else if ((sum <= 0 && l < r) || (l < r && r == n - 1)) {
      l++;
      sum -= tangerine[l - 1];
      summax = max(summax, sum);
    } else if (sum > 0 && r < n - 1) {
      r++;
      if (r == n)
        break;
      sum += tangerine[r];
      summax = max(summax, sum);
    }
  }
  cout << summax;
}