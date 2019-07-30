#ifndef IEND_LIB_INCLUDED
#define IEND_LIB_INCLUDED

#define draw_info(N)  mvwprintw(pinfo##N, 1, 1, "Info de %s\n", jugadores[N - 1].name);      \
                      mvwprintw(pinfo##N, 2, 1, "Puntos:\t%d\n", jugadores[N - 1].successes);\
                      mvwprintw(pinfo##N, 3, 1, "Errores:\t%d\n", jugadores[N - 1].mistakes);\
                      mvwprintw(pinfo##N, 4, 1, "Pulsadas\t%d\n", jugadores[N - 1].time);    \
                      box(pinfo##N, 0, 0);                                                   \

#define draw_def()      int i = jugadores[activo].cur_letter;\
                        int j = rand() % (limites[jugadores[activo].cur_letter] + 1);\
                        center(5, dir[i][j].entrada->definicion, define);



#endif  //IEND_LIB_INCLUDED
