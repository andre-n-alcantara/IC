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
  for (int& v : a) cin >> v;

  sort(a.begin(), a.end());

  auto min_distance = [&a] (int candidate)
  {
    auto lb = lower_bound(a.cbegin(), a.cend(), candidate);
    if (lb == a.cbegin())
      return a.front() - candidate;
    else if (lb == a.cend())
      return candidate - a.back();

    return min(*lb - candidate, candidate - *(lb - 1));
  };

  int res = max(min_distance(L), min_distance(R));

  // checks a smaller range
  auto lo = lower_bound(a.cbegin(), a.cend(), L);
  if (lo != a.cbegin()) --lo;

  auto hi = upper_bound(a.cbegin(), a.cend(), R);
  while ((lo+1) != hi)
  {
    const auto candidate = (*(lo+1) + *lo) / 2;
    if (L <= candidate && candidate <= R)
      res = max(res, min_distance(candidate));
    ++lo;
  }

  cout << res << "\n";

  return 0;
}
