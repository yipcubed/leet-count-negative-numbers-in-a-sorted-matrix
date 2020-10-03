#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/PrintUtils.hpp"
#include "../utils/VectorUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() { // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int count = 0;
    if (grid.size() == 0)
      return 0;
    int maxRow = grid.size();
    int maxCol = grid[0].size();
    for (int row = 0; row < maxRow; row++) {
      for (int col = 0; col < maxCol; col++) {
        if (grid[row][col] < 0) {
          // PV4(row, col, count, ((maxCol - col) * (maxRow- row)));
          count += ((maxCol - col) * (maxRow- row));
          maxCol = col;
          break;
        }
      }
    }
    return count;
  }
};

void test1() {
  cout << boolalpha;

  vector<vector<int>> grid = {
      vector<int>{4, 3, 2, -1}, vector<int>{3, 2, 1, -1},
      vector<int>{1, 1, -1, -2}, vector<int>{-1, -1, -2, -3}};

  cout << "8 ? " << Solution().countNegatives(grid) << endl;
}

void test2() {}

void test3() {}