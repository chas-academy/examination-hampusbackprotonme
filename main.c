#include <stdio.h>

#define NUM_LINES 5
#define NUM_SCORES 13
#define NAME_MAX_LENGHT 10

void capitalize_name(char line[]) {
    if (line[0] > 96)
        line[0] = line[0] - 32;
}

float calculate_avg_score(int scores[]) {
    int sum = 0;
    for (int i = 0; i < NUM_SCORES; i++) {
        sum += scores[i];
    }
    
    return (float)sum / NUM_SCORES;
}

int get_highest_score_index(float avg_scores[]) {
    float highest_score = 0.f;
    int highest_score_index;

    for(int i = 0; i < NUM_LINES; i++) {
        if(avg_scores[i] > highest_score) {
            highest_score = avg_scores[i];
            highest_score_index = i;
        }
    }

    return highest_score_index;
}

float calc_group_avg(float avg_scores[]) {
    float group_sum = 0.f;

    for(int i = 0; i < NUM_LINES; i++) {
        group_sum += avg_scores[i];
    }

    return group_sum / NUM_LINES;
}

int main() {

    char names[NUM_LINES][NAME_MAX_LENGHT + 1];
    int scores[NUM_LINES][NUM_SCORES];
    float avg_scores[NUM_LINES];

    // Read input, store names in one array and all the results in another one.
    for(int i = 0; i < NUM_LINES; i++) {
        scanf("%s", &names[i]);

        for(int j = 0; j < NUM_SCORES; j++) {
            scanf("%d", &scores[i][j]);
        }
    }

    // For each student, capitalize name if needed and calculate their average score
    for(int i = 0; i < NUM_LINES; i++) {
        capitalize_name(names[i]);
        avg_scores[i] = calculate_avg_score(scores[i]);
    }

    // Print the name of the student with the highest average score
    printf("%s\n", names[get_highest_score_index(avg_scores)]);

    // Calculate group average
    float group_avg = calc_group_avg(avg_scores);

    // Print the name of everyone with an average score lower than the average score of the entire group
    for(int i = 0; i < NUM_LINES; i++) {
        if(avg_scores[i] < group_avg)
            printf("%s\n", names[i]);
    }

    return 0;
}
