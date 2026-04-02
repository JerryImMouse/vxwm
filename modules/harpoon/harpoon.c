// VXWM_MOD [2026-04-02] HARPOON - added harpoon/pins in vxwm just for fun :) 
static void harpoon_pin(const Arg *arg) {
    int slot = arg->ui;
    Client *c = selmon->sel;

    if (!c || slot < 0 || slot >= MAX_PINS)
        return;

    pins[slot] = c;
}

static void harpoon_goto(const Arg *arg) {
    int slot = arg->ui;
    Client *c = pins[slot];
    if (!c)
        return;

    if (!ISVISIBLE(c))
        view(&((Arg){ .ui = c->tags }));

    focus(c);
#if INFINITE_TAGS
    centerwindow(NULL);
#endif
#if WARP_TO_CLIENT && WARP_TO_CENTER_OF_WINDOW_AFFECTED_BY_FOCUSSTACK
    warptoclient(c);
#endif   
    restack(c->mon);
}
