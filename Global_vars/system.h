#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    IDLE,
    BUSY
} ServerStatus;

typedef struct client
{
    int id;
    int t_arrival;
    int t_start_service;
    int t_service;
    struct client *suiv;
} client;

typedef struct queue
{
    client *head;
    client *tail;
} queue;


extern double Tnow;
extern ServerStatus Server;
extern queue QueueList;
extern int arrival_time;
extern int service_time;
extern int id_client;
extern client CurrentClient;

void initial_queue(queue *q);
bool is_empty(queue *q);
void enqueue(queue *q, int id, int t_arrival, int t_start_service ,int t_service);
bool dequeue(queue *q, client *c);


#endif