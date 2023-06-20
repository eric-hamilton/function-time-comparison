"""
Template for comparing the speed of two functions - AI Time Checker
Repo Link: https://github.com/eric-hamilton/ai-time-checker
Created by Eric Hamilton
GitHub: https://github.com/eric-hamilton
"""

extends Node

func _ready():
    main()
    
# User-defined function
func my_function():
    # Add your own code here
    pass

# AI-generated function
func ai_function():
    # Add AI code here
    pass

func main():
    var num_runs = 3  # Number of times to run each function

    var my_times = []
    var ai_times = []

    var my_total_time = 0.0
    var ai_total_time = 0.0

    for i in range(num_runs):
        var start_time = OS.get_ticks_usec()

        my_function() # Add any required arguments here

        var my_time = (OS.get_ticks_usec() - start_time) / 1000.0

        my_total_time += my_time
        my_times.append(my_time)

        start_time = OS.get_ticks_usec()

        ai_function() # Add any required arguments here

        var ai_time = (OS.get_ticks_usec() - start_time) / 1000.0

        ai_total_time += ai_time
        ai_times.append(ai_time)

    print("My average time: %.10f milliseconds" % (my_total_time / num_runs))
    print("AI average time: %.10f milliseconds" % (ai_total_time / num_runs))
    print("\n")

    print("My execution times:")
    for i in range(my_times.size()):
       print("Run %d: %.10f milliseconds" % [i + 1, my_times[i]])


    print("AI execution times:")
    for i in range(ai_times.size()):
        print("Run %d: %.10f milliseconds" % [i + 1, ai_times[i]])


    if my_total_time > ai_total_time:
        var time_factor = my_total_time / ai_total_time
        print("AI is, on average, %.2f times faster." % time_factor)
    else:
        var time_factor = ai_total_time / my_total_time
        print("Mine is, on average, %.2f times faster." % time_factor)

    yield(get_tree().create_timer(0.0), "timeout")
