#include "AnimatedShow.h"
#include <iomanip>


AnimatedShow::AnimatedShow(string name, string genre, double eL, int nE, string aR, vector<string> s, string animationStudio, vector<string> voiceActors) 
    : TVShow(name, genre, eL, nE, aR, s), mAnimationStudio(animationStudio), mVoiceActors(voiceActors){}

string AnimatedShow::getAnimationStudio() const{ return mAnimationStudio; }
void AnimatedShow::setAnimationStudio(string animationStudio){ mAnimationStudio = animationStudio; }
vector<string> AnimatedShow::getVoiceActors() const { return mVoiceActors; }
void AnimatedShow::setVoiceActors(vector<string> voiceActors){ mVoiceActors = voiceActors; }


string AnimatedShow::displaySummary() const {
    ostringstream ss;
    ss << TVShow::displaySummary();
    ss << "Additional Information:\n";
    ss << "Animation Studio: " << mAnimationStudio << "\n"
       << "Voice Actors: ";

    const vector<string>& voices = mVoiceActors;

    for(int i = 0; i < voices.size(); i++){
        ss << voices[i] << (i < voices.size()-1 ? ", ": "");
    }

    ss << "\n";
   
    return ss.str();

}

ostream& operator<<(ostream& os, const AnimatedShow& a){
        os << a.displaySummary();
        return os;
}



