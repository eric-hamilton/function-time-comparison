--[[
Template for comparing the speed of two functions - AI Time Checker
Repo Link: https://github.com/eric-hamilton/ai-time-checker
Created by Eric Hamilton
GitHub: https://github.com/eric-hamilton
]]

-- User-defined function
local function my_function()
    -- Add your own code here
end

-- AI-generated function
local function ai_function()
    -- Add AI code here
end

local num_runs = 3  -- Number of times to run each function

local my_times = {}
local ai_times = {}

local my_total_time = 0.0
local ai_total_time = 0.0

for _ = 1, num_runs do
    local my_timer = os.clock()
    my_function()  -- Add any required arguments here
    local my_time = (os.clock() - my_timer) * 1000
    
    local ai_timer = os.clock()
    ai_function()  -- Add any required arguments here
    local ai_time = (os.clock() - ai_timer) * 1000

    my_total_time = my_total_time + my_time
    ai_total_time = ai_total_time + ai_time
    table.insert(my_times, my_time)
    table.insert(ai_times, ai_time)
end

print("My average time: ", string.format("%.10f", my_total_time / num_runs), " milliseconds")
print("AI average time: ", string.format("%.10f", ai_total_time / num_runs), " milliseconds")
print("\n")

print("My execution times:")
for i, my_time in ipairs(my_times) do
    print("Run ", i, ": ", string.format("%.10f", my_time), " milliseconds")
end

print("AI execution times:")
for i, ai_time in ipairs(ai_times) do
    print("Run ", i, ": ", string.format("%.10f", ai_time), " milliseconds")
end

if my_total_time > ai_total_time then
    local time_factor = my_total_time / ai_total_time
    print("AI is, on average, ", string.format("%.2f", time_factor), " times faster.")
else
    local time_factor = ai_total_time / my_total_time
    print("Mine is, on average, ", string.format("%.2f", time_factor), " times faster.")
end

io.read()  -- Press Enter to exit
