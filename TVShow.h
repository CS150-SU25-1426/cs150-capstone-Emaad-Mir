#ifndef TVSHOW_H
#define TVSHOW_H

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

class TVShow {
protected:

    string name;
    string genre;
    double episodeLength;
    int numEpisodes;
    string audienceRating;
    vector<string> streams;

    TVShow(const TVShow& copy): 
        name(copy.name), 
        genre(copy.genre), 
        episodeLength(copy.episodeLength), 
        numEpisodes(copy.numEpisodes), 
        audienceRating(copy.audienceRating), 
        streams(copy.streams){}

public:
    TVShow(string name, string g, double eL, int nE, string aR, vector<string> s): 
        name(name), 
        genre(g), 
        episodeLength(eL), 
        numEpisodes(nE), 
        audienceRating(aR), 
        streams(s){}
    virtual ~TVShow(){}
    string getName() const;
    string getGenre() const;
    double getEpisodeLength() const;
    int getNumEpisodes() const;
    string getAudienceRating() const;
    vector<string> getServices() const;

    void setName(string name);
    void setGenre(string g);
    void setEpisodeLength(double eL);
    void setNumEpisodes(int nE);
    void setAudienceRating(string aR);
    
    void addStreamingService(string service);
    bool isAvailable(string service);
    double timeToFinish() const;
    virtual string displaySummary() const;
    
    friend bool operator==(const TVShow& t1, const TVShow& t2);
    friend ostream& operator<<(ostream& os, const TVShow& t);

};


#endif