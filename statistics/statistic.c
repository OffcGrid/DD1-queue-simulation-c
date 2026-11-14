#include "statistic.h"

int mean_response_time=0;
int mean_waiting_time=0;
int client_served=0;

void stats(){
    printf("Mean Response Time: %d\n", mean_response_time);
    printf("Mean Waiting Time: %d\n", mean_waiting_time);
    printf("THROUGHPUT: %e\n", client_served/(double)Tnow);
}