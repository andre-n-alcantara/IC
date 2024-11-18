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

  // slightly different min_distance
  auto min_distance = [&a] (int candidate)
  {
    const auto ub = upper_bound(a.cbegin(), a.cend(), candidate);
    if (ub == a.cend())
      return candidate - a.back();
    else if (ub == a.cbegin())
      return a.front() - candidate;

    return min(*ub - candidate, candidate - *(ub - 1));
  };

  int res = max(min_distance(L), min_distance(R));

  auto it = a.cbegin();
  while ((it+1) != a.cend())
  {
    const auto candidate = (*(it+1) + *it) / 2;
    if (L <= candidate && candidate <= R)
      res = max(res, min_distance(candidate));
    ++it;
  }

  cout << res << "\n";

  return 0;
}
