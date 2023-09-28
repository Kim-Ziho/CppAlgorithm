#include <iostream>
using namespace std;

int N; //격자크기
int K; //도시 수
int U; //높이차 U이상
int D; //높이차 D이하
int arr[8][8];

void input() {
  cin >> N >> K >> U >> D;
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      cin >> arr[y][x];
    }
  }
}

int main() {
  freopen("우리는하나.txt", "r", stdin);
  input();

  return 0;
}