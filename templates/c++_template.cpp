/*
Template for comparing the speed of two functions - AI Time Checker
Repo Link: https://github.com/eric-hamilton/ai-time-checker
Created by Eric Hamilton
GitHub: https://github.com/eric-hamilton
*/

#include <iostream>
#include <chrono>
#include <vector>

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

    std::vector<double> my_times;
    std::vector<double> ai_times;

    double my_total_time = 0.0;
    double ai_total_time = 0.0;

    for (int i = 0; i < num_runs; ++i)
    {
        auto my_start = std::chrono::high_resolution_clock::now();
        my_function(); // Add any required arguments here
        auto my_end = std::chrono::high_resolution_clock::now();
        double my_time = std::chrono::duration<double, std::milli>(my_end - my_start).count();

        auto ai_start = std::chrono::high_resolution_clock::now();
        ai_function(); // Add any required arguments here
        auto ai_end = std::chrono::high_resolution_clock::now();
        double ai_time = std::chrono::duration<double, std::milli>(ai_end - ai_start).count();

        my_total_time += my_time;
        ai_total_time += ai_time;
        my_times.push_back(my_time);
        ai_times.push_back(ai_time);
    }

    std::cout << "My average time: " << std::fixed << (my_total_time / num_runs) << " milliseconds" << std::endl;
    std::cout << "AI average time: " << std::fixed << (ai_total_time / num_runs) << " milliseconds" << std::endl;
    std::cout << "\n";

    std::cout << "My execution times:" << std::endl;
    for (int i = 0; i < my_times.size(); ++i)
    {
        std::cout << "Run " << (i + 1) << ": " << std::fixed << my_times[i] << " milliseconds" << std::endl;
    }
    std::cout.flush();

    std::cout << "AI execution times:" << std::endl;
    for (int i = 0; i < ai_times.size(); ++i)
    {
        std::cout << "Run " << (i + 1) << ": " << std::fixed << ai_times[i] << " milliseconds" << std::endl;
    }
    std::cout.flush();


    if (my_total_time > ai_total_time)
    {
        double time_factor = my_total_time / ai_total_time;
        std::cout << "AI is, on average, " << std::fixed << time_factor << " times faster." << std::endl;
    }
    else
    {
        double time_factor = ai_total_time / my_total_time;
        std::cout << "Mine is, on average, " << std::fixed << time_factor << " times faster." << std::endl;
    }

    return 0;
}
