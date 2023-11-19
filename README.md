***To debug compile issues:***
do
```bash
$ sudo apt-get install apt-file
$ sudo apt-file update
$ apt-file search "X11/extensions/Xinerama.h"
libxinerama-dev: /usr/include/X11/extensions/Xinerama.h
$ sudo apt-get install libxinerama-dev
```
with each header file that is not available.
Do make an exhaustive list of all dependencies this time and commit(or make a pr if the person reading is not Ishaan).
