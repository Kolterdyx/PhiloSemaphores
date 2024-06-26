//
// Created by kolterdyx on 6/26/24.
//


#include "philo.h"

#include <string.h>

void live(t_philo *philo) {
    while (!is_dead(philo)) {
        life_guard(&eat, philo, NULL);
        life_guard(&psleep, philo, NULL);
        life_guard(&think, philo, NULL);
    }
}

void eat(t_philo *philo, void *data) {
    sem_wait(philo->semaphore);
    life_guard(&talk, philo, "picked up a fork");
    sem_wait(philo->semaphore);
    life_guard(&talk, philo, "picked up another fork");
    life_guard(&talk, philo, "is eating");
    sem_post(philo->semaphore);
    sem_post(philo->semaphore);
}

void psleep(t_philo *philo, void *data) {
    life_guard(&talk, philo, "is sleeping");
    csleep(philo->game, philo->game->sleep_time);

}

void think(t_philo *philo, void *data) {
    life_guard(&talk, philo, "is thinking");
    csleep(philo->game, philo->game->think_time);
}

int is_dead(const t_philo *philo) {
    return 0;//get_time() - philo->ltt_eat > philo->game->die_time;
}

void life_guard(philo_func const func, t_philo *philo, void *data) {
    if (!is_dead(philo)) {
        func(philo, data);
    }
}

void talk(const t_philo *philo, char *msg) {
    printf("[%u] %i %s\n", get_time(), philo->id, msg);
}