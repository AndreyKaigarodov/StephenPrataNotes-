#ifndef GOLF_H_
#define GOLF_H_

namespace Golf
{
    const int Len = 40;
    struct golf
    {
        char fullname[Len];
        int handicap;
    };

    void setgolf(golf &gf, const char *fullname, int hp);

    int setgolf(golf &gf);

    void handicap(golf &gf, const int hc);

    void showgolf(const golf &gf);

}

#endif