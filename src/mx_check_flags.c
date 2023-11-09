#include "uls.h"

unsigned short LS_FLAGS = 0x00; // 0000 0000 0000 0000

unsigned short FLAG_l   = 0x01; // 0000 0000 0000 0001

void mx_check_flags(int argc, char *argv[], int flags) {
    for(int i = 1; i < argc; i++) {
        if(argv[i][0] == '-') {
            for(int j = 1; j < mx_strlen(argv[i]); j++) {
                switch(argv[i][j]) {
                    case 'l':
                        LS_FLAGS |= FLAG_l;
                        mx_printstr("option: ");
                        mx_printchar('l');
                        mx_printchar('\n');
                        break;
                    case 'R':
                        mx_printstr("option: ");
                        mx_printchar('R');
                        mx_printchar('\n');
                        break;
                    case 'A':
                        mx_printstr("option: ");
                        mx_printchar('A');
                        mx_printchar('\n');
                        break;
                    case 'a':
                        mx_printstr("option: ");
                        mx_printchar('a');
                        mx_printchar('\n');
                        break;
                    case 'G':
                        mx_printstr("option: ");
                        mx_printchar('G');
                        mx_printchar('\n');
                        break;
                    case 'h':
                        mx_printstr("option: ");
                        mx_printchar('h');
                        mx_printchar('\n');
                        break;
                    case '@':
                        mx_printstr("option: ");
                        mx_printchar('@');
                        mx_printchar('\n');
                        break;
                    case 'e':
                        mx_printstr("option: ");
                        mx_printchar('e');
                        mx_printchar('\n');
                        break;
                    case 'T':
                        mx_printstr("option: ");
                        mx_printchar('T');
                        mx_printchar('\n');
                        break;
                    case '1':
                        mx_printstr("option: ");
                        mx_printchar('1');
                        mx_printchar('\n');
                        break;
                    case 'C':
                        mx_printstr("option: ");
                        mx_printchar('C');
                        mx_printchar('\n');
                        break;
                    case 'r':
                        mx_printstr("option: ");
                        mx_printchar('r');
                        mx_printchar('\n');
                        break;
                    case 't':
                        mx_printstr("option: ");
                        mx_printchar('t');
                        mx_printchar('\n');
                        break;
                    case 'u':
                        mx_printstr("option: ");
                        mx_printchar('u');
                        mx_printchar('\n');
                        break;
                    case 'c':
                        mx_printstr("option: ");
                        mx_printchar('c');
                        mx_printchar('\n');
                        break;
                    case 'S':
                        mx_printstr("option: ");
                        mx_printchar('S');
                        mx_printchar('\n');
                        break;
                    default:
                        mx_printerr("uls: invalid option: -");
                        write(STDERR_FILENO, &argv[i][j], 1);
                        mx_printchar('\n');
                }
            }
        }
    }

    mx_printstr("option l is defined: ");
    if(LS_FLAGS & FLAG_l) mx_printstr("true\n");
    else mx_printstr("false\n");
}

