## Secure Programming ##
## Assignment 3 ##

Author: pz.yao
Email: a1205593@student.adelaide.edu.au
---------------------

## Instructions ##

## Assignment 3 : Attack gedit gdk3 ##

1. Open terminal

2. Type: './attack_gedit_GDK3.sh 10 200 gedit' (Start profiling phase)

3. Profiling result can be found in gedit_gdk3_log.csv

4. Found single event address in gedit_gdk3_log.csv

5. Type: './exploitation /usr/lib/x86_64-linux-gnu/libgdk-3.so.0.1000.8 <Memory Address>' to validate each single event address

6. The folder, `Result/gedit`, contains all iteration results for gedit_gdk3 cache template attack.


## Assignment 3 : Attack Firefox libthread ##

1. Open terminal

2. Type: './attack_firefox_libpthread.sh 10 200 Firefox' (Start profiling phase)

3. Profiling result can be found in firefox_log.csv

4. Found single event address in firefox_log.csv

5. Type: './exploitation /lib/x86_64-linux-gnu/libpthread-2.19.so <Memory Address>' to validate each single event address

6. The folder, `Result/Firefox`, contains all iteration results for Firefox_libthread cache template attack.

## Instruction END ##

## Library command ##
I have used followling command to select target library.

1. 'ps -aux | grep Firefox' (This command will get the pid of target program)

2. 'cat /proc/<TARGET PID NUMBER HERE>/maps | grep r-x | grep lib' (This command will take the program pid and show all readable and executable file with name lib.
3. select possible library from the shown list.

