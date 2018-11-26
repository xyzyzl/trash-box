#include <iostream>
#include <queue>

#define MAXN 100005

using namespace std;

typedef pair<long long, int> pii;

int N, K;
int E[MAXN];
long long sum[MAXN], dp[MAXN];
priority_queue<pii> pq;
int main() {
  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> E[i];
  }
  for(int i = 0; i < N; i++) {
    sum[i+1] = sum[i] + E[i];
  }
  pq.push(make_pair(0, -1));
  for(int i = 0; i <= N; i++) {
    while(pq.top().second < i-K-1)
      pq.pop();
    dp[i] = pq.top().first + sum[i];
    pq.push(make_pair(dp[i] - sum[i+1], i));
  }
  cout << dp[N] << endl;
}
