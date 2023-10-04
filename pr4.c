#include<stdio.h>
#include<stdlib.h>

void pline(int x){
    for(int i = 0; i < x; i++)
        printf("-");
    printf("\n");
}

struct PCB {
    int PID;
    int Arrival_Time;
    int Burst_Time;
    int Completion_Time;
    int Tutnaround_Time;
    int Waiting_Time;
};

void swap(struct PCB p[],struct PCB temp,int i,int j){
    temp.PID = p[i].PID;
    temp.Arrival_Time = p[i].Arrival_Time;
    temp.Burst_Time = p[i].Burst_Time;
    temp.Completion_Time = p[i].Completion_Time;
    temp.Tutnaround_Time = p[i].Tutnaround_Time;
    temp.Waiting_Time = p[i].Waiting_Time;


    p[i].PID = p[j].PID;
    p[i].Arrival_Time = p[j].Arrival_Time;
    p[i].Burst_Time = p[j].Burst_Time;
    p[i].Completion_Time = p[j].Completion_Time;
    p[i].Tutnaround_Time = p[j].Tutnaround_Time;
    p[i].Waiting_Time = p[j].Waiting_Time;

    p[j].PID = temp.PID;
    p[j].Arrival_Time = temp.Arrival_Time;
    p[j].Burst_Time = temp.Burst_Time;
    p[j].Completion_Time = temp.Completion_Time;
    p[j].Tutnaround_Time = temp.Tutnaround_Time;
    p[j].Waiting_Time = temp.Waiting_Time;
}
void display(struct PCB p[],int num){
    system("clear");
    pline(70);
    printf("PID\tArrival\t\tBurst\t\tCompletion\tTAT\tWT\n");
    pline(70);
    for(int i = 0; i < num; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t%d",p[i].PID,p[i].Arrival_Time,p[i].Burst_Time,p[i].Completion_Time,
        p[i].Tutnaround_Time,p[i].Waiting_Time);
        printf("\n");
    }    
    pline(70);
}


int main(){
    int num,sum;
    struct PCB p[10],temp;
    printf("Enter The Number Of Process You Have : ");
    scanf("%d",&num);

    printf("Enter the arrival time for rach process !\n\n");
    pline(30);
    for(int i = 0; i < num; i++){
        p[i].PID = i+1;
        printf("P%d",i+1);
        printf("\nArrival : ");
        scanf("%d",&p[i].Arrival_Time);
        printf("Burst : ");
        scanf("%d",&p[i].Burst_Time);
        pline(30);       
    }

    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num-i-1; j++){
            if(p[j].Arrival_Time > p[j+1].Arrival_Time)
                swap(p,temp,j,(j+1));
    }

    }
    sum = 0;
    for(int i = 0; i < num; i++){
        sum += p[i].Burst_Time;
        p[i].Completion_Time = sum;
        p[i].Tutnaround_Time = p[i].Completion_Time;
        p[i].Waiting_Time = p[i].Tutnaround_Time - p[i].Burst_Time;
    }

    sum = 0;
    int Wsum = 0;
    for(int i = 0; i < num; i++){
        sum+=p[i].Tutnaround_Time;
        Wsum+=p[i].Waiting_Time;
    }

    for(int i = 0; i < num - 1; i++){
        for(int j = 0; j < num-i-1; j++){
            if(p[j].PID > p[j+1].PID)
                swap(p,temp,j,(j+1));
    }

    display(p,num);
    
    printf("\n\nThe Average TAT : %0.2f",(float)sum/(float)num);
    printf("\n\nThe Average WT : %0.2f\n",(float)Wsum/(float)num);
}
}
