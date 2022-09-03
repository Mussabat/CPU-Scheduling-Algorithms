#include <bits/stdc++.h>
#include<windows.h>

using namespace std;

struct process {
    string id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int current_remaining_time_quantum;
    int priority;
    int end_time;
    int first_active = 1e9;
    int last_active = -1e9;
};

bool operator<(const process& a, const process& b) {
    return a.arrival_time < b.arrival_time;
}

struct cmp_non_preemptive_sjf {
    bool operator()(const process& a, const process& b) {
        if (a.burst_time > b.burst_time) return true;
        if (a.burst_time < b.burst_time) return false;
        if (a.arrival_time > b.arrival_time) return true;
        if (a.arrival_time < b.arrival_time) return false;
        return a.id > b.id;
    }
};

struct cmp_preemptive_sjf {
    bool operator()(const process& a, const process& b) {
        if (a.remaining_time > b.remaining_time) return true;
        if (a.remaining_time < b.remaining_time) return false;
        if (a.arrival_time > b.arrival_time) return true;
        if (a.arrival_time < b.arrival_time) return false;
        return a.id > b.id;
    }
};

struct cmp_priority {
    bool operator()(const process& a, const process& b) {
        if (a.priority > b.priority) return true;
        if (a.priority < b.priority) return false;
        if (a.arrival_time > b.arrival_time) return true;
        if (a.arrival_time < b.arrival_time) return false;
        return a.id > b.id;
    }
};

struct cmp_rr {
    bool operator()(const process& a, const process& b) {
        if (a.arrival_time > b.arrival_time) return true;
        if (a.arrival_time < b.arrival_time) return false;
        return a.id > b.id;
    }
};

struct cmp_our_proposed {
    bool operator()(const process& a, const process& b) {
        if (a.priority + a.last_active > b.priority + b.last_active) return true;
        if (a.priority + a.last_active < b.priority + b.last_active) return false;
        if (a.arrival_time > b.arrival_time) return true;
        if (a.arrival_time < b.arrival_time) return false;
        return a.id > b.id;
    }
};

class os {
  public:
    void choice();
    void  FCFS(vector <process> v);
    void  NON_PREEMPTIVE_SJF(vector <process> v);
    void  PREEMPTIVE_SJF(vector <process> v);
    void  NON_PREEMPTIVE_PRIORITY(vector <process> v);
    void  PREEMPTIVE_PRIORITY(vector <process> v);
    void  ROUND_ROBIN(vector <process> v, int time_quantum);
    void  OUR_PROPOSED_ALGORITHM(vector <process> v, int time_quantum);
    void  COMPARE_ALL(vector <process> v, int time_quantum);

  private:
    int time_quantum;
    vector <process> v;
    vector <double> avg_waiting_time, avg_turnaround_time, avg_response_time;
};

int main() {
    cout << '\n';
    cout << '\n';
    cout << "\t\t\t\t OPERATING SYSTEM PROJECT" << '\n';
    cout << "\t\t\t\t **************************" << '\n';

    os call ;
    call.choice();

    return 0;
}


