//
// Created by kolterdyx on 6/26/24.
//


#include "philo.h"

void free_game(t_game *game) {
    sem_close(game->semaphore);
    pthread_join(game->log_thread, NULL);
    for (int i = 0; i < game->n_philos; i++) {
        kill(game->philos[i].pid, SIGKILL);
    }
    free(game->philos);
    free(game);
}
