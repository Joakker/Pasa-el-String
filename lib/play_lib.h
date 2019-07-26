#ifndef PLAY_LIB_H_INCLUDED
#define PLAY_LIB_H_INCLUDED

void noop();

typedef struct {
  char          name[25];
  unsigned char successes;
  unsigned char mistakes;
  unsigned int  time;
} Player;

void center(int row, char* title) {
        int len, indent, y, width;

        getmaxyx(stdscr, y, width);

        len = strlen(title);
        indent = (width - len) / 2;

        mvaddstr(row, indent, title);
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

#endif //PLAY_LIB_H_INCLUDED
