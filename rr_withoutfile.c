 #include <stdio.h>

struct Process {
    int process_id;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void roundRobin(struct Process processes[], int n, int quantum) {
    int time = 0;
    int flag = 0; // Flag to check if any process is remaining
    float total_waiting_time = 0, total_turnaround_time = 0;

    printf("\nRound Robin Scheduling\n");
    printf("Time Quantum: %d\n\n", quantum);
    printf("Gantt Chart:\n|");

    while (1) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= time) {
                flag = 1;
                if (processes[i].remaining_time > quantum) {
                    printf(" P%d |", processes[i].process_id);
                    processes[i].start_time = time;
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    printf(" P%d |", processes[i].process_id);
                    processes[i].start_time = time;
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;

                    // Calculate completion time for the process
                    processes[i].completion_time = time;

                    // Calculate turnaround time and waiting time for each process
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

                    total_waiting_time += processes[i].waiting_time;
                    total_turnaround_time += processes[i].turnaround_time;
                }
            }
        }
        if (flag == 0)
            break;
    }

    printf("\n\nProcess\t| Arrival Time\t| Burst Time\t| Start Time\t| Completion Time\t| Turnaround Time\t| Waiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t| %d\t\t| %d\t\t| %d\t\t| %d\t\t\t| %d\t\t\t| %d\n",
               processes[i].process_id, processes[i].arrival_time, processes[i].burst_time,
               processes[i].start_time, processes[i].completion_time,
               processes[i].turnaround_time, processes[i].waiting_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].process_id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    roundRobin(processes, n, quantum);

    return 0;
}
