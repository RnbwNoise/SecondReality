#ifndef U2_PORT
#define U2_PORT

#include "platform.h"

// eliminate unnecessary keywords, and pass-through segment and offset macros
#define far
#define _loadds
#define FP_SEG(x)			(x)
#define FP_OFF(x)			(x)

// MSVC defines inp() and outp() as intrinsic functions, so work around their usage
#define inp					inportb
#define outp				outportb

// compatibility workaround for usage of POSIX functions
#define open(filename,oflag) ((int)platform_fopen(filename, "rb"))
#define read(fd, buffer, count) ((int)platform_fread(buffer, 1, count, (PFILE *)(fd)))
#define close(fd) (platform_fclose((PFILE *)(fd)))

extern char *MK_FP(int seg, int off);

unsigned char inportb(unsigned short int port);
extern void outportb(unsigned short int port, unsigned char val);
extern void outport(unsigned short int port, unsigned short int val);

extern int  dis_indemo();
extern int  dis_musplus();
extern int	dis_musrow();
extern void dis_partstart();
extern int  dis_waitb();
extern int  dis_sync();
extern int  dis_exit();
extern void dis_setmframe(int frame);
extern int  dis_getmframe();
extern void dis_setcopper(int routine_number, void (*routine)());

extern void tw_opengraph();
extern void tw_putpixel(int x, int y, int color);
extern int  tw_getpixel(int x, int y);
extern void tw_setpalette(char *pal);
extern void tw_setstart(int s);

// functions which need wrapping because of C library differences
extern int fcrand();

#endif // U2_PORT

