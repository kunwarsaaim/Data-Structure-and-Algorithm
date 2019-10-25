#include <iostream>
using namespace std;

struct Process {
    string P;
    int arrival_time;
    int Burst_time;
};

struct Gant_chart {
    string P;
    int time;
};

bool compare( Process P1, Process P2){return P1.arrival_time<P2.arrival_time;}

int main(int argc, const char * argv[]) {

    Process pro[10];
    Gant_chart chart[10];
    int n;
    cout<<"Enter number of process: ";
    cin>>n;
    cout<<endl;
    for (int i=0; i<n; i++) {
        cout<<"Enter Process Name | Arrival Time | Burst Time: "<<endl;
        cin>>pro[i].P;
        cin>>pro[i].arrival_time;
        cin>>pro[i].Burst_time;
    }
    cout<<endl;
    
    cout<<"Process\t Arrival Time\t Burst Time"<<endl;
    for (int i=0; i<n; i++) {
        cout<<pro[i].P<<"\t\t\t"<<pro[i].arrival_time<<"\t\t\t\t"<<pro[i].Burst_time<<endl;
    }
    cout<<endl;
    
    sort(pro, pro+n, compare);

    int process_count=0,chart_count=0;
    while(process_count<n){
        if ((pro[0].arrival_time!=0 && chart_count==0)  || (process_count>0 && pro[process_count].arrival_time>chart[chart_count-1].time)) {
            chart[chart_count].P = "I";
            chart[chart_count].time=pro[process_count].arrival_time;
            chart_count++;
        }
        else{
            if(chart_count==0){
                chart[chart_count].P = pro[process_count].P;
                chart[chart_count].time = pro[process_count].Burst_time;
                process_count++;
                chart_count++;
            }
            else{
                chart[chart_count].P = pro[process_count].P;
                chart[chart_count].time = chart[chart_count-1].time + pro[process_count].Burst_time;
                process_count++;
                chart_count++;
            }
        }
    }
    
    cout<<"Gant Chart: "<<endl;
    for(int i=0;i<chart_count;i++){
        cout<<chart[i].P<<"\t";
    }
    cout<<endl;
    for(int i=0;i<chart_count;i++){
        cout<<chart[i].time<<"\t";
    }
    cout<<"\n"<<endl;
    
    float average_waiting=0,average_turnaround=0;
    process_count=0;
    for (int i=0; i<chart_count; i++) {
        if(chart[i].P != "I"){
            int turn_around = chart[i].time-pro[process_count].arrival_time;
            int waiting_time = turn_around-pro[process_count].Burst_time;
            cout<<"Process "<<pro[process_count].P<<" Turn Around Time: "<<turn_around<<" Waiting Time: "<<waiting_time<<endl;
            average_waiting+=waiting_time;
            average_turnaround+=turn_around;
            process_count++;
        }
    }
    cout<<endl;
    
    average_turnaround= (float)average_turnaround/n;
    average_waiting = (float)average_waiting/n;
    cout<<"Average turnaround Time: "<<average_turnaround<<"  Average Waiting Time: "<<average_waiting<<endl;
    
    return 0;
}
