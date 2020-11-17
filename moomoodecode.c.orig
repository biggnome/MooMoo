/***************** START OF MOOMOODECODE.C ************************/
/*
 * moomoodecode.c by Sean O'Gara (sean@ReZn8.com) 7/1/94.
 *
 * This program decodes a file that was encoded with moomooencode.
 * It reads the moomooencoded file from standard input and makes a file
 * with the name that was encoded in the source file.  It ignores lines
 * that aren't of the form "MoO mOO MOo ...," so you can mash the components
 * of a multi-part file without having to remove headers and mail signatures
 * and whatnot first.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int mooread(void)
{
  static char inbuf[1024];
  static int rdpos = 0;
  static int have_line = 0;
  static int l;
  int i, j;
  int at_end = 0;
  int rslt = 0;
  char c;
  char *himoo = "MOO ";

  for (i=0;i<8;i++) {
    while (!have_line && !at_end) {
      int ok = 1;
      at_end = !gets(inbuf);
      rdpos = 0;
      if (at_end) return -1;
      l = strlen(inbuf);
      if (l == 0) ok = 0;
      for (j=0;(j<l) && ok;j++) if (toupper(inbuf[j]) != himoo[j % 4]) ok = 0;
      if (ok) have_line = 1;
    }
    c = inbuf[rdpos++];
    if (rdpos >= l) have_line = 0;
    if (c == ' ')
      --i;
    else {
      rslt = rslt << 1;
      if (c <= 'Z') rslt |= 1;
    }
  }
  return rslt;
}

main(int argc, char *argv[])
{
  FILE *outfil;
  char outname[1024], resp[80], *c;
  int mr, format;

  if (argc != 1) {
    fprintf(stderr,"\nThis program takes no command line arguments. It\n");
    fprintf(stderr,"reads a moomooencoded file from the standard input and\n");
    fprintf(stderr,"makes a file with the name that was encoded in the\n");
    fprintf(stderr,"source file.  It ignores lines that aren't of the form\n");
    fprintf(stderr,"'MoO mOO MOo ...,' so you can mash the components of a\n");
    fprintf(stderr,"multi-part file without having to remove headers and\n");
    fprintf(stderr,"mail signatures and whatnot first.\n\n");
    return 1;
  }

  format = mooread();
  if (format != 0) {
    fprintf(stderr,"\nThe input file is either not a moomooencoded file or\n");
    fprintf(stderr,"was encoded in a format that this version of the\n");
    fprintf(stderr,"decoder does not support\n");
    return 1;
  }

  c = outname;
  while ((mr=mooread()) > 0) *(c++) = mr;
  *c = 0;

  if (*outname == 0)
    strcpy(outname,"moo.out");

  if ((int)((outfil = fopen(outname,"wb"))) > 0)
    printf("\nCreating %s\n\n",outname);
  else {
    printf("\nCan't create %s -- aborting\n\n",outname);
    return 1;
  }

  while ((mr = mooread()) >= 0) fputc(mr,outfil);

  /* fclose(outfil); */
}



/***************** END OF MOOMOODECODE.C ************************/

