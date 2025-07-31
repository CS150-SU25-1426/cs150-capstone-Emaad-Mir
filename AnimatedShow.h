#ifndef ANIMATEDSHOW_H
#define ANIMATEDSHOW_H
#include "TVShow.h"

class AnimatedShow : public TVShow {
public:
    AnimatedShow(string name, string genre, double eL, int nE, string aR, vector<string> s, string animationStudio, vector<string> voiceActors);
    string getAnimationStudio() const;
    void setAnimationStudio(string animationStudio);
    vector<string> getVoiceActors() const;
    void setVoiceActors(vector<string> voiceActors);
    friend ostream& operator<<(ostream& os, const AnimatedShow& a);
    virtual string displaySummary() const override;


private:
    string mAnimationStudio;
    vector<string> mVoiceActors;
};


#endif