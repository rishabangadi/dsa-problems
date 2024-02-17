class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        Map<Character, Character> matching = new HashMap<>();
        matching.put('(', ')');
        matching.put('{', '}');
        matching.put('[', ']');
        for (char c : s.toCharArray()) {
            if (matching.containsKey(c))
                stack.push(c);
            else {
                if (stack.empty())
                    return false;
                char previousOpening = stack.pop();
                if (matching.get(previousOpening) != c)
                    return false;
            }
        }
        return stack.empty();
    }
}