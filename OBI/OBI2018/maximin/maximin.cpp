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

  // como a ordem dos elementos de `a` não é importante para o problema,
  // começamos ordenando `a` para que as próximas etapas sejam calculadas de
  // forma eficiente.
  sort(a.begin(), a.end());

  // encontra a menor diferença entre cada um dos elementos de `a` e `candidate`
  auto min_distance = [&a] (int candidate)
  {
    // lb aponta para o primeiro elemento de `a` maior ou igual a `candidate`
    auto lb = lower_bound(a.cbegin(), a.cend(), candidate);
    if (lb == a.cbegin())
    {
      // se o primeiro elemento é maior ou igual, ele vai ser aquele com a
      // menor diferença
      return *lb - candidate;
    }
    else if (lb == a.cend())
    {
      // se nenhum elemento é maior ou igual, o elemento com a menor diferença
      // é o maior elemento de `a`
      return candidate - a.back();
    }
    const auto lower = *(lb - 1);
    const auto higher = *lb;
    // caso contrário temos que `lower` < `candidate` <= `higher`, o que
    // significa que não precisamos nos preocupar com os outros elementos, basta
    // descobrir a menor diferença entre `candidate` e esses dois.
    return min(higher - candidate, candidate - lower);
  };

  // uma vez que entendemos como encontrar a menor diferença podemos perceber
  // que não é necessário testar todos os valores entre L e R para encontrar
  // aquele que tem a menor diferença. dados dois valores `lower` e `higher`
  // tais que `lower` <= `higher` o valor cuja menor diferença para os dois
  // vai ser máxima é (`higher` - `lower`)/2. assim basta testar como candidatos
  // os limites `L` e `R` e as médias dos valores consecutivos de `a` que
  // estão entre `L` e `R`.
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
