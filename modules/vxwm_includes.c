#ifndef VXWM_INCLUDES_C
#define VXWM_INCLUDES_C

#if GAPS
#include "gaps/gaps.c"
#endif

#if XRDB
#include "xrdb/xrdb.c"
#endif

#if FULLSCREEN
#include "fullscreen/fullscreen.c"
#endif

#if EWMH_TAGS
#include "ewmh_tags/ewmh_tags.c"
#endif

#if WARP_TO_CLIENT
#include "warptoclient/warptoclient.c"
#endif

#if ENHANCED_TOGGLE_FLOATING
#include "etf/etf.c"
#endif

#if BETTER_RESIZE
#include "betterresize/betterresize.c"
#endif

#if WINDOWMAP
#include "windowmap/windowmap.c"
#endif

#endif
