//
// Created by kolterdyx on 6/26/24.
//

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>

#define SEM_NAME "philo"

typedef struct s_game t_game;

typedef struct s_philo {
    int id;
    int pid;
    int ltt_eat;
    sem_t *semaphore;
    t_game *game;
} t_philo;

typedef struct s_game {
    int n_philos;
    int n_to_eat;
    int die_time;
    int sleep_time;
    int think_time;

    t_philo *philos;
    sem_t *semaphore;
    pthread_t log_thread;
} t_game;


typedef void (*philo_func)(t_philo*, void *data);

void live(t_philo *philo);
void eat(t_philo *philo, void *data);
void think(t_philo *philo, void *data);
void psleep(t_philo *philo, void *data);
t_game *create_game(int n_philos, int die_time, int sleep_time, int think_time, int tt_eat);
t_philo *init_philo(t_philo *philo, int id, t_game *game);
void csleep(const t_game *game, unsigned int mtime);
unsigned int get_time();
void free_game(t_game *game);
void start_game(t_game *game);
int is_dead(const t_philo *philo);
void life_guard(philo_func func, t_philo *philo, void *data);
void talk(const t_philo *philo, char *msg);

#endif //PHILO_H
