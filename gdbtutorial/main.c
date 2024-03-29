/* prime-number finding program
 *  
 *  Will (after bugs are fixed) report a list of all primes which are  less than
 *  or equal to the user-supplied upper bound.   It is riddled with errors! */
 
#include <stdio.h>
void CheckPrime(int K, int Prime[]); /* prototype for function in prime.c */
 
int Prime[50],  /* Prime[i] will be 1 if i is prime, 0 otherwise */
UpperBound; /* check all number up through this one for primeness */
 
int main()
{
  int i;
 
  printf("Enter upper bound:\n");
  scanf("%d", &UpperBound);
 
  Prime[1] = 1;
  Prime[2] = 1;
 
  for (i = 3; i <= UpperBound; i += 2) {
    CheckPrime(i, Prime);
    if (Prime[i])
      printf("%d is a prime\n", i);
  }
  return 0;
} /* main() */
