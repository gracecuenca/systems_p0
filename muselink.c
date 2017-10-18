#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//da song node
struct song_node{
  char * name;
  char * artist;
  struct song_node * next;
};

void print_list(struct song_node * list){
  printf("format: song title by artist\n");
  while(list){
    printf("~~~~~~");
    printf("|%s by %s|\n", list->name, list-> artist);
    list = list->next;
  }
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

struct song_node * free_list(struct song_node * list){
  while(list){
    struct song_node * temp = list;
    list = list-> next;
    free(temp);
    temp = NULL;
  }
  return list;
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

int main(){
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
  print_list(jamz);
  ret_song_artist(jamz, "high on you", "survivor");
  ret_song_artist(jamz, "what do you mean", "justin bieber");
  return 0;
}
