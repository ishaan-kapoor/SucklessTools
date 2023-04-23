/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "CaskaydiaCove Nerd Font:style=Book:size=12:antialias=true:autohint=true", "JoyPixels:style=Regular:size=11:antialias=true:autohint=true", "monospace::size=12:antialias=true:autohint=true"};
static const char dmenufont[]       = "monospace:size=14";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;

#include "/home/ishaan/.cache/wal/colors-wal-dwm.h"

static const unsigned int alphas[][3]      = {
       /*               fg      bg        border     */
       [SchemeNorm] = { OPAQUE, baralpha, borderalpha },
       [SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] =    { "", "", "", "", "", "", "", "", "" };
static const char *tagsalt[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const int momentaryalttags = 0; /* 1 means alttags will show only when key is held down */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   isterminal noswallow monitor */
    { "Gimp",       NULL,       NULL,       0,              1,           0,         0,        -1 },
    { "Firefox",    NULL,       NULL,       1 << 8,         0,           0,         0,        -1 },
    { NULL,         NULL,   "Chromium",     0,              1,           0,         0,        -1 }, // floating profile selection window
    { "Chromium",   NULL,       NULL,       0,              0,           0,         0,        -1 }, // make normal browser tiled
    { "st",         NULL,       NULL,       0,              0,           1,         1,        -1 },
	{ "fSt",        NULL,       NULL,       0,              1,           1,         1,        -1 }, // floating terminal
	{ NULL,         NULL,  "Event Tester",  0,              1,           1,         1,        -1 }, // xev
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "custom.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
    { "|M|",      centeredmaster },    /* first entry is default */
    { ">M>",      centeredfloatingmaster },
    { "[@]",      spiral },
    { "H[]",      deck },
    { "###",      nrowgrid },
    { "[\\]",     dwindle },
    { "TTT",      bstack },
    { "===",      bstackhoriz },
    { "HHH",      grid },
    { "---",      horizgrid },
    { ":::",      gaplessgrid },
    { "[=]",      tile },
    { "[M]",      monocle },
    { "><>",      NULL },    /* no layout function means floating behavior */
    { NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *dmenuruncmd[] = { "run_dmenu", "centre", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *floatingtermcmd[]  = { "st", "-c", "fSt", NULL };
static const char *browsercmd[]  = { "chromium", NULL };
static const char *statbarref[]    = { "/home/ishaan/programs/scripts/sb-refresh", NULL };
static const char *volmutecmd[] = { "/home/ishaan/programs/scripts/dwm-ch-vol", "mute", NULL };
static const char *volupcmd[] = { "/home/ishaan/programs/scripts/dwm-ch-vol", "+5%", NULL };
static const char *voldowncmd[] = { "/home/ishaan/programs/scripts/dwm-ch-vol", "-5%", NULL };
// static const char *volupcmd[] = { "pactl", "set-sink-volume", "0", "+5%", NULL };
static const char *brightupcmd[] = { "/home/ishaan/programs/scripts/dwm-ch-bright", "+5", NULL };
static const char *brightdowncmd[] = { "/home/ishaan/programs/scripts/dwm-ch-bright", "-5", NULL };
static const char *mediaprevcmd[] = { "playerctl", "previous", NULL };
static const char *mediaplaycmd[] = { "playerctl", "play", NULL };
static const char *mediaplaypausecmd[] = { "playerctl", "play-pause", NULL };
static const char *mediapausecmd[] = { "playerctl", "pause", NULL };
static const char *medianextcmd[] = { "playerctl", "next", NULL };
static const char *lockscreencmd[] = { "/home/ishaan/programs/scripts/lock-screen", NULL };
static const char *screenshotcmd[] = { "/home/ishaan/programs/scripts/screenshot", "-f", NULL };
static const char *ssselectivecmd[] = { "/home/ishaan/programs/scripts/screenshot", "-s", NULL };
static const char *sswindowcmd[] = { "/home/ishaan/programs/scripts/screenshot", "-w", NULL };
static const char *ssclipboardcmd[] = { "/home/ishaan/programs/scripts/screenshot", "-c", NULL };


#include <X11/XF86keysym.h>
#define XK_PrintScreen 0x0000ff61
static Key keys[] = {
	/* modifier                     key        function        argument */
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_r,      spawn,          {.v = dmenuruncmd } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { Mod1Mask|ShiftMask,           XK_Return, spawn,          {.v = floatingtermcmd } },
    { MODKEY|ShiftMask,             XK_s,      spawn,          {.v = ssclipboardcmd } },
    { 0,                  XK_PrintScreen,      spawn,          {.v = screenshotcmd } },
    { ShiftMask,          XK_PrintScreen,      spawn,          {.v = ssselectivecmd } },
    { ControlMask,        XK_PrintScreen,      spawn,          {.v = sswindowcmd } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[13]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[12]} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY|ShiftMask,             XK_t,      togglealttag,   {0} },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_q,       quit,           {0} },
    { MODKEY,                      XK_F5,       spawn,          {.v = statbarref } },
    { MODKEY|ShiftMask,             XK_b,       spawn,          {.v = browsercmd } },
    { MODKEY|Mod1Mask,              XK_l,       spawn,          {.v = lockscreencmd} },
    { Mod1Mask,                   XK_Tab,       switchcol,      {0} },
    { 0,                XF86XK_AudioMute,       spawn,          {.v = volmutecmd } },
    { 0,         XF86XK_AudioLowerVolume,       spawn,          {.v = voldowncmd } },
    { 0,         XF86XK_AudioRaiseVolume,       spawn,          {.v = volupcmd } },
    { 0,          XF86XK_MonBrightnessUp,       spawn,          {.v = brightupcmd } },
    { 0,        XF86XK_MonBrightnessDown,       spawn,          {.v = brightdowncmd } },
    { 0,                XF86XK_AudioPrev,       spawn,          {.v = mediaprevcmd } },
    { 0,                XF86XK_AudioPlay,       spawn,          {.v = mediaplaypausecmd } },
    { 0,               XF86XK_AudioPause,       spawn,          {.v = mediaplaypausecmd } },
    { 0,                XF86XK_AudioNext,       spawn,          {.v = medianextcmd } },
    { MODKEY|ShiftMask,             XK_f,       togglefullscr,  {0} },
    { MODKEY,                       XK_x,       movecenter,     {0} },
    { MODKEY,                       XK_g,       incrgaps,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_g,       incrgaps,       {.i = -1 } },
//  { MODKEY|ControlMask,           XK_i,       incrigaps,      {.i = +1 } },
//  { MODKEY|ControlMask|ShiftMask, XK_i,       incrigaps,      {.i = -1 } },
//  { MODKEY|ControlMask,           XK_o,       incrogaps,      {.i = +1 } },
//  { MODKEY|ControlMask|ShiftMask, XK_o,       incrogaps,      {.i = -1 } },
//  { MODKEY|ControlMask,           XK_6,       incrihgaps,     {.i = +1 } },
//  { MODKEY|ControlMask|ShiftMask, XK_6,       incrihgaps,     {.i = -1 } },
//  { MODKEY|ControlMask,           XK_7,       incrivgaps,     {.i = +1 } },
//  { MODKEY|ControlMask|ShiftMask, XK_7,       incrivgaps,     {.i = -1 } },
//  { MODKEY|ControlMask,           XK_8,       incrohgaps,     {.i = +1 } },
//  { MODKEY|ControlMask|ShiftMask, XK_8,       incrohgaps,     {.i = -1 } },
//  { MODKEY|ControlMask,           XK_9,       incrovgaps,     {.i = +1 } },
//  { MODKEY|ControlMask|ShiftMask, XK_9,       incrovgaps,     {.i = -1 } },
    { MODKEY|ControlMask,           XK_0,       togglegaps,     {0} },
    { MODKEY|ControlMask|ShiftMask, XK_0,       defaultgaps,    {0} },
    { MODKEY|ShiftMask,             XK_h,       cyclelayout,    {.i = -1 } },
    { MODKEY|ShiftMask,             XK_l,       cyclelayout,    {.i = +1 } },
    { MODKEY|ShiftMask,             XK_j,       movestack,      {.i = +1 } },
    { MODKEY|ShiftMask,             XK_k,       movestack,      {.i = -1 } },
    { MODKEY|ControlMask,           XK_l,       view_adjacent,  { .i = +1 } },
	{ MODKEY|ControlMask,           XK_h,       view_adjacent,  { .i = -1 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

