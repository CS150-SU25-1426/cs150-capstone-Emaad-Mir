#ifndef TVSHOWLIST_H
#define TVSHOWLIST_H

#include <vector>
#include "TVShow.h"


class TVShowList {
private:
    vector<TVShow> shows;
public:
    void addShow(TVShow t);
    void editShow(int i);
    void deleteShow(int i);

    friend bool operator==(const TVShowList& l1, const TVShowList& l2);
    friend ostream& operator<<(ostream& os, const TVShowList& t);



};

#endif