struct song_node{
  char * name;
  char * artist;
  struct song_node * next;
};
struct song_node * insert_front(struct song_node * list, char * song_name, char * song_artist);
struct song_node * insert_order(struct song_node * list, char * song_name, char * song_artist);
void print_list(struct song_node * list);
struct song_node * ret_song_artist(struct song_node * list, char * song_name, char * song_artist);
struct song_node * ret_first_song(struct song_node * list, char * song_artist);
struct song_node * ret_random(struct song_node * list);
struct song_node * free_spec(struct song_node * list, char * song_name, char * song_artist);
void free_list(struct song_node * list);
