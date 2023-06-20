/*
Template for comparing the speed of two functions - AI Time Checker
Repo Link: https://github.com/eric-hamilton/ai-time-checker
Created by Eric Hamilton
GitHub: https://github.com/eric-hamilton
*/

use std::time::Instant;

// User-defined function
fn my_function() {
    // Add your own code here
}

// AI-generated function
fn ai_function() {
    // Add AI code here
}

fn main() {
    let num_runs = 3;  // Number of times to run each function

    let mut my_times = Vec::new();
    let mut ai_times = Vec::new();

    let mut my_total_time = 0.0;
    let mut ai_total_time = 0.0;

    for _ in 0..num_runs {
        let my_start_time = Instant::now();
        my_function(); // Add any required arguments here
        let my_end_time = Instant::now();
        let my_duration = my_end_time.duration_since(my_start_time);

        let ai_start_time = Instant::now();
        ai_function(); // Add any required arguments here
        let ai_end_time = Instant::now();
        let ai_duration = ai_end_time.duration_since(ai_start_time);

        let my_time = my_duration.as_secs_f64();
        let ai_time = ai_duration.as_secs_f64();

        my_total_time += my_time;
        ai_total_time += ai_time;
        my_times.push(my_time);
        ai_times.push(ai_time);
    }

    println!("My average time: {:.10} seconds", my_total_time / (num_runs as f64));
    println!("AI average time: {:.10} seconds", ai_total_time / (num_runs as f64));
    println!();

    println!("My execution times:");
    for (i, my_time) in my_times.iter().enumerate() {
        println!("Run {}: {:.10} seconds", i + 1, my_time);
    }

    println!("AI execution times:");
    for (i, ai_time) in ai_times.iter().enumerate() {
        println!("Run {}: {:.10} seconds", i + 1, ai_time);
    }

    if my_total_time > ai_total_time {
        let time_factor = my_total_time / ai_total_time;
        println!("AI is, on average, {:.2} times faster.", time_factor);
    } else {
        let time_factor = ai_total_time / my_total_time;
        println!("Mine is, on average, {:.2} times faster.", time_factor);
    }

    let _ = std::io::stdin().read_line(&mut String::new());
}
