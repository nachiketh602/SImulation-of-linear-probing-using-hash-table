#ifndef CONFIG_H_
#define CONFIG_H_
/*
** All the required configuration constants are declared here
** Nord theme is defaultly used without users altering anything in this file
**
** SIM_INTERVAL :- this value should be set to the amount of time out between
** each comparision or operation.
**
** BACKGROUND_COLOR :- this value should be set to the background color of the
** simulation window.
**
** SCANFILL_COLOR :- this value is used to fill the NULL nodes in the HashMap.
**
** HIGHLIGHT_COLOR :- this value is used to color the currently highlighted
** display cell in the simulation window.
**
*/

#define SIM_INTERVAL 2
#define BACKGROUND_COLOR /* R/255 */ 0.180, /* G/255 */ 0.204, /* B/255 */ 0.250
#define SCANFILL_COLOR /*R*/ 58, /*G*/ 64, /*B*/ 76
#define HIGHLIGHT_COLOR /*R*/ 235, /*G*/ 203, /*B*/ 139
#endif // CONFIG_H_
