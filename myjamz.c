#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "myjamz.h"

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

void print_letter(struct song_node * list[], char letter){
  int i = letter - 'a';
  printf("printing songs by artist's whose names start with %c:\n", letter);
  print_list(list[i]);
}

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

void print_library(struct song_node * list[]){
  int i = 0;
  while(i < 26){
    if(list[i]){
      print_list(list[i]);
    }
    i++;
  }
}

void shuffle(struct song_node * list[]){
  srand( time(NULL) );
  int x = 0;
  int i = rand() % 2;
  int z = rand() % 25;
  while (x < 5){
    struct song_node * temp = list[z];
    while(!temp){
      z = rand()%25;
      temp = list[z];
    }
    if(i == 0 && temp->next){
      print_song(temp->next);
    }
    else{
      print_song(temp);
    }
    i=rand()%2;
    z = rand() % 25;
    x++;
  }
}

void delete_song(struct song_node * list[], char * name, char * artist){
  char first_letter = artist[0];
  int i = first_letter - 'a';
  list[i] = free_spec(list[i], name, artist);
}

void delete_songs(struct song_node * list[]){
  int i = 0;
  while(i<26){
    free_list(list[i]);
    i++;
  }
  printf("all song nodes freed!\n");
}
