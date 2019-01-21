dp = [0, 1, 1, 1, 2, 2, ]

for i in range(6, 101):
    dp.insert(i, dp[i-1] + dp[i-5])
    
t = int(input())

for i in range (0, t):
    n = int(input())
    print(dp[n])
