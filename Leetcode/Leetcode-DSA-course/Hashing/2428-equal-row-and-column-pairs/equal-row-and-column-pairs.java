class Solution {
    public int equalPairs(int[][] grid) {
        Map<String, Integer> dic = new HashMap<>();
        for (int[] row : grid) {
            String key = convertToKey(row);
            dic.put(key, dic.getOrDefault(key, 0) + 1);
        }
        Map<String, Integer> dic2 = new HashMap<>();
        for (int col = 0; col < grid[0].length; col++) {
            int[] currentCol = new int[grid.length];
            for (int row = 0; row < grid.length; row++) {
                currentCol[row] = grid[row][col];
            }
            String key = convertToKey(currentCol);
            dic2.put(key, dic2.getOrDefault(key, 0) + 1);
        }

        int ans = 0;
        for (String arr : dic.keySet()) {
            ans += dic.get(arr) * dic2.getOrDefault(arr, 0);
        }
        return ans;
    }

    public String convertToKey(int[] arr) {
        StringBuilder sb = new StringBuilder();
        for (int num : arr) {
            sb.append(num);
            sb.append(",");
        }
        return sb.toString();
    }
}