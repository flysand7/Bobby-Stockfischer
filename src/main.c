
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "piece.c"
#include "an.c"

int main() {
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
        MoveInfo move;
        size_t ok = parse_an(&move, line);
        if(!ok) {
            printf("BAD MOVE\n");
        }
    };
    return 0;
}
