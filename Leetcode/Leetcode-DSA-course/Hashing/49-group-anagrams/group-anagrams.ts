function groupAnagrams(strs: string[]): string[][] {
    let groups = new Map();
    for (const s of strs) {
        let key = s.split("").sort().join("");
        if (!groups.has(key))
            groups.set(key, []);
        groups.get(key).push(s);
    }
    const ans = []
    for (const s of groups.values())
        ans.push(s);
    return ans;
};