void os :: choice() {
    int n;
    avg_waiting_time = vector <double> (7);
    avg_turnaround_time = vector <double> (7);
    avg_response_time = vector <double> (7);
    char option;
    while(1) {
        cout << "\n\n\t Press " << endl;
        cout << "\t =====" << endl << endl;
        cout << "  1. FCFS" << endl;
        cout << "  2. NON-PREEMTIVE - SJF" << endl;
        cout << "  3. PREEMTIVE - SJF" << endl;
        cout << "  4. NON PREEMPTIVE - PRIORITY" << endl;
        cout << "  5. PREEMPTITIVE - PRIORITY" << endl;
        cout << "  6. ROUND-ROBIN" << endl;
        cout << "  7. OUR PROPOSED ALGORITHM" << endl;
        cout << "  8. COMPARE-ALL" << endl;
        cout << "  9. EXIT" << endl;

        cout << '\n';
        cout << '\n';
        cout << '\n';

        cout <<"\t\t\t\t";
        cout << "Input Your Choice :  ";
        cin >> option;

        system("CLS");
        switch(option) {

        case '1' :
            cout << "Number of process: ";
            cin >> n;
            cout << '\n';

            v = vector <process> (n);

            for (int i = 0; i < n; i++) {
                process& p = v[i];
                cout << "Enter the arrival time of ";
                p.id += "P";
                p.id += ((i + 1) + '0');
                cout << p.id << " : ";
                cin >>  p.arrival_time;
                cout << "Enter the burst time of ";
                cout << p.id << " : ";
                cin >> p.burst_time;
                p.remaining_time = p.burst_time;
                cout << '\n';
            }

            os :: FCFS(v);
            break;
        case '2' :
            cout << "Number of process: ";
            cin >> n;
            cout << '\n';

            v = vector <process> (n);

            for (int i = 0; i < n; i++) {
                process& p = v[i];
                cout << "Enter the arrival time of ";
                p.id += "P";
                p.id += ((i + 1) + '0');
                cout << p.id << " : ";
                cin >>  p.arrival_time;
                cout << "Enter the burst time of ";
                cout << p.id << " : ";
                cin >> p.burst_time;
                p.remaining_time = p.burst_time;
                cout << '\n';

            }

            os :: NON_PREEMPTIVE_SJF(v);
            break;

        case '3' :
            cout << "Number of process: ";
            cin >> n;
            cout << '\n';

            v = vector <process> (n);

            v = vector <process>(n);
            for (int i = 0; i < n; i++) {
                process& p = v[i];
                cout << "Enter the arrival time of ";
                p.id += "P";
                p.id += ((i + 1) + '0');
                cout << p.id << " : ";
                cin >>  p.arrival_time;
                cout << "Enter the burst time of ";
                cout << p.id << " : ";
                cin >> p.burst_time;
                p.remaining_time = p.burst_time;
                cout << '\n';

            }

            os :: PREEMPTIVE_SJF(v);
            break;

        case '4' :
            cout << "Number of process: ";
            cin >> n;
            cout << '\n';

            v = vector <process> (n);

            v = vector <process>(n);
            for (int i = 0; i < n; i++) {
                process& p = v[i];
                cout << "Enter the arrival time of ";
                p.id += "P";
                p.id += ((i + 1) + '0');
                cout << p.id << " : ";
                cin >>  p.arrival_time;
                cout << "Enter the burst time of ";
                cout << p.id << " : ";
                cin >> p.burst_time;
                p.remaining_time = p.burst_time;
                cout << "Enter the priority of ";
                cout << p.id << " : ";
                cin >> p.priority;
                cout << '\n';

            }
            os :: NON_PREEMPTIVE_PRIORITY(v);
            break;

        case '5' :
            cout << "Number of process: ";
            cin >> n;
            cout << '\n';

            v = vector <process> (n);

            v = vector <process>(n);
            for (int i = 0; i < n; i++) {
                process& p = v[i];
                cout << "Enter the arrival time of ";
                p.id += "P";
                p.id += ((i + 1) + '0');
                cout << p.id << " : ";
                cin >>  p.arrival_time;
                cout << "Enter the burst time of ";
                cout << p.id << " : ";
                cin >> p.burst_time;
                p.remaining_time = p.burst_time;
                cout << "Enter the priority of ";
                cout << p.id << " : ";
                cin >> p.priority;
                cout << '\n';

            }

            os :: PREEMPTIVE_PRIORITY(v);
            break;
        case '6' :
            cout << "Number of process : ";
            cin >> n;
            cout << '\n';

            cout << "Time Quantum : ";
            cin >> time_quantum;

            v = vector <process>(n);
            for (int i = 0; i < n; i++) {
                process& p = v[i];
                cout << "Enter the arrival time of ";
                p.id += "P";
                p.id += ((i + 1) + '0');
                cout << p.id << " : ";
                cin >>  p.arrival_time;
                cout << "Enter the burst time of ";
                cout << p.id << " : ";
                cin >> p.burst_time;
                p.remaining_time = p.burst_time;
                p.current_remaining_time_quantum = time_quantum;
                cout << '\n';

            }

            os :: ROUND_ROBIN(v, time_quantum);
            break;
        case '7' :
            cout << "Number of process : ";
            cin >> n;
            cout << '\n';

            cout << "Time Quantum : ";
            cin >> time_quantum;

            v = vector <process>(n);
            for (int i = 0; i < n; i++) {
                process& p = v[i];
                cout << "Enter the arrival time of ";
                p.id += "P";
                p.id += ((i + 1) + '0');
                cout << p.id << " : ";
                cin >>  p.arrival_time;
                cout << "Enter the burst time of ";
                cout << p.id << " : ";
                cin >> p.burst_time;
                p.remaining_time = p.burst_time;
                p.current_remaining_time_quantum = time_quantum;
                cout << "Enter priority: ";
                cin >> p.priority;
                cout << '\n';

            }

            os :: OUR_PROPOSED_ALGORITHM(v, time_quantum);
            break;
        case '8' :
            cout << "Number of process : ";
            cin >> n;
            cout << '\n';

            cout << "Time Quantum : ";
            cin >> time_quantum;

            v = vector <process>(n);
            for (int i = 0; i < n; i++) {
                process& p = v[i];
                cout << "Enter the arrival time of ";
                p.id += "P";
                p.id += ((i + 1) + '0');
                cout << p.id << " : ";
                cin >>  p.arrival_time;
                cout << "Enter the burst time of ";
                cout << p.id << " : ";
                cin >> p.burst_time;
                p.remaining_time = p.burst_time;
                p.current_remaining_time_quantum = time_quantum;
                cout << "Enter priority: ";
                cin >> p.priority;
                cout << '\n';

            }

            os :: COMPARE_ALL(v, time_quantum);
            break;
        case '9' :
            exit(0);
            break;
        }

        continue;
    }

}

