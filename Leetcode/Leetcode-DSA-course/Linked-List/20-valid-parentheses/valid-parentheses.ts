function isValid(s: string): boolean {
    let stack = [];
    let matching = { '(': ')', '{': '}', '[': ']' };
    for (let c of s) {
        if (c in matching)
            stack.push(c);
        else {
            if (!stack.length)
                return false;
            let previousOpening = stack.pop()
            if (matching[previousOpening] != c)
                return false;
        }

    }
    return !stack.length
};