function equalPairs(grid: number[][]): number {
    function convertToKey(arr: number[]) {
        let str = "";
        for (let num of arr)
            str += num + ","
        return str;
    }

    const dic = new Map();
    for (let row of grid) {
        let key = convertToKey(row)
        dic.set(key, (dic.get(key) || 0) + 1)
    }
    const dic2 = new Map()
    for (let col = 0; col < grid[0].length; col++) {
        let currentCol = []
        for (let row = 0; row < grid.length; row++) {
            currentCol.push(grid[row][col])
        }
        let key = convertToKey(currentCol)
        dic2.set(key, (dic2.get(key) || 0) + 1)
    }

    let ans = 0;
    for (let [arr, val] of dic) {
        ans += val * (dic2.get(arr) || 0);
    }
    return ans;

};