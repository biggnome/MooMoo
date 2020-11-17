/***************** START OF MOOMOOENCODE.C ************************/
/*
 *  moomooencode.c by Sean O'Gara (sean@ReZn8.com) 7/1/94.
 *
 *  This program encodes a binary file into "MoO mOo moo MOO MOo ... "
 *  where the data in the file is used to determine the cases of the letters.
 *  The file can be decoded by moomoodecode.
 *
 *  Usage: moomooencode expansion-file-name
 *
 *  The program takes the input file from std. input and sends the encoded
 *  result to std. output.  expansion-file-name is the name the file will
 *  get when it is moomoodecoded.
 */

#include <stdio.h>
#include <string.h>

void moosend(char c);

main(int argc, char *argv[])
{
  char *exname;
  int i, l, c;

  if (argc != 2) {
    fprintf(stderr,"\nUsage: %s expansion-file-name\n\n",argv[0]);
    fprintf(stderr,"This program takes the input file from std. input\n");
    fprintf(stderr,"and sends the encoded result to std. output.\n");
    fprintf(stderr,"expansion-file-name is the name the file will get\n");
    fprintf(stderr,"when it is moomoodecoded.\n");
    return;
  }

  exname = argv[1];

  moosend(0);  /* version/format identifier -- change when extensions added */
  l = strlen(exname);
  for (i=0;i<l;i++) moosend(exname[i]);
  moosend(0);

  while ((c = fgetc(stdin)) != EOF) {
    moosend(c);
  }
  printf("\n");
}

void moosend(char c)
{
  static cpos = 0;
  char *lomoo = "moo";
  char *himoo = "MOO";
  int mpos, i;
  int line_len = 74;

  for (i=0;i<8;i++) {
     mpos = cpos++ % 4;
     if (mpos == 3) {
       fputc(' ',stdout);
       ++cpos;
       mpos = 0;
     }
     fputc((c & 128) ? himoo[mpos] : lomoo[mpos],stdout);
     c = c << 1;
     if (cpos > line_len) {
       printf("\n");
       cpos = 0;
     }
  }
}