void os :: FCFS(vector <process> processes) {
    sort(processes.begin(), processes.end());
    int n = processes.size();

    queue <process> q;

    int total_waiting_time = 0;
    int total_idle_time = 0;

    vector <pair <process, int>> data;
    vector <string> g_chart;
    int cur = 0;

    for (int clock = 0; cur < n or !q.empty(); clock++) {
        while (cur < n and clock == processes[cur].arrival_time) {
            q.push(processes[cur]);
            cur++;
        }

        if (q.empty()) {
            g_chart.push_back("-");
            total_idle_time++;
            continue;
        }

        q.front().first_active = min(clock, q.front().first_active);
        q.front().last_active = clock;
        q.front().remaining_time--;
        g_chart.push_back(q.front().id);

        if (q.front().remaining_time == 0) {
            data.push_back({q.front(), clock});
            q.pop();
        }
    }


    cout << "\n\nFCFS\n";

    double total_turnaround_time = 0, total_response_time = 0;
    for (auto& dt: data) {
        cout << "Process : " << dt.first.id << " Arrival Time: " << dt.first.arrival_time << " Burst Time: " << dt.first.burst_time;
        cout << " Finish Time : " << dt.second;
        cout << " Turnaround Time: " << (dt.second - dt.first.arrival_time + 1) << " Waiting Time: ";

        int wait = (dt.second - dt.first.arrival_time + 1) - dt.first.burst_time;
        total_waiting_time += wait;
        total_turnaround_time += (dt.second - dt.first.arrival_time + 1);

        cout << wait << " ";
        cout << " Response Time: " << dt.first.first_active - dt.first.arrival_time << endl;
        total_response_time += dt.first.first_active - dt.first.arrival_time;
    }

    cout << '\n';

    double avg = total_waiting_time;
    avg /= n;

    cout << "Total Waiting Time: " << total_waiting_time << endl;
    cout << "Average Waiting Time: " << fixed << setprecision(6) << avg << endl;
    cout << "Average Turnaround time: " << fixed << setprecision(6) << (total_turnaround_time / n) << endl;
    cout << "Average Response time: " << fixed << setprecision(6) << (total_response_time / n) << endl;
    cout << "Total Idle time: " << total_idle_time << endl;

    cout << "\nGantt Chart:\n---\n";
    for (int i = 0; i < g_chart.size(); i++) {
        cout << i << " " << g_chart[i] << '\n';
    }

    avg_waiting_time[0] = (total_waiting_time / n);
    avg_turnaround_time[0] = (total_turnaround_time / n);
    avg_response_time[0] = (total_response_time / n);
}

