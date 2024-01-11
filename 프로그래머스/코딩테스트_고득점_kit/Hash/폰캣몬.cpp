// https://school.programmers.co.kr/learn/courses/30/lessons/1845
// 폰켓몬

#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
  int answer = 0;
  int species = 0;
  int dat[200001] = { 0 };

  for (int& a : nums) {
    if (dat[a] == 0) {
      dat[a]++;
      species++;
    }
  }

  if (nums.size() / 2 <= species) {
    return answer = nums.size() / 2;
  } else {
    return species;
  }

  // return answer;
}