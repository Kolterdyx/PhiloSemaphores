//
// Created by kolterdyx on 6/26/24.
//

#include "philo.h"

unsigned int get_time() {
    static struct timeval start;
    struct timeval end;

    gettimeofday(&end, NULL);
    if (start.tv_sec == 0 && start.tv_usec == 0)
        start = end;

    return (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
}

void csleep(const t_game *game, const unsigned int mtime) {
    const unsigned int target_time = get_time() + mtime;
    while (get_time() < target_time) {
        usleep(50);
    }
}
