#ifndef FLAGS_H
#define FLAGS_H

#define FLAG_l  1 << 0
#define FLAG_R  1 << 1
#define FLAG_A  1 << 2
#define FLAG_a  1 << 3
#define FLAG_G  1 << 4
#define FLAG_h  1 << 5
#define FLAG_AT 1 << 6
#define FLAG_e  1 << 7
#define FLAG_T  1 << 8
#define FLAG_1  1 << 9
#define FLAG_C  1 << 10
#define FLAG_r  1 << 11
#define FLAG_t  1 << 12
#define FLAG_u  1 << 13
#define FLAG_c  1 << 14
#define FLAG_S  1 << 15

int mx_check_flags(int argc, char *argv[], unsigned short *flags);

#endif

