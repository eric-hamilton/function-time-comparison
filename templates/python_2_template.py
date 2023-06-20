"""
Template for comparing the speed of two functions - AI Time Checker
Repo Link: https://github.com/eric-hamilton/ai-time-checker
Created by Eric Hamilton
GitHub: https://github.com/eric-hamilton
"""

import timeit

# User-defined function
def my_function():
    # Add your own code here
    pass

# AI-generated function
def ai_function():
    # Add AI code here
    pass

num_runs = 3  # Number of times to run each function

my_times = []
ai_times = []

my_total_time = 0.0
ai_total_time = 0.0

for _ in range(num_runs):
    my_timer = timeit.Timer(stmt=my_function)  # Add any required arguments here
    ai_timer = timeit.Timer(stmt=ai_function)  # Add any required arguments here

    my_time = my_timer.timeit(number=1)
    ai_time = ai_timer.timeit(number=1)

    my_total_time += my_time
    ai_total_time += ai_time
    my_times.append(my_time)
    ai_times.append(ai_time)

print "My average time:", "{:.10f}".format(my_total_time / num_runs), "seconds"
print "AI average time:", "{:.10f}".format(ai_total_time / num_runs), "seconds"
print "\n"

print "My execution times:"
for i, my_time in enumerate(my_times):
    print "Run {}: {:.10f} seconds".format(i+1, my_time)

print "AI execution times:"
for i, ai_time in enumerate(ai_times):
    print "Run {}: {:.10f} seconds".format(i+1, ai_time)

if my_total_time > ai_total_time:
    time_factor = my_total_time / ai_total_time
    print "AI is, on average, {:.2f} times faster.".format(time_factor)
else:
    time_factor = ai_total_time / my_total_time
    print "Mine is, on average, {:.2f} times faster.".format(time_factor)

try:
    raw_input("Press Enter to exit")
except EOFError:
    pass
