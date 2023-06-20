/*
Template for comparing the speed of two functions - AI Time Checker
Repo Link: https://github.com/eric-hamilton/ai-time-checker
Created by Eric Hamilton
GitHub: https://github.com/eric-hamilton
*/

using System;
using System.Diagnostics;

class Program
{
    // User-defined function
    static void MyFunction()
    {
        // Add your own code here
    }

    // AI-generated function
    static void AiFunction()
    {
        // Add AI code here
    }

    static void Main()
    {
        int numRuns = 3;  // Number of times to run each function

        double[] myTimes = new double[numRuns];
        double[] aiTimes = new double[numRuns];

        double myTotalTime = 0.0;
        double aiTotalTime = 0.0;

        for (int i = 0; i < numRuns; i++)
        {
            Stopwatch myTimer = Stopwatch.StartNew();
            MyFunction(); // Add any required arguments here
            myTimer.Stop();

            Stopwatch aiTimer = Stopwatch.StartNew();
            AiFunction(); // Add any required arguments here
            aiTimer.Stop();

            double myTime = myTimer.Elapsed.TotalMilliseconds;
            double aiTime = aiTimer.Elapsed.TotalMilliseconds;

            myTotalTime += myTime;
            aiTotalTime += aiTime;
            myTimes[i] = myTime;
            aiTimes[i] = aiTime;
        }

        Console.WriteLine("My average time: {0:F10} milliseconds", myTotalTime / numRuns);
        Console.WriteLine("AI average time: {0:F10} milliseconds", aiTotalTime / numRuns);
        Console.WriteLine();

        Console.WriteLine("My execution times:");
        for (int i = 0; i < numRuns; i++)
        {
            Console.WriteLine("Run {0}: {1:F10} milliseconds", i + 1, myTimes[i]);
        }

        Console.WriteLine("AI execution times:");
        for (int i = 0; i < numRuns; i++)
        {
            Console.WriteLine("Run {0}: {1:F10} milliseconds", i + 1, aiTimes[i]);
        }

        if (myTotalTime > aiTotalTime)
        {
            double timeFactor = myTotalTime / aiTotalTime;
            Console.WriteLine("AI is, on average, {0:F2} times faster.", timeFactor);
        }
        else
        {
            double timeFactor = aiTotalTime / myTotalTime;
            Console.WriteLine("Mine is, on average, {0:F2} times faster.", timeFactor);
        }

        Console.ReadLine();
    }
}
