def fact(val):
    return val * fact(val-1) if val > 1 else 1

def fact_stop(val, s):
    return val * fact_stop(val-1, s) if val > s else 1

n = int(input('Give a number\n'))

result = fact_stop(2*n, n)/fact(n)
print('Result = {}'.format(result))