void os :: NON_PREEMPTIVE_SJF(vector <process> processes) {
    int n = processes.size();
    sort(processes.begin(), processes.end());

    queue <process> q;
    priority_queue <process, vector<process>, cmp_non_preemptive_sjf> pq;

    double total_waiting_time = 0;
    int total_idle_time = 0;

    vector <pair <process, int>> data;
    vector <string> g_chart;
    int cur = 0;

    for (int clock = 0; cur < n or !pq.empty() or !q.empty(); clock++) {
        while (cur < n and clock == processes[cur].arrival_time) {
            pq.push(processes[cur]);
            cur++;
        }

        if (q.empty()) {
            if (pq.empty()) {
                g_chart.push_back("-");
                total_idle_time++;
                continue;
            }

            q.push(pq.top());
            pq.pop();
        }

        process& p = q.front();
        p.first_active = min(p.first_active, clock);
        p.last_active = clock;
        p.remaining_time--;
        g_chart.push_back(p.id);

        if (p.remaining_time == 0) {
            data.push_back({p, clock});
            q.pop();
        }
    }


    cout << "\n\nNON-PREEMPTIVE SJF\n";


    double total_turnaround_time = 0, total_response_time = 0;
    for (auto& dt: data) {
        cout << "Process : " <<  dt.first.id << " Arrival Time: " << dt.first.arrival_time << " Burst Time: " << dt.first.burst_time;
        cout << " Finish Time : " << dt.second;

        cout << " Turnaround Time: " << (dt.second - dt.first.arrival_time + 1) << " Waiting Time: ";

        int wait = (dt.second - dt.first.arrival_time + 1) - dt.first.burst_time;
        total_waiting_time += wait;
        total_turnaround_time += (dt.second - dt.first.arrival_time + 1);

        cout << wait << " ";
        cout << " Response Time: " << dt.first.first_active - dt.first.arrival_time << endl;
        total_response_time += dt.first.first_active - dt.first.arrival_time;
    }
    cout << '\n';


    double avg = total_waiting_time;
    avg /= n;

    cout << "Total Waiting Time: " << total_waiting_time << endl;
    cout << "Average Waiting Time: " << fixed << setprecision(6) << avg << endl;
    cout << "Average Turnaround time: " << fixed << setprecision(6) << (total_turnaround_time / n) << endl;
    cout << "Average Response time: " << fixed << setprecision(6) << (total_response_time / n) << endl;
    cout << "Total Idle time: " << total_idle_time << endl;

    cout << "\nGantt Chart:\n---\n";
    for (int i = 0; i < g_chart.size(); i++) {
        cout << i << " " << g_chart[i] << '\n';
    }

    avg_waiting_time[1] = (total_waiting_time / n);
    avg_turnaround_time[1] = (total_turnaround_time / n);
    avg_response_time[1] = (total_response_time / n);
}

void os :: PREEMPTIVE_SJF(vector <process> processes) {
    int n = processes.size();
    sort(processes.begin(), processes.end());
    priority_queue <process, vector<process>, cmp_preemptive_sjf> q;

    double total_waiting_time = 0;
    int total_idle_time;

    vector <pair <process, int>> data;
    vector <string> g_chart;
    int cur = 0;

    for (int clock = 0; cur < n or !q.empty(); clock++) {
        while (cur < n and clock == processes[cur].arrival_time) {
            cout << clock << " " << processes[cur].id << '\n';
            q.push(processes[cur]);
            cur++;
        }

        if (q.empty()) {
            g_chart.push_back("-");
            total_idle_time++;
            continue;
        }

        process p = q.top();
        q.pop();
        p.first_active = min(p.first_active, clock);
        p.last_active = clock;
        p.remaining_time--;
        if (p.remaining_time == 0) data.push_back({p, clock});
        else q.push(p);
        g_chart.push_back(p.id);
    }


    cout << "\n\nPREEMPTIVE SJF\n";
    double total_turnaround_time = 0, total_response_time = 0;
    for (auto& dt: data) {
        cout << "Process : " <<  dt.first.id << " Arrival Time: " << dt.first.arrival_time << " Burst Time: " << dt.first.burst_time;
        cout << " Finish Time : " << dt.second;

        cout << " Turnaround Time: " << (dt.second - dt.first.arrival_time + 1) << " Waiting Time: ";

        int wait = (dt.second - dt.first.arrival_time + 1) - dt.first.burst_time;
        total_waiting_time += wait;
        total_turnaround_time += (dt.second - dt.first.arrival_time + 1);

        cout << wait << " ";
        cout << " Response Time: " << dt.first.first_active - dt.first.arrival_time << endl;
        total_response_time += dt.first.first_active - dt.first.arrival_time;
    }
    cout << '\n';


    double avg = total_waiting_time;
    avg /= n;

    cout << "Total Waiting Time: " << total_waiting_time << endl;
    cout << "Average Waiting Time: " << fixed << setprecision(6) << avg << endl;
    cout << "Average Turnaround time: " << fixed << setprecision(6) << (total_turnaround_time / n) << endl;
    cout << "Average Response time: " << fixed << setprecision(6) << (total_response_time / n) << endl;
    cout << "Total Idle time: " << total_idle_time << endl;

    cout << "\nGantt Chart:\n---\n";
    for (int i = 0; i < g_chart.size(); i++) {
        cout << i << " " << g_chart[i] << '\n';
    }

    avg_waiting_time[2] = (total_waiting_time / n);
    avg_turnaround_time[2] = (total_turnaround_time / n);
    avg_response_time[2] = (total_response_time / n);
}

