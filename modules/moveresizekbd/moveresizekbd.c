#if !INFINITE_TAGS
void
moveresize(const Arg *arg)
{
	XEvent ev;
	Monitor *m = selmon;

	if(!(m->sel && arg && arg->v && m->sel->isfloating))
		return;
  XRaiseWindow(dpy, m->sel->win);
	resize(m->sel, m->sel->x + ((int *)arg->v)[0],
		m->sel->y + ((int *)arg->v)[1],
		m->sel->w + ((int *)arg->v)[2],
		m->sel->h + ((int *)arg->v)[3],
		True);
#if WARP_TO_CLIENT && WARP_TO_CENTER_OF_WINDOW_MOVED_BY_KEYBOARD
  warptoclient(m->sel);
#endif
	while(XCheckMaskEvent(dpy, EnterWindowMask, &ev));
}

#else

void
moveresize(const Arg *arg)
{

    XEvent ev;
    Monitor *m = selmon;
    if(!(m->sel && arg && arg->v && m->sel->isfloating))
      if (selmon->lt[selmon->sellt]->arrange != NULL) return;
    XRaiseWindow(dpy, m->sel->win);
    if (selmon->lt[selmon->sellt]->arrange != NULL) {
      resize(m->sel, m->sel->x + ((int *)arg->v)[0],
		    m->sel->y + ((int *)arg->v)[1],
		    m->sel->w + ((int *)arg->v)[2],
		    m->sel->h + ((int *)arg->v)[3],
		    True);
#if WARP_TO_CLIENT && WARP_TO_CENTER_OF_WINDOW_MOVED_BY_KEYBOARD
      warptoclient(m->sel);
#endif
	    while(XCheckMaskEvent(dpy, EnterWindowMask, &ev));
      return;
    }
    Client *c = m->sel;
    int tagidx = getcurrenttag(m);

    int dx = ((int *)arg->v)[0];
    int dy = ((int *)arg->v)[1];
    int dw = ((int *)arg->v)[2];
    int dh = ((int *)arg->v)[3];

    int nx = c->x + dx;
    int ny = c->y + dy;
    int nw = c->w + dw;
    int nh = c->h + dh;

    int canvas_dx = 0, canvas_dy = 0;

    if (dx != 0 || dy != 0) {
      if (nx < m->wx) {
        canvas_dx = nx - m->wx;
        nx = m->wx;
      } else if (nx + nw + 2 * c->bw > m->wx + m->ww) {
        canvas_dx = (nx + nw + 2 * c->bw) - (m->wx + m->ww);
        nx = m->wx + m->ww - nw - 2 * c->bw;
      }

      if (ny < m->wy) {
        canvas_dy = ny - m->wy;
        ny = m->wy;
      } else if (ny + nh + 2 * c->bw > m->wy + m->wh) {
        canvas_dy = (ny + nh + 2 * c->bw) - (m->wy + m->wh);
        ny = m->wy + m->wh - nh - 2 * c->bw;
      }

      if (canvas_dx != 0 || canvas_dy != 0) {
        m->canvas[tagidx].cx -= canvas_dx;
        m->canvas[tagidx].cy -= canvas_dy;

        Client *tmp;
        for (tmp = m->clients; tmp; tmp = tmp->next) {
          if (ISVISIBLE(tmp) && tmp != c) {
            tmp->x -= canvas_dx;
            tmp->y -= canvas_dy;
            XMoveWindow(dpy, tmp->win, tmp->x, tmp->y);
          }
        }
      }
    }

    resize(c, nx, ny, nw, nh, True);
    focus(c);
#if WARP_TO_CLIENT && WARP_TO_CENTER_OF_WINDOW_MOVED_BY_KEYBOARD
    warptoclient(c);
#endif
    while(XCheckMaskEvent(dpy, EnterWindowMask, &ev));
    drawbar(m);
}
#endif
