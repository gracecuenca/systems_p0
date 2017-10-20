#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "muselink.h"

struct song_node * construct_song_node(char * song_name, char * song_artist){
  struct song_node * new_node = malloc(sizeof(struct song_node));
  new_node-> name = song_name;
  new_node-> artist = song_artist;
  new_node-> next = NULL;
  return new_node;
}

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
  struct song_node * front = malloc(sizeof(struct song_node));
  front -> name = song_name;
  front -> artist = song_artist;
  front-> next = list;
  return front;
}

struct song_node * insert_order(struct song_node * list, char * song_name, char * song_artist){

  struct song_node * insert = construct_song_node(song_name, song_artist);

  if(strcmp(song_artist, list->artist) < 0){
    return insert_front(list, song_name, song_artist);
  }

  struct song_node * front = list;
  struct song_node * prev = malloc(sizeof(struct song_node));

  while(list){
    if(strcmp(song_artist, list->artist) < 0){
      break;
    }
    else if(strcmp(song_artist, list->artist) == 0){
      if(strcmp(song_name, list->name) < 0){
        break;
      }
    }
    prev = list;
    list = list->next;
  }
  insert -> next = list;
  prev-> next = insert;
  return front;
}

void free_list(struct song_node * list){
  while(list){
    struct song_node * temp = list;
    list = list-> next;
    free(temp);
    temp = NULL;
  }
  //printf("every song freed!\n");
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
