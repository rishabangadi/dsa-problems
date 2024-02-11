function maxVowels(s: string, k: number): number {
  let vowels = new Set(["a", "e", "i", "o", "u"]);
  let count = 0;
  for (let i = 0; i < k; i++) count += Number(vowels.has(s[i]));
  let ans = count;
  for (let i = k; i < s.length; i++) {
    count += Number(vowels.has(s[i])) - Number(vowels.has(s[i - k]));
    ans = Math.max(ans, count);
  }

  return ans;
}
