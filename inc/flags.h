#ifndef FLAGS_H
#define FLAGS_H

#define FLAG_l  0x01  // completed, but need to fix output with old data
#define FLAG_R  0x02  // completed
#define FLAG_A  0x04  // completed
#define FLAG_a  0x08  // completed
#define FLAG_G  0x10  // completed
#define FLAG_h  0x20  // so hard, syka blyaaaaaatttt bim bim bam bam 
#define FLAG_AT 0x40  // completed, tabulation not completed ska blyat bim bim bam bam
#define FLAG_e  0x80
#define FLAG_T  0x100  // completed
#define FLAG_1  0x200  // completed
#define FLAG_C  0x400 // completed
#define FLAG_r  0x800
#define FLAG_t  0x1000
#define FLAG_u  0x2000
#define FLAG_c  0x4000
#define FLAG_S  0x8000 // completed

int mx_check_flags(int argc, char *argv[], unsigned short *flags);

#endif

