#include "lib/io.c"
#include "lib/kbd.c"
#include "lib/video.c"
int strcmp(char *s1,char *s2)
{
int i = 0,c = 0;
while (1)
{ 
  if (i == 5) break;
  if (s1[i] == s2[i]) c++;
  i++;
}
if (i == c) return 1;
return 0;
}

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
    puts("\n");
    if (strcmp(a, "hello")==1){clrscr(); cmd_hello(); }
    }

}

