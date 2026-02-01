#ifndef MODULES_H
#define MODULES_H

/* vxwm compile-time options */

/* Move/Resize */
#define BETTER_RESIZE 1 // yeah it's better resize support.
#define LOCK_MOVE_RESIZE_REFRESH_RATE 1 // Recomended to use on every pc, because cpu (software) rendered apps like ST will lagg when resizing even if you have a good pc.
#define USE_RESIZECLIENT_FUNC 0 // Use resizeclient function of instead of resize function which ignores window's resize hints, not recommended.



/* Kind of eye candy */
#define GAPS 0 // Gaps support.
#define XRDB 0 // Xrdb support.



/* Bar */
#define ALT_CENTER_OF_BAR_COLOR 0 // changes center of bar color to a dark color.
#define BAR_HEIGHT 0 // Support for changing bar height.
#define BAR_PADDING 0 // Support for changing the bar padding.
#define OCCUPIED_TAGS_DECORATION 0 // This provides the ability to use an alternative text for tags which contain at least one window aka occupied tags.


/* Misc */
#define FULLSCREEN 0 // Support for toggling fullscreen.
#define MOVE_IN_TILED 0 // Support for moving windows in tiled mode.
#define EWMH_TAGS 0 // Support for EWMH tags, recommended if you want to use external bars with less pain
#define ALWAYS_CENTER_NEW_FLOATING_WINDOWS 0 //so, basically, it does what it says.
#define WARP_TO_CLIENT 0 // It warps cursor, where? idk, but use it trust me bro.
#define WARP_TO_CLIENT_AFFECTED_BY_INCNMASTER 0
#define TAG_TO_TAG 0 // If you switch to tag where you already are, it'll switch to previous tag.



/* Floating */ // Recomended to use with ALWAYS_CENTER_NEW_FLOATING_WINDOWS set to 1.
#define FLOATING_LAYOUT_FLOATS_WINDOWS 0 // By default, in floating layout, windows appear to be floating, but, for dwm, they are not. Because of this, when switching to tiled layout after floating layout, windows will be tiled, enable this if you don't want that behaviour.
#define ENHANCED_TOGGLE_FLOATING 0 // Support for enhanced toggle floating, when toggling floating window will resize to its natural size, and in floating layout, window will be tiled.
#define RESTORE_SIZE_AND_POS_ETF 0 // Restore previous size and position of window when toggling floating 

#endif