void os :: NON_PREEMPTIVE_PRIORITY(vector <process> processes) {
    int n = processes.size();
    sort(processes.begin(), processes.end());

    queue <process> q;
    priority_queue <process, vector<process>, cmp_priority> pq;

    double total_waiting_time = 0;
    int total_idle_time = 0;
    vector <pair <process, int>> data;
    vector <string> g_chart;
    int cur = 0;

    for (int clock = 0; cur < n or !pq.empty() or !q.empty(); clock++) {
        while (cur < n and clock == processes[cur].arrival_time) {
            pq.push(processes[cur]);
            cur++;
        }

        if (q.empty()) {
            if (pq.empty()) {
                total_idle_time++;
                g_chart.push_back("-");
                continue;
            }

            q.push(pq.top());
            pq.pop();
        }

        process& p = q.front();
        p.remaining_time--;
        p.first_active = min(p.first_active, clock);
        p.last_active = clock;
        g_chart.push_back(p.id);

        if (p.remaining_time == 0) {
            data.push_back({p, clock});
            q.pop();
        }
    }


    cout << "\n\nNON-PREEMPTIVE PRIORITY\n";
    double total_turnaround_time = 0, total_response_time = 0;
    for (auto& dt: data) {
        cout << "Process : " <<  dt.first.id << " Arrival Time: " << dt.first.arrival_time << " Burst Time: " << dt.first.burst_time;
        cout << " Finish Time : " << dt.second;

        cout << " Turnaround Time: " << (dt.second - dt.first.arrival_time + 1) << " Waiting Time: ";

        int wait = (dt.second - dt.first.arrival_time + 1) - dt.first.burst_time;
        total_waiting_time += wait;
        total_turnaround_time += (dt.second - dt.first.arrival_time + 1);

        cout << wait << " ";
        cout << " Response Time: " << dt.first.first_active - dt.first.arrival_time << endl;
        total_response_time += dt.first.first_active - dt.first.arrival_time;
    }
    cout << '\n';


    double avg = total_waiting_time;
    avg /= n;

    cout << "Total Waiting Time: " << total_waiting_time << endl;
    cout << "Average Waiting Time: " << fixed << setprecision(6) << avg << endl;
    cout << "Average Turnaround time: " << fixed << setprecision(6) << (total_turnaround_time / n) << endl;
    cout << "Average Response time: " << fixed << setprecision(6) << (total_response_time / n) << endl;
    cout << "Total Idle time: " << total_idle_time << endl;

    cout << "\nGantt Chart:\n---\n";
    for (int i = 0; i < g_chart.size(); i++) {
        cout << i << " " << g_chart[i] << '\n';
    }

    avg_waiting_time[3] = (total_waiting_time / n);
    avg_turnaround_time[3] = (total_turnaround_time / n);
    avg_response_time[3] = (total_response_time / n);
}

