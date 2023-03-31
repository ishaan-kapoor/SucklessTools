/* user and group to drop privileges to */
static const char *user  = "ishaan"; // "nobody"
static const char *group = "ishaan"; // "nogroup"

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;
#define entrylen 0 /* Length of entries */
static const struct secretpass {
    const char *pass;
    const char *command;
};
static const struct secretpass scom[entrylen] = {
/*	 Password		    command */
	// { "clean",   "/home/ishaan/programs/scripts/clean-screen" },
};
