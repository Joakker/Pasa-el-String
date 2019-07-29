#ifndef PLAY_LIB_H_INCLUDED
#define PLAY_LIB_H_INCLUDED

void noop();

typedef struct {
  char          name[25];
  unsigned char successes;
  unsigned char mistakes;
  unsigned char cur_letter;
  unsigned int  time;
} Player;

void center(int row, char* title, WINDOW* win) {
        int len, indent, y, width;

        getmaxyx(win, y, width);

        len = strlen(title);
        indent = (width - len) / 2;

        mvwaddstr(win, row, indent, title);
}

char* title_row(int i) {
        switch(i){
                case 1: return TITLE_1;
                case 2: return TITLE_2;
                case 3: return TITLE_3;
                case 4: return TITLE_4;
                case 5: return TITLE_5;
                case 6: return TITLE_6;
        }
}

Player* init_players() {
        Player* jugadores = (Player*) malloc(sizeof(Player)*2);
        for (int i = 0; i < 2 ; i++) {
                jugadores[i].successes = jugadores[i].mistakes = 0;
                jugadores[i].cur_letter = 0;
                jugadores[i].time = 120;
        }
        return jugadores;
}

#endif //PLAY_LIB_H_INCLUDED
