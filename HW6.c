#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//HW6
int range_count(int *scores, int scores_count, int begin, int end){
    int count = 0;
    int score_iter;
    for (score_iter = 0; score_iter < scores_count; score_iter++){
        if (scores[score_iter] >= begin && scores[score_iter] <= end){
            count++;
        }
    }
    return count;
}


int main()
{
    int scores_count;
    printf("Enter how many scores do you want to process: ");
    scanf(" %d", &scores_count);
    int *scores = malloc(scores_count * sizeof(int));
    if (scores == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    int score_iter;
    printf("Enter your %d scores: ", scores_count);
    for (score_iter = 0; score_iter < scores_count; score_iter++){
        scanf(" %d", &scores[score_iter]);
    }
    printf("Here is your report: \n");
    int passing = 0;
    for (score_iter = 0; score_iter < scores_count; score_iter++){
        if (scores[score_iter] >= 70){
            passing++;
        }

    }
    printf("\t- %d students passed the test with a score of 70 or higher\n\n", passing);
    printf("\t- Letter Grade distribution of the scores: ");
    printf("\n\t\t%d Students earned the grade of A (90-100)", range_count(&scores, scores_count, 90, 100));
    printf("\n\t\t%d Students earned the grade of B (80-89)", range_count(&scores, scores_count, 80, 89));
    printf("\n\t\t%d Students earned the grade of C (70-79)", range_count(&scores, scores_count, 70, 79));
    printf("\n\t\t%d Students earned the grade of D (60-69)", range_count(&scores, scores_count, 60, 69));
    printf("\n\t\t%d Students earned the grade of 59 or below", range_count(&scores, scores_count, 0, 59));
    float std;
    int mn= 0;
    for (score_iter = 0; score_iter < scores_count; score_iter++){
        mn+= scores[score_iter];
    }
    mn = mn/scores_count;
    int single_dev;
    int added_devs = 0;
    for (score_iter = 0; score_iter < scores_count; score_iter++){
        single_dev = scores[score_iter] - mn;
        added_devs += single_dev * single_dev;
    printf("\nGoodbye!");
    free(scores);
    return 0;
}
    printf("\n\n\t- The Standard deviation of the scores is: %f", std);
    printf("\nGoodbye!");
    return 0;
}
