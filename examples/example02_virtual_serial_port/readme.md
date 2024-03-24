# How to create virtual serial port

You need to install:

    sudo apt install socat

Then:

    sudo socat -d -d pty,rawer,echo=0 pty,rawer,echo=0

## example

    sudo picocom -b 115200 /dev/pts/15

    sudo picocom -b 115200 /dev/pts/16
