// https://school.programmers.co.kr/learn/courses/30/lessons/1845
// 폰켓몬

#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
  unordered_set<int> us(nums.begin(), nums.end());

  return min(us.size(), nums.size() / 2);
}