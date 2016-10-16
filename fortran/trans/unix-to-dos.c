#include <stdio.h>

int main(int argc, char* argv[])
{
   int ch;
   while ((ch = getchar()) > 0) {
      if (ch == '\n') {
         putchar('\r');
      }
      putchar(ch);
   }

   return 0;
}
