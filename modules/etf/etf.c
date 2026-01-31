#if !RESTORE_SIZE_AND_POS_ETF
void
enchancedtogglefloating(const Arg *arg)
{
    if (!selmon->sel || selmon->sel->isfullscreen)
        return;

    Client *c = selmon->sel;
    int prev = selmon->sellt;

    c->isfloating = !c->isfloating;

    if (c->isfloating) {
        int w = c->sfw > 0 ? c->sfw : c->w;
        int h = c->sfh > 0 ? c->sfh : c->h;
        resize(c,
            c->mon->wx + (c->mon->ww - w) / 2,
            c->mon->wy + (c->mon->wh - h) / 2,
            w, h, 0);
    } else {
        selmon->sellt = 0;
        arrange(selmon);
        selmon->sellt = prev;
    }

    arrange(selmon);
}
#else // fuck this shit i almost pulled out all my hair when i wrote this, but atleast it works lol
void
enchancedtogglefloating(const Arg *arg)
{
    if (!selmon->sel || selmon->sel->isfullscreen)
        return;

    Client *c = selmon->sel;
    int wasfloating = c->isfloating;

    Layout *prevlayout = selmon->lt[selmon->sellt];

    c->isfloating = !c->isfloating;

    if (c->isfloating) {
        int w = c->sfw > 0 ? c->sfw : c->w;
        int h = c->sfh > 0 ? c->sfh : c->h;

        int x = c->sfx > 20 && c->sfy > 20 ? c->sfx : c->mon->wx + (c->mon->ww - w) / 2;
        int y = c->sfx > 20 && c->sfy > 20 ? c->sfy : c->mon->wy + (c->mon->wh - h) / 2;

        resize(c, x, y, w, h, 0);

        c->sfx = c->x; c->sfy = c->y;
        c->sfw = c->w; c->sfh = c->h;
    } else {
        c->sfx = c->x;
        c->sfy = c->y;
        c->sfw = c->w;
        c->sfh = c->h;

        selmon->sellt = 0;
        arrange(selmon);

        for (int i = 0; i < LENGTH(layouts); i++) {
            if (selmon->lt[i] == prevlayout) {
                selmon->sellt = i;
                break;
            }
        }
    }

    arrange(selmon);
}
#endif
