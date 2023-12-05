def minimum_length(t, test_cases):
    results = []

    for i in range(t):
        n, s = test_cases[i]

        stack = []
        for char in s:
            if stack and stack[-1] != char:
                stack.pop()
            else:
                stack.append(char)

        results.append(len(stack))

    return results

# Input
t = int(input())
test_cases = []

for _ in range(t):
    n = int(input())
    s = input()
    test_cases.append((n, s))

# Output
results = minimum_length(t, test_cases)
for result in results:
    print(result)
