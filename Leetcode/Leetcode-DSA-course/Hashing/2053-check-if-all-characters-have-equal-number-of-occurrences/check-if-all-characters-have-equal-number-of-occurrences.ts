function areOccurrencesEqual(s: string): boolean {
    const counts = new Map();
    for (let ch of s)
        counts.set(ch, (counts.get(ch) || 0) + 1)

    const frequencies = new Set(counts.values())
    return frequencies.size == 1;
};