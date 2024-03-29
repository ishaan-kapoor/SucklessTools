/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                     /* -b  option; if 0, dmenu appears at bottom     */
static int restrict_return = 0;            /* -r option; if 1, disables shift-return and ctrl-return */
static int centered = 0;                   /* -c option; centers dmenu on screen */
static int min_width = 500;                /* minimum width when centered */
static int fuzzy = 1;                      /* -F  option; if 0, dmenu doesn't use fuzzy matching     */
static const int vertpad = 25;             /* vertical padding of bar */
static const int sidepad = 5;              /* horizontal padding of bar */

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"CaskaydiaCove Nerd Font:style=Book:size=14:antialias=true:autohint=true",
	"JoyPixels:style=Regular:size=14:antialias=true:autohint=true",
	"monospace:size=14:antialias=true:autohint=true"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */


static const unsigned int baralpha = 0xcc;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
   /*               fg      bg        border     */
   [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
   [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};


#include "/home/ishaan/.cache/wal/colors-wal-dmenu.h"

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static const unsigned int border_width = 2;
