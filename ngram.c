#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  // Make sure the program is run with an N parameter
  if (argc != 2) {
    fprintf(stderr, "Usage: %s N (N must be >= 1)\n", argv[0]);
    exit(1);
  }

  // Convert the N parameter to an integer
  int N = atoi(argv[1]);

  // Make sure N is >= 1
  if (N < 1) {
    fprintf(stderr, "Invalid N value %d\n", N);
    exit(1);
  }

  // TODO: read from standard input and print out ngrams until we reach the end of the input



  // create a buffer to place the N grams in
  char str[N];

  int i = 0;


  //store each next character in temp
  char temp;


  // read N chars into str buffer
  for (i = 0; i < N; i++) {
    if(feof(stdin))
    {
      return 0; //if less than N characters in input stop and return
    }
    str[i] = fgetc(stdin);
  }


//as long as we don't reach end of input (this line is not totally necessary because I am already checking this condition in the body of all operations but it is better to have it)
  while (!feof(stdin)) {


    // print the n gram
    for (int j = 0; j < N; j++) {
      printf("%c", str[j]);
    }


    // ngram done
    printf("\n");


    // discard first element in str and add a new element with fgetc if there are still characters in the file stream
      if((feof(stdin)))
      {
        return 0;
      }
    temp = fgetc(stdin);




//refill str with new characters
    for (int k = 0; k < N - 1; k++) {
      str[k] = str[k + 1];
    }
    str[N - 1] = temp;


  } //end of while loop

  return 0;
}
