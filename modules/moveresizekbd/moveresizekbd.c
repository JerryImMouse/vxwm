void
moveresize(const Arg *arg)
{
  	if (selmon->lt[selmon->sellt]->arrange != NULL)
		  return;

    Monitor *m = selmon;
    Client *c = m->sel;
#if INFINITE_TAGS
    int tagidx = getcurrenttag(m);
#endif
    if (!(c && arg && arg->v && c->isfloating))
        return;

    int dx = ((int *)arg->v)[0];
    int dy = ((int *)arg->v)[1];
    int dw = ((int *)arg->v)[2];
    int dh = ((int *)arg->v)[3];

    if (dw != 0 || dh != 0) {
        if (c->x + c->w + dw > m->mw)
            return;
        
        if (c->y + c->h + dh > m->mh)
            return;

        resize(c, c->x, c->y, c->w + dw, c->h + dh, True);
        
        XEvent ev;
        while (XCheckMaskEvent(dpy, EnterWindowMask, &ev));
        return;
    }

    if (dx != 0 || dy != 0) {
        resize(c, c->x + dx, c->y + dy, c->w, c->h, True);

#if INFINITE_TAGS
        int canvas_dx = 0;
        int canvas_dy = 0;

        if (c->x < 0) {
            canvas_dx = c->x;
        } 
        else if (c->x + WIDTH(c) > m->mw) {
            canvas_dx = (c->x + WIDTH(c)) - m->mw;
        }

        if (c->y < 0) {
            canvas_dy = c->y;
        } 
        else if (c->y + HEIGHT(c) > m->mh) {
            canvas_dy = (c->y + HEIGHT(c)) - m->mh;
        }

        if (canvas_dx != 0 || canvas_dy != 0) {
            m->canvas[tagidx].cx += canvas_dx;
            m->canvas[tagidx].cy += canvas_dy;

            Client *tmp;
            for (tmp = m->clients; tmp; tmp = tmp->next) {
                if (ISVISIBLE(tmp)) {
                    tmp->x -= canvas_dx;
                    tmp->y -= canvas_dy;
                    XMoveWindow(dpy, tmp->win, tmp->x, tmp->y);
                }
            }
            drawbar(m);
        }
#endif
    }

    XEvent ev;
    while (XCheckMaskEvent(dpy, EnterWindowMask, &ev));
}
