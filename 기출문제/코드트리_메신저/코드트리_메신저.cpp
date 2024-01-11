#include <iostream>
using namespace std;

int N, Q;
int a[100001];
int p[100001];
bool t[100001];
int val[100001];
int mx[10001][22];

void init() {
  int power, now, abil;

  for (int i = 1; i <= N; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    if (a[i] > 20) a[i] = 20;
  }
  for (int i = 1; i <= N; i++) {
    int now = i;
    int auth = a[i];

    while (now && auth) {
      mx[now][auth]++;
      now = p[now];
      auth--;
      val[now]++;
    }
  }
}

void toggle(int c) {
  if (t[c]) {
    int now = p[c];
    int num = 1;

    while (now) {
      for (int i = num; i <= 20; i++) {
        val[now] += mx[c][i];
        mx[now][i - num + 1] += mx[c][num + 1];
      }
      now = p[now];
      num++;
      if (t[now]) break;
    }
    t[c] = false;
  } else {
    int now = p[c];
    int num = 1;

    while (now) {
      for (int i = num; i <= 20; i++) {
        val[now] -= mx[c][i];
        mx[now][i - num + 1] -= mx[c][num + 1];
      }
      now = p[now];
      num++;
      if (t[now]) break;
    }
    t[c] = true;
  }
}

void change_auth(int c, int power) {

}

void change_parent(int c1, int c2) {

}

void print_num(int c) {
  cout << "x" << endl;
}

int main() {
  freopen("source.txt", "r", stdin);
  int q, c, c1, c2, power;
  cin >> N >> Q;
  while (Q--) {
    cin >> q;
    if (q == 100) {
      init();
    } else if (q == 200) {
      cin >> c;
      toggle(c);
    } else if (q == 300) {
      cin >> c >> power;
      change_auth(c, power);
    } else if (q == 400) {
      cin >> c1 >> c2;
      change_parent(c1, c2);
    } else if (q == 500) {
      cin >> c;
      print_num(c);
    }
  }
  return 0;
}
