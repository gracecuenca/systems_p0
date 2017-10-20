void add_song(struct song_node * list[], char * name, char * artist);
struct song_node * song_search(struct song_node * list[], char * name, char * artist);
struct song_node * artist_search(struct song_node * list[], char * artist);
void print_letter(struct song_node * list[], char letter);
void print_artist(struct song_node * list[], char * artist);
void print_library(struct song_node * list[]);
void shuffle(struct song_node * list[]);
void delete_song(struct song_node * list[], char * name, char * artist);
void delete_songs(struct song_node * list[]);
