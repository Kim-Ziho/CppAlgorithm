#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phoneBook) {
  unordered_set<string> us(phoneBook.begin(), phoneBook.end());

  for (string s : phoneBook) {
    for (int i = 1; i < s.size(); i++) {
      string tmp = s.substr(0, i);
      if (us.find(tmp) != us.end()) return false;
    }
  }
  return true;
}