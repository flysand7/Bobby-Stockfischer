
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <intrin.h>

#include "piece.c"
#include "board.c"
#include "board_print.c"
#include "an.c"

int main() {
    Board b;
    board_default(&b);
    char line_buf[1024];
    size_t line_buf_size = sizeof(line_buf);
    for(;;) {
        printf("> ");
        char *line = fgets(line_buf, line_buf_size, stdin);
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
        else if(line_buf[0] == 'm' && line_buf[1] == ' ') {
            char *cell = line_buf+2;
            int file = cell[0] - 'a';
            int rank = cell[1] - '1';
            print_moves(&b, file, rank);
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
