def solve(N):
    ans = []
    for i in range(2, 42):
        while N % i == 0:
            ans.append(i)
            N //= i
    if N > 1:
        ans.append(N)
    # print(ans)
    s = sum(ans)
    if s <= 41:
        return " ".join(map(str, [len(ans)+41-s] + [1] * (41-s) + ans))
    else:
        return -1

def main():
    T = int(input())
    for t in range(T):
        print(f"Case #{t+1}: {solve(int(input()))}")


if __name__ == "__main__":
    main()