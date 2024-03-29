# CPU-Scheduling-Algorithms

<h2>INTRODUCTION</h2>

<pre>

In this project, we implemented all the CPU scheduling algorithms covered during our
theory class. The list of CPU scheduling algorithms implemented here are:

  1. First-Come, First-Served (FCFS) Scheduling
  2. Non-preemptive Shortest-Job-First (SJF) Scheduling
  3. Preemptive Shortest-Job-First (SJF) Scheduling
  4. Non-preemptive Priority Scheduling
  5. Preemptive Priority Scheduling
  6. Round Robin (RR) Scheduling
  7. Our Proposed CPU Scheduling Algorithm
  
CPU scheduling is a technique that fully utilizes the CPU by allowing one process to use it while
another process is in a waiting state due to a lack of resources. The ultimate object of CPU
scheduling algorithm is to maximize CPU utilization, maximum throughput, less average waiting 
time, less response time and less turnaround time. In our proposed algorithm, a new scheduling
algorithm based on round robin and preemptive priority scheduling is designed and
implemented. Here our new algorithm provides less starvation problem and less response time.
  
</pre>


<h2> Our Proposed Algorithm </h2>

<pre>
We want to provide an algorithm that will lessen the starvation problem while simultaneously
reducing response time. We are going to take a time slice so that each process receives an equal
amount of time. Every process will be given a priority rating (lower number means higher
priority) and their last active time will be tracked here. The process which was active in the CPU
a long time ago will have a higher chance of getting the CPU. The priority of the process is also
taken into consideration. So, the two criteria for choosing which process will use the CPU for the
duration of a time slice are: (i) last active time in the CPU and (ii) priority describing number. If
a process has higher priority, and it was active a long time ago, this combination will result in
higher chance of getting the CPU. Lower priority or recently run processes will have a lower
chance of getting the CPU. For processes that have just arrived, the last active time of these
processes are set to negative infinity, so they get the CPU at the earliest time possible. If multiple
processes arrive at the same time with varying priority, they all get the CPU one after another
depending on their priority. Thus, we will experience less starvation and a faster response time as
a result.

</pre>


<h2 align = 'center'>FlowChart of our Proposed Algorithm</h3>
<img src = "https://user-images.githubusercontent.com/84468462/212688588-37597bdc-2210-44be-8507-288e91cdb94d.png"/>
<hr>
<h2 align = 'center'>Result Comparision</h2>
<img src = "https://user-images.githubusercontent.com/84468462/212688309-04bb1b5a-644d-4358-a648-a3e5e90599fa.png"/>


