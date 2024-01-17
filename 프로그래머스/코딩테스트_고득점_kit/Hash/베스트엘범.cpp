#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Music {
    int id;
    int plays;

    bool operator<(const Music& t) const {
        if (plays == t.plays) {
            return id < t.id;
        } else return plays > t.plays;
    }
};

struct Genre {
    string name;
    int total_plays;

    bool operator<(const Genre& t) const {
        return total_plays > t.total_plays;
    }
};

int main() {
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    unordered_map<string, int> genre_total_plays;
    unordered_map<string, set<Music>> song_rank;
    set<Genre> genre_rank;

    for (int i = 0; i < genres.size(); i++) {
        song_rank[genres[i]].insert({ i, plays[i] });
        genre_total_plays[genres[i]] += plays[i];
    }

    for (pair<string, int> pair : genre_total_plays) {
        genre_rank.insert({ pair.first, pair.second });
    }

    for (Genre genre : genre_rank) {
        int cnt = 0;
        for (Music music : song_rank[genre.name]) {
            cout << music.id << ' ';
            cnt++;
            if (cnt == 2) break;
        }
    }
}