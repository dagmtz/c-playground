#include <stdlib.h>
#include <stdio.h>

#define EXPECTED_ARGS 3
#define TOTAL_ITEMS 125

const unsigned int items_per_section[EXPECTED_ARGS] = {45, 25, 55};

int main(int argc, char** argv){

  unsigned int wrong_answers[EXPECTED_ARGS] = {0};
  unsigned int correct_answers[EXPECTED_ARGS] = {0};
  unsigned int totals = 0;

  float average = 0;

  if(argc <= EXPECTED_ARGS) {
    printf("Expected %d arguments, received %d\n", EXPECTED_ARGS, argc-1);
    return EXIT_FAILURE;
  }

  for(unsigned int i = 0; i < EXPECTED_ARGS; i++){
    if(atoi(argv[i+1]) < 0U) {
      printf("Only positive integer numbers allowed. Entered: %s\n", argv[i+1]);
      return EXIT_FAILURE;
    }else if (atoi(argv[i+1]) > items_per_section[i])
    {
      printf("The number entered for section %d exceeds the maximum (%s>%d).\n", i, argv[i+1], items_per_section[i]);
      return EXIT_FAILURE;
    }
    
    wrong_answers[i] = atoi(argv[i+1]);
    correct_answers[i] = items_per_section[i] - wrong_answers[i];
    average = (float) correct_answers[i] / (float) items_per_section[i];
    printf("Section %d: %d/%d -> %.2f \n", i+1, correct_answers[i], items_per_section[i], average*100); 
    totals += correct_answers[i];
  }

  printf("Totals: %d/%d -> %.2f\n", totals, TOTAL_ITEMS, ((float) totals/TOTAL_ITEMS)*100);

  return EXIT_SUCCESS;

}
