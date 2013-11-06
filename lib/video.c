#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define SCREEN_MAX_CHAR 1920
#define SCREEN_MAX_MEM 3840

int row = 0;
int col = 0;
int position = 0;

 void update_cursor(int row, int col)
 {
    unsigned short pos=(row*80) + col;
    // cursor LOW port to vga INDEX register
    outb(0x3D4, 0x0F);
    outb(0x3D5, (unsigned char)(pos&0xFF));
    // cursor HIGH port to vga INDEX register
    outb(0x3D4, 0x0E);
    outb(0x3D5, (unsigned char )((pos>>8)&0xFF));
 }

void putc( char c)
{
    if (col == 160) {row++; col =0;}
    position = (row * 80 * 2) + col;
    char *vidmem = (char *) 0xb8000; //a pointer to video memory
    vidmem[position] = c;
    vidmem[position+1] = 0x7;
    update_cursor(row, col/2+1);
    col = col + 2;
}

void puts( char *string )
{
  int i=0;
   while(string[i] != '\0')
   {
      //if ((string[i] == 92)&&(string[i+1]==110)) //those are ascii codes for \n
      if (string[i]=='\n')
        {
          row++;
          col=0;
          i++;
        }
      else
      {
        putc(string[i]);
        i++;
      }
    }
}

void clrscr()
{
  char *vidmem = (char *)0xB8000;
  int scr_size = 80*25;
  int i;

  for (i=0; i<scr_size; i++) 
  {
    *vidmem++ = 0;
    *vidmem++ = 0xF;
  }
  row=0; col=0;
}

void gets( char *str )
{
 int i=0;
 while(i<=32)
    {
      str[i]=getchar();
      if(( str[i]=='\n') ||  ( str[i]=='\0') )
      {
        str[i]='\0'; return;
      }

      putc(str[i]); // adding echo

    i++;
    }
}
