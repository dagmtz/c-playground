#include <stdlib.h>
#include <stdio.h>

#define SECTIONS 3
#define TOTAL_ITEMS 125

const unsigned int items_per_section[SECTIONS] = {45, 25, 55};

int main(int argc, char** argv){

  while (1)
  {
    int wrong_answers[SECTIONS] = {0};
    unsigned int correct_answers[SECTIONS] = {0};
    unsigned int totals = 0;
    float average = 0;

    for(unsigned int i = 0; i < SECTIONS; i++){
      printf("Enter the number of wrong answers for section %d: ", i+1);
      scanf("%d", &wrong_answers[i]); 

      if(wrong_answers[i] < 0) {
        printf("Entered negative number. Exiting \n");
        return EXIT_FAILURE;
      } else if (wrong_answers[i] > items_per_section[i]) {
        printf("The number entered for section %d exceeds the maximum (%d>%d).\n", i, wrong_answers[i], items_per_section[i]);
        return EXIT_FAILURE;  
      }
      

      correct_answers[i] = items_per_section[i] - wrong_answers[i];
      average = (float) correct_answers[i] / (float) items_per_section[i];
      printf("Section %d: %d/%d -> %.2f \n", i+1, correct_answers[i], items_per_section[i], average*100); 
      totals += correct_answers[i];
    }

    printf("Totals: %d/%d -> %.2f\n\n", totals, TOTAL_ITEMS, ((float) totals/TOTAL_ITEMS)*100);
  }

  return EXIT_FAILURE;

}
