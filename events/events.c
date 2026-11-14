#include "events.h"

Event_List EventList;

void init_event_list(Event_List *list) {
    list->head = NULL;
    list->tail = NULL;
}

bool event_list_empty(Event_List *list) {
    return list->head == NULL;
}

void create_event(Event_List *list, EventType type, double time) {
    Event *new_event = (Event *)malloc(sizeof(Event));
    if (new_event == NULL) {
        return;
    }
    new_event->type = type;
    new_event->time = time;
    new_event->next = NULL;

    if (event_list_empty(list)) {
        list->head = new_event;
        list->tail = new_event;
    } else {
        list->tail->next = new_event;
        list->tail = new_event;
    }
}

/* Removes and returns the event with the smallest time.
   The list must not be empty. */
Event get_event(Event_List *list) {
    Event *min = list->head, *min_prev = NULL;
    Event *prev = NULL, *e = list->head;

    while (e != NULL) {
        if (e->time < min->time) {
            min = e;
            min_prev = prev;
        }
        prev = e;
        e = e->next;
    }

    Event result = *min;
    result.next = NULL;

    if (min_prev == NULL)
        list->head = min->next;
    else
        min_prev->next = min->next;

    if (min == list->tail)
        list->tail = min_prev;

    free(min);
    return result;
}