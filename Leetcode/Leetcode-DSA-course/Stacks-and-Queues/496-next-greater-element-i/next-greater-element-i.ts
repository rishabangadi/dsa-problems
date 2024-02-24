function nextGreaterElement(nums1: number[], nums2: number[]): number[] {
    let stack = []
    let map = new Map();
    for (let i = 0; i < nums2.length; i++) {
        while (stack.length > 0 && nums2[i] > stack[stack.length - 1]) {
            map.set(stack.pop(), nums2[i]);
        }
        stack.push(nums2[i]);
    }
    while (stack.length > 0) {
        map.set(stack.pop(), -1);
    }
    let res = []
    for (let num of nums1) {
        res.push(map.get(num));
    }
    return res;
};