#include <iostream>
#include <vector>
#define ll long long

using namespace std;

vector<ll> arr;
vector<ll> tree;

ll init(int node, int l, int r) {
  if (l == r) return tree[node] = arr[l];
  return tree[node] = init(node * 2, l, (l + r) / 2) + init(node * 2 + 1, (l + r) / 2 + 1, r);
}

ll update(int node, int l, int r, int idx, ll alt) {
  if (idx < l || r < idx) return tree[node];
  if (l == r) return tree[node] = alt;
  return tree[node] = update(node * 2, l, (l + r) / 2, idx, alt) + update(node * 2 + 1, (l + r) / 2 + 1, r, idx, alt);
}

ll sum(int node, int l, int r, int a, int b) {
  if (b < l || r < a) return 0;
  if (a <= l && r <= b) return tree[node];
  return sum(node * 2, l, (l + r) / 2, a, b) + sum(node * 2 + 1, (l + r) / 2 + 1, r, a, b);
}

int main() {
  freopen("백준2042번_구간_합_구하기.txt", "r", stdin);
  int N, M, K;
  cin >> N >> M >> K;

  arr = vector<ll>(N + 1);
  tree = vector<ll>(N * 4);

  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  init(1, 1, N);

  for (int i = 0; i < M + K; i++) {
    ll a, b, c;
    cin >> a >> b >> c;

    switch (a) {
    case 1:
      update(1, 1, N, b, c);
      break;
    case 2:
      cout << sum(1, 1, N, b, c) << endl;
      break;
    }
  }
}