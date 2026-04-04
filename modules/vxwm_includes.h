#pragma once

#if GAPS
#include "gaps/gaps.h"
#endif

#if XRDB
#include "xrdb/xrdb.h"
#endif

#if FULLSCREEN
#include "fullscreen/fullscreen.h"
#endif

#if EWMH_TAGS
#include "ewmh_tags/ewmh_tags.h"
#endif

#if WARP_TO_CLIENT
#include "warptoclient/warptoclient.h"
#endif

#if ENHANCED_TOGGLE_FLOATING
#include "etf/etf.h"
#endif

#if WINDOWMAP
#include "windowmap/windowmap.h"
#endif

#if INFINITE_TAGS
#include "infinitetags/infinitetags.h"
#endif

#if MOVE_RESIZE_WITH_KEYBOARD
#include "moveresizekbd/moveresizekbd.h"
#endif

#if DIRECTIONAL_FOCUS
#include "directionalfocus/directionalfocus.h"
#endif

#if DIRECTIONAL_MOVE
#include "directionalmove/directionalmove.h"
#endif

/* VXWM_MOD [2026-04-02] HARPOON - added harpoon/pins in vxwm just for fun :) */
#if HARPOON
#include "harpoon/harpoon.h"
#endif

#if AUTOSTART
#include "autostart/autostart.h"
#endif

#if EXTERNAL_BARS
#include "externalbars/externalbars.h"
#endif
