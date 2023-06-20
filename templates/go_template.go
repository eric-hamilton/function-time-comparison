package main

import (
	"fmt"
	"time"
)

// User-defined function
func myFunction() {
	// Add your own code here
}

// AI-generated function
func aiFunction() {
	// Add AI code here
}

const numRuns = 3 // Number of times to run each function

func main() {
	var myTimes []time.Duration
	var aiTimes []time.Duration

	var myTotalTime time.Duration
	var aiTotalTime time.Duration

	for i := 0; i < numRuns; i++ {
		start := time.Now()
		myFunction() // Add any required arguments here
		myTime := time.Since(start)

		start = time.Now()
		aiFunction() // Add any required arguments here
		aiTime := time.Since(start)

		myTotalTime += myTime
		aiTotalTime += aiTime
		myTimes = append(myTimes, myTime)
		aiTimes = append(aiTimes, aiTime)
	}

	fmt.Println("My average time:", myTotalTime/time.Duration(numRuns), "seconds")
	fmt.Println("AI average time:", aiTotalTime/time.Duration(numRuns), "seconds")
	fmt.Println()

	fmt.Println("My execution times:")
	for i, myTime := range myTimes {
		fmt.Printf("Run %d: %s\n", i+1, myTime)
	}

	fmt.Println("AI execution times:")
	for i, aiTime := range aiTimes {
		fmt.Printf("Run %d: %s\n", i+1, aiTime)
	}

	if myTotalTime > aiTotalTime {
		timeFactor := float64(myTotalTime) / float64(aiTotalTime)
		fmt.Printf("AI is, on average, %.2f times faster.\n", timeFactor)
	} else {
		timeFactor := float64(aiTotalTime) / float64(myTotalTime)
		fmt.Printf("Mine is, on average, %.2f times faster.\n", timeFactor)
	}

	fmt.Println("Press Enter to exit")
	fmt.Scanln()
}
