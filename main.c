#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "muselink.c"
#include "myjamz.c"

int main(){

  srand( time(NULL) );

  printf("=======================================\n");
  printf("TESTING MUSIC LINKED LIST FUNCTIONALITY\n");
  printf("=======================================\n\n");
  struct song_node * jamz = 0;

  printf("=======================================\n");
  printf("          Adding some songs...\n");
  printf("=======================================\n\n");

  printf("inserting 'high on you' by survivor\n\n");
  jamz = insert_front(jamz, "high on you", "survivor");

  printf("=======================================\n");
  printf("  Testing insert_front and print_list\n");
  printf("=======================================\n\n");

  printf("inserting a lot of song\n\n");
  print_list(jamz);
  printf("\n");

  jamz = insert_front(jamz, "livin' on a prayer", "bon jovi");
  jamz = insert_order(jamz, "zombie", "the cranberries");
  jamz = insert_order(jamz, "turn me on", "the grates");
  jamz = insert_order(jamz, "hey jude", "the beatles");
  jamz = insert_order(jamz, "dancing queen", "abba");
  jamz = insert_order(jamz, "the search is over", "survivor");
  jamz = insert_order(jamz, "strawberry fields forever", "the beatles");
  jamz = insert_order(jamz, "science is golden", "the grates");
  jamz = insert_order(jamz, "gold", "chet faker");
  jamz = insert_order(jamz, "you give love a bad name", "bon jovi");
  jamz = insert_order(jamz, "knockout", "bon jovi");
  jamz = insert_order(jamz, "karma chameleon", "culture club");

  printf("=======================================\n");
  printf("  Testing insert_order and print_list\n");
  printf("=======================================\n\n");

  print_list(jamz);
  printf("\n");

  printf("=======================================\n");
  printf("Testing return a song w/ artist & name\n");
  printf("=======================================\n\n");

  ret_song_artist(jamz, "high on you", "survivor");
  printf("\n");
  ret_song_artist(jamz, "what do you mean", "justin bieber");
  printf("\n");

  printf("=======================================\n");
  printf("     Testing first song by artist\n");
  printf("=======================================\n\n");
  printf("printing the first song by survivor\n");
  ret_first_song(jamz, "survivor");
  printf("\n");
  ret_first_song(jamz, "paramore");
  printf("\n");

  printf("=======================================\n");
  printf("       Testing random element\n");
  printf("=======================================\n\n");
  ret_random(jamz);
  ret_random(jamz);
  ret_random(jamz);
  printf("\n");

  printf("=======================================\n");
  printf("  Testing removing specified element\n");
  printf("=======================================\n\n");

  jamz = free_spec(jamz, "high on you", "survivor");
  printf("freeing 'high on you' by survivor\n");
  printf("\n");
  print_list(jamz);
  printf("\n");

  printf("=======================================\n");
  printf("       Freeing the entire list :0\n");
  printf("=======================================\n\n");
  free_list(jamz);
  printf("everything freed!\n");
  printf("\n");

  printf("=======================================\n");
  printf("TESTING ARRAY OF MUSIC LINKED LIST FUNC\n");
  printf("=======================================\n\n");

  struct song_node * table[26];
  int i = 0;
  while(i<26){
    table[i] = 0;
    i++;
  }

  add_song(table, "like a rolling stone", "bob dylan");
  add_song(table, "karma chameleon", "culture club");
  add_song(table, "every breath you take", "the police");
  add_song(table, "the one", "kodaline");
  add_song(table, "magnetic", "jessie j");
  add_song(table, "good grief", "bastille");
  add_song(table, "i see you in everyone", "survivor");
  add_song(table, "counting stars", "onerepublic");
  add_song(table, "stolen dance", "milky chance");
  add_song(table, "we didn't start the fire", "billy joel");
  add_song(table, "you belong with me", "taylor swift");
  add_song(table, "alone", "heart");
  add_song(table, "high on you", "survivor");
  add_song(table, "all i want", "kodaline");
  add_song(table, "love runs out", "onerepublic");
  add_song(table, "no surprises", "radiohead");

  printf("=======================================\n");
  printf("    Printing Out the Entire Library\n");
  printf("=======================================\n\n");
  print_library(table);
  printf("\n");

  printf("=======================================\n");
  printf("          Searching for Artist\n");
  printf("=======================================\n\n");
  printf("searching for billy joel...\n");
  artist_search(table, "billy joel");
  printf("searching for backstreet boys...\n");
  artist_search(table, "the backstreet boys");
  printf("\n");

  printf("=======================================\n");
  printf("   Printing Out Entries Under Letter\n");
  printf("=======================================\n\n");
  print_letter(table, 'b');
  printf("\n");

  printf("=======================================\n");
  printf("Printing Out Entries Under Certain Artist\n");
  printf("=======================================\n\n");
  print_artist(table, "milky chance");
  printf("\n");

  printf("=======================================\n");
  printf("           Testing Shuffle\n");
  printf("=======================================\n\n");
  printf("shuffling...\n");
  shuffle(table);
  printf("\n");

  printf("=======================================\n");
  printf("            Testing Delete\n");
  printf("=======================================\n\n");
  printf("removing 'alone by heart'\n");
  delete_song(table, "alone", "heart");
  print_library(table);
  printf("\n");

  printf("=======================================\n");
  printf("            Testing Delete All\n");
  printf("=======================================\n\n");
  delete_songs(table);
  printf("\n");

}
