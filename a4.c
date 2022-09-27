#include <stdio.h>
#include "a4.h"

/*
 * Name: Jason Phung
 * Email: phungj@uoguelph.ca
 * Student ID: 1047734
 * Compile with gcc -Wall -ansi -pedantic -c a4.c -o a4.o
 */

/* hash1 was created with referece to the djb2 hash algorithm
 * It was then modified so that the function works best with the last names
 * Here is a link to where I referenced my code:
 * http://www.cse.yorku.ca/~oz/hash.html
 * The number "733" was gotten from the list of primes from:
 * https://en.wikipedia.org/wiki/List_of_prime_numbers
 */
int hash1(char *string, int hash_size)
{
	unsigned int hash = 733;
  	char *c;
  	c = string;
  	while (*c != '\0')
  	{
    	hash = hash * 33 + *c; 
    	++c;
  	}
  	return hash % hash_size;
}

/*
 * hash2 was created with reference to the FNV hash algorithm
 * It was modified to work best for license number
 * Here is a link to where I got the algorithm:
 * http://www.isthe.com/chongo/tech/comp/fnv/
 */
int hash2(char *string, int hash_size)
{
	unsigned int hash = 700;
  	char *c;
    c = string;
    while (*c != '\0')
    {
      hash = hash ^ *c;
      hash = hash * 881;
      ++c;
    }
    return hash % hash_size;
}


/*
 * hash3 is very similar to hash1 but works best with issue date
 * it also uses teh djb2 algorithm with modifications to work better
 */
int hash3(char *string, int hash_size)
{
	unsigned int hash = 0;
  	char *c;
  	c = string;
  	while (*c != '\0')
  	{
    	hash = hash * 13 + *c;
    	++c;
  	}
  	return hash % hash_size;
}
