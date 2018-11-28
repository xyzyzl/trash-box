#include <iostream>
#include <cmath>

#define MAXN 2011

using namespace std;

int N;
int coins[MAXN], psum[MAXN];
int dp[MAXN][MAXN];
int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> coins[N-i-1];
  }
  for(int i = 0; i < N; i++) {
    psum[i+1] = psum[i] + coins[i];
  }
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++) {
      dp[i][j] = max(dp[i][j], dp[i][j-1]);
      if(i >= 2*j-1)
	dp[i][j] = max(dp[i][j], psum[i] - dp[i-2*j+1][2*j-1]);
      if(i >= 2*j)
	dp[i][j] = max(dp[i][j], psum[i] - dp[i-2*j][2*j]);
    }
  cout << dp[N][1] << '\n';
}