void os :: PREEMPTIVE_PRIORITY(vector <process> processes) {
    int n = processes.size();
    sort(processes.begin(), processes.end());
    priority_queue <process, vector<process>, cmp_priority> q;

    int total_waiting_time = 0;

    int total_idle_time = 0;
    vector <pair <process, int>> data;
    vector <string> g_chart;
    int cur = 0;

    for (int clock = 0; cur < n or !q.empty(); clock++) {
        while (cur < n and clock == processes[cur].arrival_time) {
            q.push(processes[cur]);
            cur++;
        }

        if (q.empty()) {
            g_chart.push_back("-");
            total_idle_time++;
            continue;
        }

        process p = q.top();
        q.pop();
        p.first_active = min(p.first_active, clock);
        p.last_active = clock;
        p.remaining_time--;

        if (p.remaining_time == 0) data.push_back({p, clock});
        else q.push(p);
        g_chart.push_back(p.id);
    }


    cout << "\n\nPREEMPTIVE PRIORITY\n";
    double total_turnaround_time = 0, total_response_time = 0;
    for (auto& dt: data) {
        cout << "Process : " <<  dt.first.id << " Arrival Time: " << dt.first.arrival_time << " Burst Time: " << dt.first.burst_time;
        cout << " Finish Time : " << dt.second;

        cout << " Turnaround Time: " << (dt.second - dt.first.arrival_time + 1) << " Waiting Time: ";

        int wait = (dt.second - dt.first.arrival_time + 1) - dt.first.burst_time;
        total_waiting_time += wait;
        total_turnaround_time += (dt.second - dt.first.arrival_time + 1);

        cout << wait << " ";
        cout << " Response Time: " << dt.first.first_active - dt.first.arrival_time << endl;
        total_response_time += dt.first.first_active - dt.first.arrival_time;
    }
    cout << '\n';

    double avg = total_waiting_time;
    avg /= n;

    cout << "Total Waiting Time: " << total_waiting_time << endl;
    cout << "Average Waiting Time: " << fixed << setprecision(6) << avg << endl;
    cout << "Average Turnaround time: " << fixed << setprecision(6) << (total_turnaround_time / n) << endl;
    cout << "Average Response time: " << fixed << setprecision(6) << (total_response_time / n) << endl;
    cout << "Total Idle time: " << total_idle_time << endl;

    cout << "\nGantt Chart:\n---\n";
    for (int i = 0; i < g_chart.size(); i++) {
        cout << i << " " << g_chart[i] << '\n';
    }

    avg_waiting_time[4] = (total_waiting_time / n);
    avg_turnaround_time[4] = (total_turnaround_time / n);
    avg_response_time[4] = (total_response_time / n);
}

void os :: ROUND_ROBIN(vector <process> processes, int time_quantum) {
    int n = processes.size();
    sort(processes.begin(), processes.end());

    queue <process> q;

    double total_waiting_time = 0;
    int total_idle_time = 0;

    vector <pair <process, int>> data;
    vector <string> g_chart;
    int cur = 0;

    for (int clock = 0; cur < n or !q.empty(); clock++) {
        while (cur < n and clock == processes[cur].arrival_time) {
            q.push(processes[cur]);
            cur++;
        }

        if (!q.empty()) {
            process& p = q.front();
            p.remaining_time--;
            p.current_remaining_time_quantum--;
            p.first_active = min(p.first_active, clock);
            p.last_active = clock;
            g_chart.push_back(p.id);

            if (p.remaining_time == 0) {
                data.push_back({p, clock});
                q.pop();
            }

            else if (p.current_remaining_time_quantum == 0) {
                q.pop();
                p.current_remaining_time_quantum = time_quantum;
                q.push(p);
            }
        }

        else {
            g_chart.push_back("-");
            total_idle_time++;
            continue;
        }
    }

    cout << "\n\nROUND ROBIN\n";
    double total_turnaround_time = 0, total_response_time = 0;
    for (auto& dt: data) {
        cout << "Process : " <<  dt.first.id << " Arrival Time: " << dt.first.arrival_time << " Burst Time: " << dt.first.burst_time;
        cout << " Finish Time : " << dt.second;

        cout << " Turnaround Time: " << (dt.second - dt.first.arrival_time + 1) << " Waiting Time: ";

        int wait = (dt.second - dt.first.arrival_time + 1) - dt.first.burst_time;
        total_waiting_time += wait;
        total_turnaround_time += (dt.second - dt.first.arrival_time + 1);

        cout << wait << " ";
        cout << " Response Time: " << dt.first.first_active - dt.first.arrival_time << endl;
        total_response_time += dt.first.first_active - dt.first.arrival_time;
    }
    cout << '\n';

    double avg = total_waiting_time;
    avg /= n;

    cout << "Total Waiting Time: " << total_waiting_time << endl;
    cout << "Average Waiting Time: " << fixed << setprecision(6) << avg << endl;
    cout << "Average Turnaround time: " << fixed << setprecision(6) << (total_turnaround_time / n) << endl;
    cout << "Average Response time: " << fixed << setprecision(6) << (total_response_time / n) << endl;
    cout << "Total Idle time: " << total_idle_time << endl;

    cout << "\nGantt Chart:\n---\n";
    for (int i = 0; i < g_chart.size(); i++) {
        cout << i << " " << g_chart[i] << '\n';
    }

    avg_waiting_time[5] = (total_waiting_time / n);
    avg_turnaround_time[5] = (total_turnaround_time / n);
    avg_response_time[5] = (total_response_time / n);
}

