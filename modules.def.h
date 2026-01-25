#ifndef MODULES_H
#define MODULES_H

/* vxwm compile-time options */
#define BETTER_RESIZE 1 // yeah it's better resize support
#define LOCK_MOVE_RESIZE_REFRESH_RATE 1 // recomended to use on every pc, because cpu (software) rendered apps like ST will lag when resizing even if you have a good pc.
#define USE_RESIZECLIENT_FUNC 0 // use resizeclient function of instead of resize function, not recommended
#define GAPS 0 // gaps support 
#define XRDB 0 //xrdb support
#define ALT_CENTER_OF_BAR_COLOR 0 //changes center of bar color to a dark color
#define BAR_HEIGHT 0 //support for changing bar height
#define BAR_PADDING 0 //support for changing the bar padding
#define FULLSCREEN 0 //support for toggling fullscreen
#define MOVE_IN_TILED 0 //support for moving windows in tiled mode
#define EWMH_TAGS 0 //support for EWMH tags, recommended if you want to use external bars with less pain
#define ALWAYS_CENTER_NEW_FLOATING_WINDOWS 0 //so, basically, it does what it says
#define WARP_TO_CLIENT 0 //it warps cursor, where? idk, but use it trust me bro
#define WARP_TO_CLIENT_AFFECTED_BY_INCNMASTER 0
#define TAG_TO_TAG 1 //if you switch to tag where you already are, it'll switch to previous tag
                     
#endif
