#include "TVShow.h"
#include <iomanip>
#include <sstream>

    string TVShow::getName() const{ return name; }
    string TVShow::getGenre() const{ return genre; }
    double TVShow::getEpisodeLength() const{ return episodeLength; }
    int TVShow::getNumEpisodes() const{ return numEpisodes; }
    string TVShow::getAudienceRating() const{ return audienceRating; }
    vector<string> TVShow::getServices() const{ return streams; }

    void TVShow::setName(string name){ this->name = name; }
    void TVShow::setGenre(string g){ this->genre = g; }
    void TVShow::setEpisodeLength(double eL){ this->episodeLength = eL; }
    void TVShow::setNumEpisodes(int nE){ this->numEpisodes = nE; }
    void TVShow::setAudienceRating(string aR){ this->audienceRating = aR; }

    
    void TVShow::addStreamingService(string service){
        streams.push_back(service);
    }

    bool TVShow::isAvailable(string service){
        for(int i = 0; i < streams.size(); i++){
            if(service == streams[i]){
                return true;
            }
        }

        return false;
    }

    double TVShow::timeToFinish() const{
        return (episodeLength*numEpisodes)/60.0;
    }


    bool operator==(const TVShow& t1, const TVShow& t2){
        return ((t1.name == t2.name) && (t1.genre == t2.genre)
                && (t1.episodeLength == t2.episodeLength) && (t1.numEpisodes == t2.numEpisodes)
                && (t1.audienceRating == t2.audienceRating) && (t1.streams == t2.streams));
    }

    string TVShow::displaySummary() const {
        ostringstream oss;
        oss << "Here is the summary of the show " << name << ":" << "\n"
           << "Genre: " << genre << "\n" 
           << "Average Episode Length: " << fixed << setprecision(1) << episodeLength << " minutes" << "\n"
           << "Number of Episodes: " << numEpisodes << " episodes" << "\n"
           << "Audience Rating: " << audienceRating << "\n"
           << "Available on: ";
        
        const vector<string>& services = streams;

        for(int i = 0; i < services.size(); i++){
            oss << services[i] << (i < services.size()-1 ? ", ": "");
        }
        oss << "\n";
        oss << "To finish the entire show, you would need to spend " << fixed << setprecision(2) << timeToFinish() << " hours binge watching it!\n";
        oss << "\n";

        return oss.str();
    }
    
    ostream& operator<<(ostream& os, const TVShow& t){
        os << t.displaySummary();
        return os;
    }

