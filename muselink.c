#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "muselink.h"

void print_list(struct song_node * list){
  //printf("format: song title by artist\n");
  while(list){
    printf("~~~~~~");
    printf("|%s by %s|\n", list->name, list-> artist);
    list = list->next;
  }
}

void print_song(struct song_node * list){
  printf("|%s by %s|\n", list->name, list-> artist);
}

struct song_node * insert_front(struct song_node * list, char * song_name, char * song_artist){
  struct song_node * temp = malloc(sizeof(struct song_node));
  temp -> name = song_name;
  temp -> artist = song_artist;
  temp-> next = list;
  return temp;
}

struct song_node * insert_order(struct song_node * list, char * song_name, char * song_artist){
  struct song_node * temp = list;
  struct song_node * prev = malloc(sizeof(struct song_node));
  struct song_node * insert = malloc(sizeof(struct song_node));
  insert->name = song_name;
  insert->artist = song_artist;
  insert->next = NULL;
  if(strcmp(insert-> artist, list->artist) < 0){
    return insert_front(temp, insert->name, insert->artist);
  }
  while(list){
    if(strcmp(insert-> artist, list->artist) < 0){
      break;
    }
    else if(strcmp(insert-> artist, list->artist) == 0){
      if(strcmp(insert->name, list->name) < 0){
        break;
      }
    }
    prev = list;
    list = list->next;
  }
  insert -> next = list;
  prev-> next = insert;
  return temp;
}

void free_list(struct song_node * list){
  while(list){
    struct song_node * temp = list;
    list = list-> next;
    free(temp);
    temp = NULL;
  }
  printf("every song freed!\n");
}

struct song_node * ret_song_artist(struct song_node * list, char * song_name, char * song_artist){
  while(list){
    if(song_name == list->name && song_artist == list-> artist){
      printf("%s by %s found!\n", song_name, song_artist);
      return list;
    }
    list = list-> next;
  }
  printf("%s by %s not found :(\n", song_name, song_artist);
  return NULL;
}

struct song_node * ret_first_song(struct song_node * list, char * song_artist){
  while(list){
    if(song_artist == list->artist){
      printf("first song by %s is %s!\n", song_artist, list->name);
      return list;
    }
    list = list->next;
  }
  printf("%s is not an artist in this list :(\n", song_artist);
  return NULL;
}

struct song_node * ret_random(struct song_node * list){
  srand( time(NULL) );
  int x = rand() % 20;
  int i = rand() % 10;
  struct song_node * temp = list;
  while(x > 0){
    if(temp-> next){
      temp = temp->next;
    }
    x--;
  }
  //printf("%s by %s was removed", temp->name, temp->artist);
  print_song(temp);
  return temp;
  //return free_spec(list, temp->name, temp->artist);
}

struct song_node * free_spec(struct song_node * list, char * song_name, char * song_artist){
  struct song_node * holder = list;
  struct song_node * prev = list;
  if(song_artist == holder->artist && song_name == holder->name){
    list = list->next;
  }
  while(holder){
    if(song_artist == holder-> artist && song_name == holder-> name){
      prev-> next = holder-> next;
      struct song_node * temp = holder;
      free(temp);
      temp = NULL;
      break;
    }
    prev = holder;
    holder = holder-> next;
  }
  return list;
}
