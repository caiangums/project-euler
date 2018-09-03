# 014 - Longest Collatz sequence

The following iterative sequence is defined for the set of positive integers:

```
n → n/2 (n is even)
n → 3n + 1 (n is odd)
```

Using the rule above and starting with `13`, we generate the following sequence:

`13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1`
It can be seen that this sequence (starting at `13` and finishing at `1`) contains `10` terms. Although it has not been proved yet (_Collatz Problem_), it is thought that all starting numbers finish at `1`.

Which starting number, under one million, produces the longest chain?

**NOTE**: Once the chain starts the terms are allowed to go above one million.

## Disclaimer

I largelly encourage you try to **solve by yourself** on the Project Euler site and by your own research. If you want to know **how** my solution works, go to `solution.md` file.
