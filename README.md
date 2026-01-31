# vxwm - Versatile X Window Manager for x11

## Requirements

In order to build dwm you need the Xlib header files.

# Getting Started:

## Installation

Edit config.mk to match your local setup (vxwm is installed into
the /usr/local namespace by default).

Enable Xinerama if you need it by uncommenting Xinerama libs in config.mk.

Afterwards enter the following command to build and install vxwm (if
necessary as root):

    make clean install


## Running vxwm

Add the following line to your .xinitrc to start vxwm using startx:

    exec vxwm

If you want to restart vxwm without losing your session 
or for hot configuration reload, add something like this to your .xinitrc:

    vxwm &
    exec sleep infinity

And then for restarting vxwm just kill vxwm's process and start it again.

In order to connect vxwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec vxwm

(This will start vxwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec vxwm


## Configuration

The configuration of vxwm is done by editing config.h and modules.h to
match your preferences and (re)compiling the source code.
