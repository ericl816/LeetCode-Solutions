class Solution {
public:
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
      vector<int> prev, res(cells.size(), 0);
      for (int cycles = 0; N-->0; cells = res, cycles++) {
        for (size_t i = 1; i < cells.size() - 1; ++i) res[i] = cells[i - 1] == cells[i + 1];
        if (!cycles) prev = res;
        else if (res == prev) N %= cycles;
      }
      return cells;
    }
};
