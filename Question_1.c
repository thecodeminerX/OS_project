/*    Name:    ASHISH KUMAR
      ROLL_NO: 68
      section: K17SM
      Question_no. : 3
  */





#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int burst_t[20],arrival_t[10],n,i,j,temp,start_t[10],finish_t[10],waiting_t[10],turnaround_t[10];    //burst_t   - burst time ,   waiting_t    - waiting time 
    int total_waiting_t=0,total_arrival_t=0;                                                                                 //arrival_t - arrival time  ,turnaround_t - turn around time
    float average_waiting_t,average_turnaround_t;                                                                                       //start_t   - starting time ,finish_t     - finish time
    char pn[10][10],t[10];
        	printf("\n-----------------------------------------SHORTEST JOB FIRST (NO PREEMPTION)--------------------------------------------");

    printf("\n\nEnter the number of process : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
    	re:
        printf("   \nEnter Process_Name , Arrival_Time  & Burst_Time  :  ");
        scanf("%s%d%d",pn[i],&arrival_t[i],&burst_t[i]);
        if(arrival_t[i]==0)                                    //error if arrival time is zero
        {
        	printf("\n WARNING:  Arrival time cant be zero\nPlease Re-enter : \n");
        	goto re;
		}
    }
    
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
        	if(arrival_t[i]<=arrival_t[j])
            if(burst_t[i]<burst_t[j])
            {
                temp=arrival_t[i];
                arrival_t[i]=arrival_t[j];
                arrival_t[j]=temp;
                temp=burst_t[i];
                burst_t[i]=burst_t[j];
                burst_t[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0)
            start_t[i]=arrival_t[i];
        else
            start_t[i]=finish_t[i-1]+2;      //2 units of time after completion of each process
        waiting_t[i]=start_t[i]-arrival_t[i];
        finish_t[i]=start_t[i]+burst_t[i];
        turnaround_t[i]=finish_t[i]-arrival_t[i];
        total_waiting_t+=waiting_t[i];
        total_arrival_t+=turnaround_t[i];
	}
    average_waiting_t=(float)total_waiting_t/n;
    average_turnaround_t=(float)total_arrival_t/n;
    printf("\nProcess_Name\tArrival_Time\tExecution_Time\tWaiting_Time\tTurnAround_Time");
    for(i=0; i<n; i++)
        printf("\n\n%s\t\t%5d\t\t%5d\t\t%5d\t\t%5d",pn[i],arrival_t[i],burst_t[i],waiting_t[i],turnaround_t[i]);
    printf("\n\nAverage waiting time is  :   %f",average_waiting_t);
    printf("\nAverage turnaroundtime is:   %f",average_turnaround_t);
    getch();
}
