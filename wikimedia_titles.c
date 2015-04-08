/*
  wikimedia_titles.h

  CPSC 223C
  Spring 2015
  CSU Fullerton

  Lab 7: Parsing Wikimedia XML

  Authors: TODO: replace this with your names and CSUF email addresses

*/ 

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "expat.h"

#include "wikimedia_titles.h"

/* TODO: You will probably need to declare several helper functions
   and a structure type to use as userData with expat. */

Wikimedia_Titles* wikimedia_titles_parse(const char* path) {
  /* TODO: implement this function */

  
  /* There is a lot going on here, so I recommend writing smaller
     helper functions, so this function can be only one or two screens
     long. If you write everything directly in this function, it will
     probably have too many local varibles and be to long to
     manage. */

  /* String containing the text of the entire XML file. */
  char* xml;
  int xml_length;

  assert(path);

  fprintf(stderr, "loading '%s'...", path);
  /* TODO: Load the contents of path into xml. Specifically:*/
     
  


     /*   - Try to open path with mode "rb" so seeking will work
	  properly. If that fails, print an error message and return NULL*/
FILE* f;
  f=fopen(path, "rb");
  if (f==NULL){
    fprint(stderr, "error: cou8ld not open '%s'", path);
    return NULL;
  }
  /* Seek to the end with fseek().*/
  fseek(f,0,SEEK_END);


/* Use ftell() to determine the number of bytes in the file.*/
  xml_length=ftell(f);


 /* Try to allocate memory for the xml string, and if that fails
    print an error message and return NULL.*/
  xml=malloc(xml_length);

/* Use fread() to read all the bytes in the file into xml. Again,
   handle an error appropriately.*/
  fread(xml,sizeof(char),xml_length,f);
  /*- Close the file.*/

  fclose(f);

  */
  fprintf(stderr, "\n");

  fprintf(stderr, "counting title tags...");
  /* TODO: Use expat to count hw many <title> tags exist in the XML
     text:

     - Create a parser with XML_ParserCreate. You should be able to
     pass NULL as the encoding.*/
  XML_Parser p=  XML_ParserCreate(NULL);
/*     - Use XML_SetUserData to initialize the user pointer to be a
       pointer to an int storing the number of <title>
       tags. Initialize that int to 0.

     - Use XML_SetElementHandler and XML_SetCharacterDataHandler to
       initialize the parser's callbacks.

     - The start element handler should examine the name string to see
       whether it is "title". If it is, increment the integer that
       userData points to.

     - The end element handler and character data handler don't need
       to do anything.

     - Finally free the parser.
  */
  fprintf(stderr, "found %i\n", 0); /* TODO: fix this to actually print the right number */

  fprintf(stderr, "parsing titles...");
  /* TODO: Now use expat to parse out each title string and place it
     in a partially-filled array.

     - Create a new parser with XML_ParserCreate.

     - Use XML_SetUserData to initialize the user pointer to be a
       pointer to a struct that holds a partialy-filled array of
       strings. The structure will also need a variable to keep track
       of whether or not the parser is currently inside a <title> tag
       or not. Allocate memory for the array, and initialize all the
       struct members.

     - Use XML_SetElementHandler and XML_SetCharacterDataHandler to
       initialize the parser's callbacks.

     - The start element handler should see if the name is "title". If
       it's not, do nothing. Otherwise update the struct to reflect
       that we're currently inside a <title> tag.

     - The end element handler should also see if name is "title". If
       it's not, do nothing. Otherwise, update the struct to reflect
       that we are no longer inside a <title> tag, and increment the
       number of strings in the partially-filled array.

     - The data handler should look inside the struct to see whether
       we are inside a <title> tag. If not, do nothing. Otherwise copy
       the s text into the last string in the array. Hint: pay close
       attention to what expat's documentation says about s being null
       terminated (
       http://www.xml.com/pub/a/1999/09/expat/#chardatahandler ).

     - Finally free the parser.
  */
  fprintf(stderr, "\n");

  /* At this point we've extracted everything we need from the xml
     string, so free it. */
  free(xml);

  fprintf(stderr, "sorting...");
  /* TODO: Sort the title strings using qsort. */
  fprintf(stderr, "\n");

  /* TODO: Allocate a Wikimedia_Titles struct and initialize all its
     fields.  Again, handle an error appropriately. */
  return NULL;
}

int wikimedia_titles_count(Wikimedia_Titles* wt) {
  /* simple getter */
  assert(wt != NULL);
  return wt->title_count;
}

char* wikimedia_titles_get(Wikimedia_Titles* wt, int index) {
  /* simple getter */
  assert(wt != NULL);
  assert(index >= 0);
  assert(index < wt->title_count);
  return wt->titles[index];
}

void wikimedia_titles_free(Wikimedia_Titles* wt) {
  int i;

  assert(wt != NULL);

  /* free each string */
  for (i = 0; i < wt->title_count; i++) {
    free(wt->titles[i]);
  }

  /* free the titles array */
  free(wt->titles);

  /* free the wt struct itself */
  free(wt);
}
