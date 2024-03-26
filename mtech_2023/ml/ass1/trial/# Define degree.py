# Define degree
degree = 2

# Iterate over possible values of m and n such that m + n = degree
for m in range(degree + 1):
    for n in range(degree - m + 1):
        # Calculate the expression (x1^m) * (x2^n)
        result = (x1 ** m) * (x2 ** n)
        print(f'(x1^{m})*(x2^{n}) = {result}')