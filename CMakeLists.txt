cmake_minimum_required(VERSION 3.28)
project(philo C)

set(CMAKE_C_STANDARD 99)

add_executable(philo main.c
        philo.h
        philo.c
        init.c
        utils.c
        cleanup.c
)
