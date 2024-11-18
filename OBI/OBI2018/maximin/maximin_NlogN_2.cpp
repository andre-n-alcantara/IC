// Paulo Cezar, maximin, O(N*log(N))

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[])
{

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, L, R;
  cin >> N >> L >> R;

  vector<int> a(N);
  for (int& v : a)
  {
    cin >> v;
  }
  sort(a.begin(), a.end());

  // code becomes uglier but we get rid of min_distance calculation
  // using binary search
  int res = -1;

  auto lo = lower_bound(a.cbegin(), a.cend(), L);
  if (lo != a.cbegin()) --lo;

  auto hi = upper_bound(a.cbegin(), a.cend(), R);

  if (lo != a.cbegin() && lo != a.cend())
    res = min(L - *(lo - 1), *lo - L);
  else if (lo != a.cbegin())
    res = L - *(lo - 1);
  else if (lo != a.cend())
    res = *lo - L;

  while (lo != hi && (lo + 1) != a.cend())
  {
    int prev = *lo;
    int next = *(lo + 1);
    auto candidate = (prev + next) / 2;
    if (L <= candidate && candidate <= R)
      res = max(res, min(candidate-prev, next-candidate));
    ++lo;
  }

  if (hi != a.cbegin() && hi != a.cend())
    res = max(res, min(R - *(hi - 1), *hi - R));
  else if (hi != a.cbegin())
    res = max(res, R - *(hi - 1));
  else if (hi != a.cend())
    res = max(res, *hi - R);

  cout << res << "\n";

  return 0;
}
