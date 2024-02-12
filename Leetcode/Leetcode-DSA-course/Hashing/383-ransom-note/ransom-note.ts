function canConstruct(ransomNote: string, magazine: string): boolean {
    let freq1 = new Map()
    for (let ch of ransomNote) {
        freq1.set(ch, (freq1.get(ch) || 0) + 1)
    }
    let freq2 = new Map()
    for (let ch of magazine) {
        freq2.set(ch, (freq2.get(ch) || 0) + 1)
    }
    for (let [ch, count] of freq1) {
        if (!freq2.has(ch) || freq2.get(ch) < count) {
            return false;
        }
    }
    return true
};