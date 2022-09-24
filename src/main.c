
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <ctype.h>
#include <intrin.h>

#include "piece.c"
#include "board.c"
#include "board_fen.c"
#include "board_print.c"
#include "an.c"

static bool str_starts_with(char *str, char *pref, char **rest) {
    while(*str != 0 && *pref != 0) {
        if(*str != *pref) {
            return false;
        }
        ++str;
        ++pref;
    }
    if(*str == 0 && *pref != 0) {
        return false;
    }
    *rest = str+1;
    return true;
}

int main() {
    bb_rays_init();
    Board b;
    board_default(&b);
    char line_buf[1024];
    size_t line_buf_size = sizeof(line_buf);
    for(;;) {
        printf("> ");
        char *line = fgets(line_buf, line_buf_size, stdin);
        char *arg;
        size_t line_len = strlen(line);
        if(line[line_len-1] == '\n') {
            line[line_len-1] = 0;
        }
        if(strcmp(line_buf, "q") == 0) {
            return 0;
        }
        else if(strcmp(line_buf, "b") == 0) {
            print_board(&b);
            continue;
        }
        else if(str_starts_with(line_buf, "m", &arg)) {
            int file = arg[0] - 'a';
            int rank = arg[1] - '1';
            print_moves(&b, file, rank);
            continue;
        }
        else if(str_starts_with(line_buf, "fen", &arg)) {
            char *fen = arg;
            board_load_fen(&b, fen);
            continue;
        }
        MoveInfo move;
        size_t ok = parse_an(&move, line);
        if(!ok) {
            printf("BAD MOVE\n");
        }
    };
    return 0;
}
