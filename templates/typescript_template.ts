// User-defined function
function my_function() {
    // Add your own code here
}

// AI-generated function
function ai_function() {
    // Add AI code here
}

const num_runs = 3; // Number of times to run each function

const my_times = [];
const ai_times = [];

let my_total_time = 0.0;
let ai_total_time = 0.0;

for (let i = 0; i < num_runs; i++) {
    const my_timer = new Date().getTime();
    my_function(); // Add any required arguments here
    const my_time = (new Date().getTime() - my_timer) / 1000;

    const ai_timer = new Date().getTime();
    ai_function(); // Add any required arguments here
    const ai_time = (new Date().getTime() - ai_timer) / 1000;

    my_total_time += my_time;
    ai_total_time += ai_time;
    my_times.push(my_time);
    ai_times.push(ai_time);
}

console.log("My average time:", (my_total_time / num_runs).toFixed(10), "seconds");
console.log("AI average time:", (ai_total_time / num_runs).toFixed(10), "seconds");
console.log("\n");

console.log("My execution times:");
my_times.forEach((my_time, i) => {
    console.log(`Run ${i+1}: ${my_time.toFixed(10)} seconds`);
});

console.log("AI execution times:");
ai_times.forEach((ai_time, i) => {
    console.log(`Run ${i+1}: ${ai_time.toFixed(10)} seconds`);
});

if (my_total_time > ai_total_time) {
    const time_factor = my_total_time / ai_total_time;
    console.log(`AI is, on average, ${time_factor.toFixed(2)} times faster.`);
} else {
    const time_factor = ai_total_time / my_total_time;
    console.log(`Mine is, on average, ${time_factor.toFixed(2)} times faster.`);
}

prompt("Press Enter to exit");
