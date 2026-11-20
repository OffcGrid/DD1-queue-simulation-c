#include <math.h>
#include <time.h>
#include "simulation.h"
 
/* Inverse CDF method: X = -ln(U) / lambda, with U strictly in (0, 1). */
double generate_exponential(double lambda) {
    double u;
    do {
        u = (double)rand() / ((double)RAND_MAX + 1.0);
    } while (u <= 0.0 || u >= 1.0);

    return -log(u) / lambda;
}

void Initialization(void) {
    srand((unsigned int)time(NULL));

    Server = IDLE;
    initial_queue(&QueueList);
    init_event_list(&EventList);

    Tnow = 0.0;
    id_client = 0;
    mean_interarrival_time = MEAN_INTERARRIVAL_TIME;
    arrival_rate = 1.0 / mean_interarrival_time;
    service_time = DETERMINISTIC_SERVICE;

    total_response_time = 0.0;
    total_waiting_time = 0.0;
    total_interarrival_time = 0.0;
    total_interarrivals = 0;
    client_served = 0;

    Create_Event(&EventList, ARRIVAL, Tnow);
}

void PArrival(void) {
    double interarrival = generate_exponential(arrival_rate);
    total_interarrival_time += interarrival;
    total_interarrivals++;

    enqueue(&QueueList, id_client++, Tnow, 0.0, service_time);

    if (Server == IDLE) {
        Server = BUSY;                          /* claim the server NOW */
        Create_Event(&EventList, START_SERVICE, Tnow);
    }

    Create_Event(&EventList, ARRIVAL, Tnow + interarrival);
}

void PStart_Service(void) {
    if (!dequeue(&QueueList, &CurrentClient)) {
        return;                                
    }

    CurrentClient.t_start_service = Tnow;
    Create_Event(&EventList, DEPARTURE, Tnow + CurrentClient.t_service);
}

void PDeparture(void) {
    total_response_time += (Tnow - CurrentClient.t_arrival);
    total_waiting_time  += (CurrentClient.t_start_service - CurrentClient.t_arrival);
    client_served++;

    if (!is_empty(&QueueList)) {
        Create_Event(&EventList, START_SERVICE, Tnow);  
    } else {
        Server = IDLE;                                 
    }
}
