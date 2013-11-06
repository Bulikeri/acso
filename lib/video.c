#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define SCREEN_MAX_CHAR 1920
#define SCREEN_MAX_MEM 3840

int row = 0;
int col = 0;
int position = 0;

void putc( char c)
{
    if (col == 160) {row++; col =0;}
    position = (row * 80 * 2) + col;
    char *vidmem = (char *) 0xb8000; //a pointer to video memory
    vidmem[position] = c;
    vidmem[position+1] = 0x7;
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


