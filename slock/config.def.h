/* user and group to drop privileges to */
static const char *user  = "ishaan"; // "nobody"
static const char *group = "ishaan"; // "nogroup"

static const char *colorname[NUMCOLS] = {
    [BACKGROUND] =   "black",     /* after initialization */
    [INIT] =   "#2d2d2d",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[INPUT_ALT] = "#227799", /* during input, second color */
	[FAILED] = "#CC3333",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* time in seconds before the monitor shuts down */
static const int monitortime = 5;

#define entrylen 0 /* Length of entries */
static const struct secretpass {
    const char *pass;
    const char *command;
};
static const struct secretpass scom[entrylen] = {
/*	 Password		    command */
	// { "clean",   "/home/ishaan/programs/scripts/clean-screen" },
};


/*Enable blur*/
#define BLUR
/*Set blur radius*/
static const int blurRadius=10;
/*Enable Pixelation*/
#define PIXELATION
/*Set pixelation radius*/
static const int pixelSize=10;

/* insert grid pattern with scale 1:1, the size can be changed with logosize */
static const int logosize = 75;
static const int logow = 12;   /* grid width and height for right center alignment*/
static const int logoh = 6;

static XRectangle rectangles[9] = {
       /* x    y       w       h */
       { 0,    3,      1,      3 },
       { 1,    3,      2,      1 },
       { 0,    5,      8,      1 },
       { 3,    0,      1,      5 },
       { 5,    3,      1,      2 },
       { 7,    3,      1,      2 },
       { 8,    3,      4,      1 },
       { 9,    4,      1,      2 },
       { 11,   4,      1,      2 },

};

