#include "simulation.h"

void initialisisation(){
    Server = IDLE;
    initial_queue(&QueueList);
    Tnow = 0;
    init_event_list(&EventList);
    arrival_time = 6;
    service_time = 5;
    create_event(&EventList, ARRIVAL, Tnow);
    mean_response_time = 0;
    mean_waiting_time = 0;
    client_served = 0;
}

void PArrival(){
    enqueue(&QueueList, id_client++, Tnow, 0, service_time);
    if (Server == IDLE) {
        create_event(&EventList, START_SERVICE, Tnow);
    }
    create_event(&EventList, ARRIVAL, Tnow + arrival_time);
}

void PStartService() {
    Server = BUSY;

    dequeue(&QueueList, &CurrentClient);

    CurrentClient.t_start_service = Tnow;

    create_event(&EventList, DEPARTURE,
                 Tnow + CurrentClient.t_service);
}


void PDeparture(){
    Server = IDLE;
    mean_response_time += (Tnow - CurrentClient.t_arrival);
    mean_waiting_time += (CurrentClient.t_start_service - CurrentClient.t_arrival);
    client_served++;
    if (!is_empty(&QueueList)) {
        create_event(&EventList, START_SERVICE, Tnow);
    }
}