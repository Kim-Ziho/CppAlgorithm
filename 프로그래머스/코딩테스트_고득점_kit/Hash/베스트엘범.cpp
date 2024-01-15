#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct string_compare {
  bool operator()(const string& t, const string& v) const {
    return t > v;
  }
};

struct Music {
  int id;
  int plays;

  bool operator<(const Music& t) {
    if (plays == t.plays) {
      return id < t.id;
    } else return plays > t.plays;
  }
};

struct Genre {
  string genres;
  int total_plays;

  bool operator<(const Genre& t) {
    return total_plays > t.total_plays;
  }
};

int main() {
  vector<string> genres = { "classic", "pop", "classic1", "classic2", "pop1" };
  vector<int> plays = { 500, 600, 150, 800, 2500 };

  unordered_map<string, int> m;
  unordered_map<string, vector<Music>> mv;
  vector<Genre> genre_list;

  for (int i = 0; i < genres.size(); i++) {
    mv[genres[i]].push_back({ i, plays[i] });
    if (m.find(genres[i]) != m.end()) {
      m[genres[i]] += plays[i];
    } else m[genres[i]] = plays[i];
  }

  sort(genres.begin(), genres.end(), greater<string>());

  for (auto a : genres) {
    cout << a << ' ';
  }
}