class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        dic = defaultdict(int)
        for row in grid:
            dic[tuple(row)] += 1
        dic2 = defaultdict(int)
        for col in range(len(grid[0])):
            currentCol = []
            for row in range(len(grid)):
                currentCol.append(grid[row][col])
            dic2[tuple(currentCol)] += 1
        ans = 0
        for arr in dic:
            ans += dic[arr] * dic2[arr]
        return ans
