function dailyTemperatures(temperatures: number[]): number[] {
    let stack = []
    let ans = new Array(temperatures.length).fill(0)
    for (let i = 0; i < temperatures.length; i++) {
        while (stack.length > 0 && temperatures[stack[stack.length - 1]] < temperatures[i]) {
            let j = stack[stack.length - 1]
            ans[j] = i - j
            stack.pop()
        }
        stack.push(i)
    }
    return ans;
};