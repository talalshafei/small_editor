/*** includes ***/
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>


/*** data ***/
struct termios orig_termios;

/*** terminal ***/
void die(const char *s) {
    perror(s);
    exit(1);
}

void disableRawMode(){
    if(tcsetattr(STDIN_FILENO, TCIFLUSH, &orig_termios) == -1)
        die("tcsetattr");
    
}

void enableRawMode() {
    if (tcgetattr(STDIN_FILENO, &orig_termios) ==-1)
        die("tcgetattr");

    atexit(disableRawMode);

    /*
        ICRNL flag of replacing '\r' with '\n'
        IXON flag for CTRL+S and CTRL+Q
        OPOST flag to for post processing
        ECHO to print typed chars
        ICANON flag for Canonical mode
        IEXTEN for CTRL+V that lets you print control chars
        ISIG for CTRL+C and CTRL+Z signals
    */
    struct termios raw = orig_termios;
    raw.c_iflag &= ~(ICRNL | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    /* 
        the following flags may be already 
        turned off on modern shells but 
        we turn them off for completeness
    */
    raw.c_iflag &= ~(BRKINT | INPCK | ISTRIP);

    // this not a flag this sets the char size to 8-bits
    raw.c_cflag |= (CS8);

    // Timeouts
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
        die("tcsetattr");
}

/*** init ***/
int main() {
    enableRawMode();

    while(1){
        char c = '\0';
        if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)
            die("read");

        if (iscntrl(c)){
            printf("%d\r\n", c);
        } else {
            printf("%d ('%c')\r\n", c, c);
        }
        if(c == 'q') break;
    }
    return 0;
}