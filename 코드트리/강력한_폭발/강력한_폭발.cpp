#include <iostream>
#include <vector>
using namespace std;

struct Coord {
  int y;
  int x;
};

int N;
int maxi = -1;
int direct_y[3][4] = {
  {-2, -1, 1, 2},
  {-1, 0, 1, 0},
  {-1, 1, 1, -1}
};
int direct_x[3][4] = {
  {0, 0, 0, 0},
  {0, 1, 0, -1},
  {1, 1, -1, -1}
};
vector<Coord> bomb;
int path[10];

void init(vector<vector<int>>& map);
void dfs(int lev, int num, vector<vector<int>> map);
void print(const vector<vector<int>>& map) {
  for (auto& y : map) {
    for (auto& x : y) {
      cout << x << ' ';
    }
    cout << endl;
  }
  cout << "--------------" << endl;
}

void init(vector<vector<int>>& map) {
  cin >> N;
  for (int i = 0; i < N; i++) {
    vector<int> temp(N);
    for (int j = 0; j < N; j++) {
      cin >> temp[j];
      if (temp[j] == 1) {
        bomb.push_back({ i, j });
      }
    }
    map.push_back(temp);
  }
}

void dfs(int lev, int num, vector<vector<int>> map) {
  if (lev == bomb.size()) {
    if (num > maxi) maxi = num;
    cout << "path : ";
    for (int i = 0; i < bomb.size(); i++) cout << path[i] << ' ';
    cout << endl;
    print(map);
    return;
  }
  for (int i = 0; i < 3; i++) {
    int b = 0;
    vector<vector<int>> temp = map;
    for (int j = 0; j < 4; j++) {
      int ny = bomb[lev].y + direct_y[i][j];
      int nx = bomb[lev].x + direct_x[i][j];
      if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
      if (temp[ny][nx] != 0) continue;
      temp[ny][nx] = 1;
      b++;
    }
    path[lev] = i;
    dfs(lev + 1, num + b, temp);
    path[lev] = -1;
  }
}

int main() {
  freopen("강력한_폭발.txt", "r", stdin);
  vector<vector<int>> map;
  init(map);
  print(map);
  dfs(0, bomb.size(), map);

  cout << maxi << endl;

  return 0;
}