#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "muselink.h"
#include "muselink.c"

//array of song_nodes
struct song_node * table[26];

//add song nodes
void add_song(struct song_node * list[], char * name, char * artist){
  char first_letter = artist[0];
  int i = first_letter - 'a';
  if(list[i]){
    list[i] = insert_front(list[i], name, artist);
  }
  else{
    list[i] = insert_front(list[i], name, artist);
  }
}

//Search for a song given song and artist name (return a pointer).
struct song_node * song_search(struct song_node * list[], char * name, char * artist){
  int i = 0;
  while(i<26){
    while(list[i]){
      if(list[i]->name == name && list[i]->artist == artist){
        printf("%s by %s was found!\n", name, artist);
        return list[i];
      }
      list[i]= list[i]->next;
    }
    i++;
  }
  printf("%s by %s wasn't found :(\n", name, artist);
  return NULL;
}

//Search for an artist (return a pointer).
struct song_node * artist_search(struct song_node * list[], char * artist){
  char first_letter = artist[0];
  int i = first_letter - 'a';
  struct song_node * ret = list[i];
  while(ret){
    if(ret-> artist == artist){
      printf("%s found!\n", artist);
      //print_list(ret);
      return ret;
    }
    ret= ret->next;
  }
  printf("%s wasn't found :(\n", artist);
  return NULL;
}

//Print out all the entries under a certain letter.
void print_letter(struct song_node * list[], char letter){
  int i = letter - 'a';
  print_list(list[i]);
}

//Print out all the songs of a certain artist
void print_artist(struct song_node * list[], char * artist){
  char first_letter = artist[0];
  int i = first_letter - 'a';
  struct song_node * temp = list[i];
  while(temp){
    if(temp->artist == artist){
      printf("here are %s's songs:\n", artist);
      print_list(temp);
      return;
    }
    temp = temp->next;
  }
}

//Print out the entire library.
void print_library(struct song_node * list[]){
  int i = 0;
  while(i < 26){
    print_list(list[i]);
    i++;
  }
}

//Shuffle - print out a series of randomly chosen songs.

//Delete a song
void delete_song(struct song_node list[], char * name, char * artist){
  
}


//Delete all the nodes.

int main(){

  srand( time(NULL) );
/*
  struct song_node * jamz = 0;
  jamz = insert_front(jamz, "high on you", "survivor");
  jamz = insert_front(jamz, "livin' on a prayer", "bon jovi");
  jamz = insert_order(jamz, "zombie", "the cranberries");
  jamz = insert_order(jamz, "turn me on", "the grates");
  jamz = insert_order(jamz, "hey jude", "the beatles");
  jamz = insert_order(jamz, "dancing queen", "abba");
  jamz = insert_order(jamz, "the search is over", "survivor");
  jamz = insert_order(jamz, "strawberry fields forever", "the beatles");
  jamz = insert_order(jamz, "science is golden", "the grates");
  jamz = insert_order(jamz, "talk is cheap", "chet faker");
  jamz = insert_order(jamz, "you give love a bad name", "bon jovi");
  jamz = insert_order(jamz, "knockout", "bon jovi");
  jamz = insert_order(jamz, "karma chameleon", "culture club");
  ret_song_artist(jamz, "high on you", "survivor");
  ret_song_artist(jamz, "what do you mean", "justin bieber");
  ret_first_song(jamz, "survivor");
  ret_first_song(jamz, "paramore");
  jamz = free_spec(jamz, "high on you", "survivor");
  print_list(jamz);
*/
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

  print_library(table);
  printf("\n");
  print_letter(table, 'b');
  song_search(table, "alone", "heart");
  artist_search(table, "taylor swift");
  print_artist(table, "kodaline");

}
