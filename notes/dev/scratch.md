
Number of digits exercise



1. Write a program that constructs a multiplication table for all values 1 up to $n$ where $n$ is read in as a command line argument
2. Write a program to compute a sum of the (partial) harmonic series:
  $$\sum_{i=1}^{n} \frac{1}{i}$$
3. Write a program to compute your massive fake profits from Doge Coin: assume it increases in value every week by 20% and that you "bank" half of your profits each week.
4. Compute a loan amortization table using a monthly payment formula:
  $$P = \frac{rate \times principle}{1-(1+rate)^{-n}}$$
where
 * rate is the rate per period (.05/12 for monthly payments)
 * $n$ is the number of periods (months) in the loan
 * Ex: A $10,000 5 year loan at 5% interest (60 payments):
 $$\frac{\frac{.05}{60} \times 10,000}{1-(1+\frac{.05}{60})^{-60}}$$

```text
Month Balance Interest New Balance
    1   $10000.00   $   41.67   $  147.04  $ 9852.96
    2   $ 9852.96   $   41.05   $  147.66  $ 9705.30
    3   $ 9705.30   $   40.44   $  148.27  $ 9557.03
    4   $ 9557.03   $   39.82   $  148.89  $ 9408.14
    5   $ 9408.14   $   39.20   $  149.51  $ 9258.63
    6   $ 9258.63   $   38.58   $  150.13  $ 9108.50
```
