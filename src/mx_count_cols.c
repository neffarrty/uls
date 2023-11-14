#include "../inc/uls.h"

int mx_count_cols(int max) {
    int cols = 0;
    struct winsize ws;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
    
    if(ws.ws_col  % (max + 2) == 0){
        cols = ws.ws_col / (max + 8);
    }
    else {
        cols = ws.ws_col / (max + 2);
    }

    return cols;
}

