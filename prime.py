def countPrimes(n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return 0
        prime = [0]*n    # 这个是类似状态组的东西
        l = int(n**0.5)    # 最大遍历上限为√n
        for i in range(2, l+1):
            if prime[i]:    # 合数直接过
                continue
            prime[i*i:n:i] = [1]*len(prime[i*i:n:i])    #如果是质数，质数平方开始到n之间步距为i的每个位置存1
        return len(prime) - sum(prime) -2    # 输出总数字与合数的差（-2是去除0 和1）

def A(m, n):
    r = 1
    for i in range(n):
        r = m * r
        r = r % (1e9+7)
        m -= 1
    return r % (1e9+7)

if __name__ == "__main__":
    print("{0,", end='')
    for i in range(1, 101):
        primes = countPrimes(i + 1)
        result = A(i - primes, i - primes) * A(primes, primes)
        result = result % (1e9+7)
        print(primes, end=',')
    print("}")