#include "lib/io.c"
#include "lib/kbd.c"
#include "lib/video.c"

int main( void )
{
 char a[1000];
 puts ("welcome to OS \n");
 for (;;)
   {
    puts("\n");
    puts("$:");
    gets(a);
    clrscr();
    puts(a);
    }

}

