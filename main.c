#include <stdio.h>

// function prototypes
void fill_sieve();
void delete_non_primes();
void delete_multiples_of_prime(int prime);
void print_primes();

// macros
#define ARRAY_SIZE 5000 // arbitrary size
#define DELETED 0

int sieve[ARRAY_SIZE];

int main(){
  // initialize all array elements with 1
  fill_sieve();

  // delete all non prime numbers
  delete_non_primes();

  // print all the remaining numbers
  print_primes();
  
  return 0;
}

void fill_sieve(){
  int index;

  for(index=2; index < ARRAY_SIZE; index++){
    sieve[index] =1;
  }
  
}

void delete_non_primes(){

  int index;

  for(index = 2; index < ARRAY_SIZE; index++){
    // check if element at that index has been deleted, if not, delete multiples of the element at that index
    if(sieve[index] != DELETED){
      delete_multiples_of_prime(index);
    }
  }
}

void delete_multiples_of_prime(int prime){
  int index, multiplier = 2;

  for(index = prime * multiplier; index < ARRAY_SIZE; index = prime * multiplier++){
    sieve[index] = DELETED;
  }
  
}


void print_primes(){
  int index;

  for(index=2; index < ARRAY_SIZE; index++){
    if(sieve[index] != DELETED){
      printf("%d ", index);
    }
  }

  printf("\n");
}
