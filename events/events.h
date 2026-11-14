#ifndef EVENTS_H
#define EVENTS_H

#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    ARRIVAL,
    START_SERVICE,
    DEPARTURE
} EventType;

typedef struct Event {
    EventType type;
    double time;
    struct Event *next;
} Event;

typedef struct EVENT_LIST {
    Event *head;
    Event *tail;
} Event_List;

extern Event_List EventList;   /* defined in events.c */

void init_event_list(Event_List *list);
bool event_list_empty(Event_List *list);
void create_event(Event_List *list, EventType type, double time);
Event get_event(Event_List *list);

#endif