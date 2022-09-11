
#include <stdio.h>
#include <string.h>

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
        if(strcmp(line_buf, "q") != 0) {
            return 0;
        }
    };
    return 0;
}
