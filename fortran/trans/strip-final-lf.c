#include <stdio.h>

int main(int argc, char* argv[])
{
   int ch, chn;
   //   FILE * fd = fopen(argv[1], "r");

   //   ch = fgetc(fd);
   //   while ((chn = fgetc(fd)) > 0) {
   ch = getchar();
   while ((chn = getchar()) > 0) {
      putchar(ch);
      ch = chn;        /* don't print last character in file (hopefully '\n') */
   }

   return 0;
}
