/*
Template for comparing the speed of two functions - AI Time Checker
Repo Link: https://github.com/eric-hamilton/ai-time-checker
Created by Eric Hamilton
GitHub: https://github.com/eric-hamilton
*/

#include <stdio.h>
#include <time.h>

void my_function()
{
    // Add your code here
}

void ai_function()
{
    // Add AI code here
}

int main()
{
    int num_runs = 3;  // Number of times to run each function

    double my_times[num_runs];
    double ai_times[num_runs];

    double my_total_time = 0.0;
    double ai_total_time = 0.0;

    for (int i = 0; i < num_runs; ++i)
    {
        clock_t my_start = clock();
        my_function(); // Add any required arguments here
        clock_t my_end = clock();
        double my_time = (double)(my_end - my_start) / CLOCKS_PER_SEC;

        clock_t ai_start = clock();
        ai_function(); // Add any required arguments here
        clock_t ai_end = clock();
        double ai_time = (double)(ai_end - ai_start) / CLOCKS_PER_SEC;

        my_total_time += my_time;
        ai_total_time += ai_time;
        my_times[i] = my_time;
        ai_times[i] = ai_time;
    }

    printf("My average time: %.10f seconds\n", my_total_time / num_runs);
    printf("AI average time: %.10f seconds\n\n", ai_total_time / num_runs);

    printf("My execution times:\n");
    for (int i = 0; i < num_runs; ++i)
    {
        printf("Run %d: %.10f seconds\n", i + 1, my_times[i]);
    }

    printf("\nAI execution times:\n");
    for (int i = 0; i < num_runs; ++i)
    {
        printf("Run %d: %.10f seconds\n", i + 1, ai_times[i]);
    }

    if (my_total_time > ai_total_time)
    {
        double time_factor = my_total_time / ai_total_time;
        printf("AI is, on average, %.2f times faster.\n", time_factor);
    }
    else
    {
        double time_factor = ai_total_time / my_total_time;
        printf("Mine is, on average, %.2f times faster.\n", time_factor);
    }

    return 0;
}
