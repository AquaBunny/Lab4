#include <stdio.h> /* printf */

/* Prototypes implemented in primes1.c */
int is_prime(int n);
void conjecture(int low, int high);

void check_primes(long count)
{
  int primes = 0; /* number of primes found */
  long i;          /* loop counter           */

    /* Check all values from 1 to count */
  for (i = count - 10000; i <= count; i++)
  {
      /* If it's prime, count it and print it */
    if (is_prime(i))
    {
      primes++;
      printf("#%3i: %3li is prime.\n", primes, i);
    }
  }
}

int main(void)
{
  check_primes(1000000000);
  check_primes(2500000000);
  /*conjecture(2, 2000);*/
  return 0;
}