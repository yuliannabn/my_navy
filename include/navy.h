/*
** EPITECH PROJECT, 2023
** navy
** File description:
** navy
*/

#ifndef NAVY_H_
    #define NAVY_H_

    #include "files.h"
    #include <signal.h>
    #include <time.h>

    #define small           '2'
    #define medium          '3'
    #define big             '4'
    #define huge            '5'
    #define board_line      "........"
    #define WAIT            "\nwaiting for enemy's attack...\n"
    #define HIT_MSG         ": hit\n"
    #define MISS_MSG        ": missed\n"
    #define FAIL_MSG        "\nEnemy won\n\n"
    #define WIN_MSG         "\nI won\n\n"
    #define all_sizes       4
    #define from_ver        3
    #define from_hor        2
    #define to_ver          6
    #define to_hor          5
    #define me              1
    #define you             2
    #define on_hold         3
    #define BOARD_SIZE      8
    #define TOTAL_SHIPS     14
    #define I_WON           0
    #define ENEMY_WON       1
    #define START_OF_ROUND  0
    #define END_OF_ROUND    2
    #define NO_HIT          5
    #define HAS_HIT         10
    #define I_WON           0
    #define ENEM_WON        1

    extern long int nbs[4];

    typedef struct sizes_s {
        char    size;
        bool    on;
    } sizes_t;

    typedef struct map_s {
        char    **board_lines;
        int     ships;
        int     ret;
        pid_t   PID;
    } map_t;

    int     help_message         (void);
    int     error_help_message   (void);
    bool    has_hit              (char index);
    void attack_feedback         (map_t *player_map, int enemy_pid);
    void get_coords              (int signal);
    void end_coord_transmission  (int signal);
    void receive_attack          (map_t *player_map, int enemy_pid, int *turn);
    void    get_attack           (int *turn, int pid);
    bool    attack_is_valid      (char *buf);
    char    *cut_str             (char *str);
    bool    out_of_bounds        (int nb);
    void    send_pid             (pid_t receiver, pid_t sender);
    int     navygame             (char *file, int mode, int pid);
    void     player_map_display  (char **player_map);
    void    enemy_map_display    (char **enemy_map);
    void    free_chararray       (char **array);
    void    free_array           (sizes_t **array);
    char    **segment_parts      (char *lines);
    void    receive_attack       (map_t *player_map, int enemy_pid, int *turn);
    void    pid_wait             (int PID);
    void    get_pid              (int signal);
    void    end_pid              (int signal);
    map_t   *init_map            (void);
    sizes_t **init_sizes         (void);
    void    free_map             (map_t *map);
    bool    sizes_valid          (char **data);
    void    init_attack          (int *turn, int pid, map_t *enemy_map);
    int     player1              (map_t *player_map, map_t *enemy_map);
    int     player2              (map_t *player_map, map_t *enemy_map, int pid);
    bool    navy_initialize      (char *file, map_t *player_map);
    void    send_attack          (int pid, int pos);
    void    send_number          (pid_t receiver, int times);
    void    send_connection      (pid_t receiver, pid_t sender);
    bool    positions_valid_fill (char **data, map_t *player_map);

#endif
