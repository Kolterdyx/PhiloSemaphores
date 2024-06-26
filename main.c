#include "philo.h"

int main(const int argc, char **argv) {
    if (argc != 5 && argc != 6) {
        printf("Usage: ./philo <n philos> <die time> <think time> <sleep time> [times to eat]\n");
        return 0;
    }
    t_game *game = create_game(
        atoi(argv[1]),
        atoi(argv[2]),
        atoi(argv[3]),
        atoi(argv[4]),
        argc == 6 ? atoi(argv[5]) : 0
    );

    start_game(game);
    free_game(game);
}

void game_loop(const t_game *game) {
    for (int i = 0; i < game->n_philos; i++) {
        waitpid(game->philos[i].pid, NULL, 0);
    }
}

void start_game(t_game *game) {
    for (int i = 0; i < game->n_philos; i++) {
        const int pid = fork();
        if (pid == 0) {
            game->philos[i].semaphore = sem_open(SEM_NAME, 0);
            live(&game->philos[i]);
            exit(0);
        }
        game->philos[i].pid = pid;
    }
    game_loop(game);
}