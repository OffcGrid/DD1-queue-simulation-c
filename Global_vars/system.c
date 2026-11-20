#include "system.h"


double Tnow = 0;
double arrival_time = 0.0;
double service_time = 0.0;
int id_client=0;
ServerStatus Server = IDLE;
queue QueueList;
client CurrentClient;


void initial_queue(queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

bool is_empty(queue *q) {
    return (q->head == NULL);
}

void enqueue(queue *q, int id, double t_arrival, double t_start_service, double t_service) {
    client *new_client = (client *)malloc(sizeof(client));
    if (new_client == NULL) {
        return;                     
    }
    new_client->id = id;
    new_client->t_arrival = t_arrival;
    new_client->t_start_service = t_start_service;   
    new_client->t_service = t_service;
    new_client->suiv = NULL;

    if (is_empty(q)) {
        q->head = new_client;
        q->tail = new_client;
    } else {
        q->tail->suiv = new_client;
        q->tail = new_client;
    }
}


bool dequeue(queue *q, client *c) {
    if (is_empty(q))
        return false;

    client *temp = q->head;
    *c = *temp;

    q->head = temp->suiv;

    if (q->head == NULL)
        q->tail = NULL;

    free(temp);
    return true;
}
