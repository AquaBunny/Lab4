/************************************************************************
*Daniel Bachler
*CS120
*10/20/15
*primes1.c
*	is_prime checks to see if a number is prime, conjecture checks if 
*	two primes added together equal every even number
************************************************************************/

#include <stdio.h> /* printf */
/*defining true and false for easier use*/
#define FALSE 0
#define TRUE  1

/*Checks to see if a number is prime*/
int is_prime(int number)
{
	int i, timesDivisible = 0, toReturn = 0; /*i is loop counter, timesDivisible is the amount of times the i is perfectly divisible
	and toReturn is the returned value of true or false*/
	for(i = 1; i <= number; i++) { /*runs once for every number from 1 to the given value*/
		int result = number % i; /*puts the divisor remainder into result*/
		if(result == 0) { /*if the number was a divisor, then increments timesDivisible*/
			timesDivisible++; /*increments timesDivisible*/
		}
		if(timesDivisible > 1)
			break;
	}
	if(timesDivisible == 2) { /*If the number is prime then it will only have been divided 2x*/
		toReturn = TRUE; /*sets toReturn to true*/
	} else if(timesDivisible > 2) { /*Anything besides primes wind up here*/
		toReturn = FALSE; /*sets toReturn to false*/
	}
	return toReturn;
}

/*Checks to see if Goldbachs Conjecture is true*/
void conjecture(int low, int high)
{
	int i, j, k, toBreak; /*i, j, and k are loop counters, toBreak is used to determine if the program needs to end*/
	for(i = low; i <= high; i++) { /*runs every number inclusive from low to high*/
		if(i % 2 == 0) { /*checks to see if i is even, if so rest of the loop runs*/
			toBreak = 0; /*resets toBreak*/
			for(j = 1; j <= high; j++) { /*Checks for primes between 1 and high*/
				int toRun = is_prime(j); /*checks if j is prime and stores answer*/
				if(toRun == 1) { /*if j is prime, runs rest of code*/
					for(k = 1; k <= high; k++) { /*Checks for second prime between 1 and high*/
						int isPrime = is_prime(k); /*checks to see if k is prime and stores answer*/
						if(isPrime == 1) { /*If k is prime too, runs*/
							if(j+k == i) { /*If the conjecture is true, prints out variable and sets loops to end*/
								printf("%3i = %3i + %3i\n", i, j, k); /*prints conjecture*/
								toBreak = 1; /*tells loop it doesnt need to run again*/
							}
						}
						if(toBreak) /*ends for loop if conjecture has been found*/
							break;
					}
				}
				if(toBreak) /*ends for loop if conjecture has been found*/
					break;
			}
		}
	}
}