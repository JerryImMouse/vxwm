# vxwm - Versatile X Window Manager for x11 forked from dwm

# Features
vxwm is dwm on steroids, it can be as lightweight as you want.
It has some patches for dwm pre installed that can be enabled/disabled by switching 0 to 1 or vice versa. (like in dwm-flexipatch)
It also has some unique features like 8 sided resize, enhanced toggle floating, warp cursor and more! (They also can be toggled)
Check modules.def.h for full list of features.

But the main feature of vxwm, is infinite tags.
 
Most tiling window managers (like the default dwm) treat your screen like a slide-projector. You click a button, and the current "slide" is swapped for another. If an window is off-screen, it doesn't exist.

With infinite tags enabled, vxwm treats your screen like a magnifying glass over a giant wooden desk.

The Canvas is Infinite
Your windows aren't "on" tags. They are placed on a massive, invisible surface. Your monitor is just a small window through which you look at that surface.

Move the View, Not Just the Windows
Instead of managing "layers" or "hidden states," you manage position.

Want more space? Slide the view over.
Can't find a window? Switch your focus to it, and the world slides until that window is right under your nose.
Lost? Hit the "homecanvas" keybind to snap your view back to the start.
Even though this sounds complex, it is actually pretty lightweight ~250 l.o.c, and is very easy to use.

# Requirements

In order to build vxwm you need the Xlib, Xft and Xinerama header files.

## Deps Installation

Arch Linux:

    sudo pacman -Sy libx11 libxft libxinerama

Void Linux:

    sudo xbps-install -S libX11 libX11-devel libXft libXft-devel libXinerama libXinerama-devel

Gentoo Linux:
    
    sudo emerge -av x11-libs/libX11 x11-libs/libXft x11-libs/libXinerama

# Getting Started:

## Installation

Clone this repository and cd into it.

    git clone https://codeberg.org/wh1tepearl/vxwm.git
    cd vxwm

Edit config.mk to match your local setup (vxwm is installed into
the /usr/local namespace by default).

Afterwards enter the following commands to build and install vxwm:
    
    make
    sudo make clean install

(yes, run make first and only then sudo make clean install)

## Running vxwm

You will need startx utility installed.

Add the following line to your .xinitrc to start vxwm using startx:

    exec vxwm

If you want to restart vxwm without losing your session 
or for hot configuration reload, add something like this to your .xinitrc:

    vxwm &
    exec sleep infinity

And then for restarting vxwm use the rvx utility.

In order to connect vxwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=:1 exec vxwm

(This will start vxwm on display :1)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec vxwm


# Configuration

The configuration of vxwm is done by editing config.h and modules.h to
match your preferences and (re)compiling the source code.

## Adding custom keybinds

Add this to config.h and replace yoursillyprogram with the actual cmd that will be executed in hte keybind (recommended adding it right before keys array):

    static const char *yoursillyprogramcmd[]  = { "yoursillyprogram", NULL };

If your cmd uses multiple arguments, you should write them like this:

    static const char *yoursillyprogramcmd[]  = { "yoursillyprogram", "arg1", "arg2", NULL };

etc.

And then add this to keys massive:

    { MODKEY|ShiftMask,             XK_u, spawn,          {.v = yoursillyprogramcmd } }, 

......Mod    Modificator               Key                      arg

## Modules

Enable/disable (0/1) modules you need/don't need, thats it.

# AFTER ANY CHANGE IN CONFIG/MODULES RECOMPILE VXWM AND RESTART USING RVX

# Acknowledgements

vxwm was made in solo by a linux enthusiast wh1tepearl, many thanks to suckless.org and the [dwm] developers for making dwm in first place.
Thanks 5element developer and hevel wayland compositor developers for inspiration of infinite tags.

Also try:

hevel wayland compositor: https://git.sr.ht/~dlm/hevel

5element: https://hg.sr.ht/~umix11/5element
