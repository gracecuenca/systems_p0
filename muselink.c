#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//da song node
struct song_node{
  char name[256];
  char artist[256];
  struct song_node * next;
};

void print_list(struct song_node * list){
  printf("Song List:\n");
  while(list){
    printf("%s by %s\n", list->name, list-> artist);
    list = list->next;
  }
  //printf("NULL\n");
}

struct song_node * insert_front(struct song_node * list, char * song_name, char * song_artist){
  struct song_node * frntptr;
  frntptr = malloc(sizeof(struct song_node));
  strcpy(frntptr->name, song_name);
  strcpy(frntptr->artist, song_artist);
  return frntptr;
}

struct song_node * free_list(struct song_node * list){
  while(list){
    struct song_node * temp = list;
    list = list-> next;
    free(temp);
    temp = NULL;
  }
  return list;
}

struct song_node * ret_song(char * song_name, struct song_node * list){
  while(list){
    if(song_name == list->name){
      return list;
    }
    list = list-> next;
  }
  return NULL;
}

int main(){
  struct song_node * jamz = 0;
  print_list(jamz);
  jamz = insert_front(jamz, "High on You", "Survivor");
  jamz = insert_front(jamz, "Livin' on a Prayer", "Bon Jovi");
  print_list(jamz);
}
