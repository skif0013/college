def prime_factors(n):
    factors = []
    divisor = 2
    while n > 1:
        while n % divisor == 0:
            factors.append(divisor)
            n //= divisor
        divisor += 1
    return factors


number = 250
factors = prime_factors(number)
print(f"{number} = {', '.join(map(str, factors))}")