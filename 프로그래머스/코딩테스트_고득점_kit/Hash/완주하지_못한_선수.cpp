// 문제 URL : https://school.programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";

  unordered_map<string, int> um;
  for (string& a : completion) {
    if (um.find(a) != um.end()) {
      um[a]++;
    } else {
      um[a] = 1;
    }
  }
  for (string& a : participant) {
    if (um.find(a) != um.end()) {
      um[a]--;
      if (um[a] < 0) {
        answer = a;
        break;
      }
    } else {
      answer = a;
      break;
    }
  }

  return answer;
}