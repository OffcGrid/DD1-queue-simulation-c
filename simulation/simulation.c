#include "simulation.h"

void initialisisation() {
    Server = IDLE;
    initial_queue(&QueueList);
    Tnow = 0;
    init_event_list(&EventList);

    do {
        printf("Enter arrival time (> 0): ");
        scanf("%lf", &arrival_time);

        printf("Enter service time (> 0): ");
        scanf("%lf", &service_time);

        if (arrival_time <= 0.0 || service_time <= 0.0) {
            printf("Error: Both values must be greater than 0.\n");
        }
    } while (arrival_time <= 0.0 || service_time <= 0.0);

    create_event(&EventList, ARRIVAL, Tnow);
    mean_response_time = 0;
    mean_waiting_time = 0;
    client_served = 0;
}

void PArrival(){
    enqueue(&QueueList, id_client++, Tnow, 0, service_time);
    if (Server == IDLE) {
        Server = BUSY;                     
        create_event(&EventList, START_SERVICE, Tnow);
    }
    create_event(&EventList, ARRIVAL, Tnow + arrival_time);
}

void PStartService() {
    if (!dequeue(&QueueList, &CurrentClient))  
        return;

    CurrentClient.t_start_service = Tnow;
    create_event(&EventList, DEPARTURE, Tnow + CurrentClient.t_service);
}

void PDeparture(){
    mean_response_time += (Tnow - CurrentClient.t_arrival);
    mean_waiting_time  += (CurrentClient.t_start_service - CurrentClient.t_arrival);
    client_served++;

    if (!is_empty(&QueueList)) {
        create_event(&EventList, START_SERVICE, Tnow); 
    } else {
        Server = IDLE;                                  
    }
}
