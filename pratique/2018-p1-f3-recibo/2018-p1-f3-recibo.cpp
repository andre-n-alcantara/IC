#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int combinar(int R, int K, vector<int>& dp) {
  if (K == 1) return 1;
  if (dp[K] != -1) return dp[K];
  int ans = 0;
  for (int i = 1; i <= min(R, K); i++) {
    ans += combinar(R - i, K - 1, dp);
  }
  dp[K] = ans;
  return ans;
}

int main() {
    std::clock_t startTime = std::clock();
  int R, K;
  cin >> R >> K;
  vector<int> dp(K + 1, -1);
  cout << combinar(R, K, dp) << endl;
  
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\n';
return 0;
}