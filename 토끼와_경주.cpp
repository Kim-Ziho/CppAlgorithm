/*
제한시간 2500ms, 메모리제한 80mb
int = 4b
80mb = 4b * 20,000,000
N x M = (100,000 X 100,000) -> 2차원 배열 금지

P 마리
N x M 격자, 초기위치 (1,1)
토끼 : pid, d, (y,x)

<함수>
경주 시작 준비(100) void :
경주 진행(200 K S) : 2000번
  우선순위 토끼 뽑아 멀리 보내기 K번
  우선순위 : 총 점프 횟수, 행+열, 행, 열, 고유번호가 작은 순위
  네 방향으로 이동, 격자 벗어나면 반대 방향 한칸 이동. d만큼 이동.
  네 위치 중 우선순위 : 행+열, 행, 열 큰 순위
  이동 후, 해당 토끼 제외 나머지 r+c 점수 얻음
  K번 이동 후, 뽑혔던 토끼 중, 우선순위 : 행+열, 행, 열, 고유번호 큰 토끼 S점 추가
이동거리 변경(300 pid L) : 2000번
  고유번호 pid인 토끼의 이동거리 d를 L배, d는 10억을 넘지 않는다.
최고의 토끼 선정(400) 점수 최댓값 출력 :
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Rabbit {
  int total;
  int y;
  int x;
  int id;
  int d;

  Rabbit(int id, int d):
    total(0), y(1), x(1), id(id), d(d) {}

  bool operator<(const Rabbit& r) const {
    if (total == r.total) {
      if (y + x == r.y + r.x) {
        if (y == r.y) {
          if (x == r.x) {
            return id < r.id;
          }
          return x < r.x;
        }
        return y < r.y;
      }
      return y + x < r.y + r.x;
    }
    return total < r.total;
  }
};

int main() {
  //freopen("토끼와_경주.txt", "r", stdin);

  set<Rabbit> rabbits;
  rabbits.insert(Rabbit(10, 2));
  rabbits.insert(Rabbit(20, 5));

  Rabbit pick = *rabbits.begin();
  pick.y = 2;
  // pick.total += pick.d;
  rabbits.erase(rabbits.begin());
  rabbits.insert(pick);

  vector<Rabbit> v;
  v.push_back(Rabbit(10, 2));
  v.push_back(Rabbit(20, 5));
  v.begin()->y = 2;
  for (auto& iter : v) {
    cout << iter.id << ' ' << iter.y << endl;
  }

  for (auto& iter : rabbits) {
    cout << iter.total << ' ' << iter.y + iter.x << ' ' << iter.id << endl;
  }

}
