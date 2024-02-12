function checkIfPangram(sentence: string): boolean {
  const hashSet = new Set(sentence);
  return hashSet.size == 26;
}
