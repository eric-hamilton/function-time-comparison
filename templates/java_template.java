/*
Template for comparing the speed of two functions - AI Time Checker
Repo Link: https://github.com/eric-hamilton/ai-time-checker
Created by Eric Hamilton
GitHub: https://github.com/eric-hamilton
*/

import java.util.ArrayList;
import java.util.List;

public class CompareTimes {
    // User-defined function
    public static void myFunction() {
    }

    // AI-generated function
    public static void aiFunction() {
    }

    public static void main(String[] args) {
        int numRuns = 3; // Number of times to run each function

        List<Double> myTimes = new ArrayList<>();
        List<Double> aiTimes = new ArrayList<>();

        double myTotalTime = 0.0;
        double aiTotalTime = 0.0;

        for (int i = 0; i < numRuns; i++) {
            long start = System.nanoTime();
            myFunction(); // Add any required arguments here
            long end = System.nanoTime();
            double myTime = (end - start) / 1e9; // Convert to seconds

            start = System.nanoTime();
            aiFunction(); // Add any required arguments here
            end = System.nanoTime();
            double aiTime = (end - start) / 1e9; // Convert to seconds

            myTotalTime += myTime;
            aiTotalTime += aiTime;
            myTimes.add(myTime);
            aiTimes.add(aiTime);
        }

        System.out.println("My average time: " + String.format("%.10f", myTotalTime / numRuns) + " seconds");
        System.out.println("AI average time: " + String.format("%.10f", aiTotalTime / numRuns) + " seconds");
        System.out.println();

        System.out.println("My execution times:");
        for (int i = 0; i < myTimes.size(); i++) {
            System.out.println("Run " + (i + 1) + ": " + String.format("%.10f", myTimes.get(i)) + " seconds");
        }

        System.out.println("AI execution times:");
        for (int i = 0; i < aiTimes.size(); i++) {
            System.out.println("Run " + (i + 1) + ": " + String.format("%.10f", aiTimes.get(i)) + " seconds");
        }

        if (myTotalTime > aiTotalTime) {
            double timeFactor = myTotalTime / aiTotalTime;
            System.out.printf("AI is, on average, %.2f times faster.%n", timeFactor);
        } else {
            double timeFactor = aiTotalTime / myTotalTime;
            System.out.printf("Mine is, on average, %.2f times faster.%n", timeFactor);
        }

        System.console().readLine("Press Enter to exit");
    }
}
