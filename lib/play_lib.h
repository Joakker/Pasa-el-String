#ifndef PLAY_LIB_H_INCLUDED
#define PLAY_LIB_H_INCLUDED

void noop();

typedef struct {
  char          name[25];
  unsigned char successes;
  unsigned char mistakes;
  unsigned int  time;
} Player;



#endif //PLAY_LIB_H_INCLUDED
