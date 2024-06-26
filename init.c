//
// Created by kolterdyx on 6/26/24.
//



#include "philo.h"

t_game *create_game(const int n_philos, const int die_time, const int sleep_time, const int think_time, const int tt_eat) {
    t_game *game = calloc(1, sizeof(t_game));
    game->die_time = die_time;
    game->sleep_time = sleep_time;
    game->think_time = think_time;
    game->n_to_eat = tt_eat;
    game->semaphore = sem_open(SEM_NAME, O_CREAT, 0644, n_philos);
    game->n_philos = n_philos;
    game->philos = calloc(n_philos, sizeof(t_philo));
    for (int i = 0; i < n_philos; i++) {
        init_philo(&game->philos[i], i+1, game);
    }
    return game;
}

t_philo *init_philo(t_philo *philo, const int id, t_game *game) {
    philo->id = id;
    philo->ltt_eat = get_time();
    philo->game = game;
    philo->semaphore = NULL;
    return philo;
}