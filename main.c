#include "simulation/simulation.h"
#include "events/events.h"
#include "statistics/statistic.h"   
#include "Global_vars/system.h"

int main() {
    initialisisation();
    while (client_served < 100) {
        Event e = get_event(&EventList);
        Tnow = e.time;
        switch (e.type) {
            case ARRIVAL:
                PArrival();
                break;
            case START_SERVICE:
                PStartService();
                break;
            case DEPARTURE:
                PDeparture();
                break;
        }
    }
    stats();

    return 0;
}