void os :: OUR_PROPOSED_ALGORITHM(vector <process> processes, int time_quantum) {
    int n = processes.size();
    sort(processes.begin(), processes.end());

    queue <process> q;
    priority_queue <process, vector<process>, cmp_our_proposed> pq;

    double total_waiting_time = 0;
    int total_idle_time = 0;

    vector <pair <process, int>> data;
    vector <string> g_chart;
    int cur = 0;

    for (int clock = 0; cur < n or !pq.empty() or !q.empty(); clock++) {
        while (cur < n and clock == processes[cur].arrival_time) {
            pq.push(processes[cur]);
            cur++;
        }

        while (!q.empty() and q.front().current_remaining_time_quantum == 0) {
            process p = q.front();
            q.pop();
            p.current_remaining_time_quantum = time_quantum;
            pq.push(p);
        }

        if (q.empty()) {
            if (pq.empty()) {
                g_chart.push_back("-");
                total_idle_time++;
                continue;
            }

            q.push(pq.top());
            pq.pop();
        }

        process& p = q.front();
        p.remaining_time--;
        p.current_remaining_time_quantum--;
        p.first_active = min(p.first_active, clock);
        p.last_active = clock;
        g_chart.push_back(p.id);

        if (p.remaining_time == 0) {
            data.push_back({p, clock});
            q.pop();
        }
    }

    cout << "\n\nOUR PROPOSED ALGORiTHM\n";

    double total_turnaround_time = 0, total_response_time = 0;
    for (auto& dt: data) {
        cout << "Process : " <<  dt.first.id << " Arrival Time: " << dt.first.arrival_time << " Burst Time: " << dt.first.burst_time;
        cout << " Finish Time : " << dt.second;

        cout << " Turnaround Time: " << (dt.second - dt.first.arrival_time + 1) << " Waiting Time: ";

        int wait = (dt.second - dt.first.arrival_time + 1) - dt.first.burst_time;
        total_waiting_time += wait;
        total_turnaround_time += (dt.second - dt.first.arrival_time + 1);

        cout << wait << " ";
        cout << " Response Time: " << dt.first.first_active - dt.first.arrival_time << endl;
        total_response_time += dt.first.first_active - dt.first.arrival_time;
    }
    cout << '\n';


    double avg = total_waiting_time;
    avg /= n;

    cout << "Total Waiting Time: " << total_waiting_time << endl;
    cout << "Average Waiting Time: " << fixed << setprecision(6) << avg << endl;
    cout << "Average Turnaround time: " << fixed << setprecision(6) << (total_turnaround_time / n) << endl;
    cout << "Average Response time: " << fixed << setprecision(6) << (total_response_time / n) << endl;
    cout << "Total Idle time: " << total_idle_time << endl;

    cout << "\nGantt Chart:\n---\n";
    for (int i = 0; i < g_chart.size(); i++) {
        cout << i << " " << g_chart[i] << '\n';
    }

    avg_waiting_time[6] = (total_waiting_time / n);
    avg_turnaround_time[6] = (total_turnaround_time / n);
    avg_response_time[6] = (total_response_time / n);
}

void os :: COMPARE_ALL(vector <process> v, int time_quantum) {
    os::FCFS(v);
    os::NON_PREEMPTIVE_SJF(v);
    os::PREEMPTIVE_SJF(v);
    os::NON_PREEMPTIVE_PRIORITY(v);
    os::PREEMPTIVE_PRIORITY(v);
    os::ROUND_ROBIN(v, time_quantum);
    os::OUR_PROPOSED_ALGORITHM(v, time_quantum);

    for (int i = 0; i < 7; i++) {
        cout << "Algorithm " << i + 1 << " ";
        cout << "Average Waiting Time: " << fixed << setprecision(6) << avg_waiting_time[i] << " ";
        cout << "Average Turnaround Time: " << fixed << setprecision(6) << avg_turnaround_time[i] << " ";
        cout << "Average Response Time: " << fixed << setprecision(6) << avg_response_time[i] << '\n';
    }
}



