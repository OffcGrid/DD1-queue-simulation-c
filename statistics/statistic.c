#include "statistic.h"

double mean_response_time = 0;
double mean_waiting_time = 0;
int client_served = 0;

void stats(){
    printf("Mean Response Time: %.2f\n",
           mean_response_time / client_served);

    printf("Mean Waiting Time: %.2f\n",
           mean_waiting_time / client_served);

    printf("THROUGHPUT:  %.6f\n",
           client_served / (double)Tnow);
}
