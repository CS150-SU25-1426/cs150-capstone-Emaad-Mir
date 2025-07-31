#include "TVShowList.h"
#include <iomanip>
#include <iostream>


void TVShowList::addShow(TVShow* t){
    shows.push_back(t);
}

void TVShowList::editShow(int i){
    while(i < 0 || i >= shows.size()){
        cout << "Invalid index. Please try again.\n";
        cout << "Which show would you like to change? (enter index): ";
        cin >> i;
    }

    int choice;
    string menu = 
    "What would you like to change about this show?\n"
         "1) Name\n"
         "2) Genre\n"
         "3) Episode Length\n"
         "4) Number of Episodes\n"
         "5) Audience Rating\n"
         "6) Add Streaming Service\n"
         "7) Exit\n";
    
 
    while(true){
        cout << menu;
        cin >> choice;

        while(choice < 1 || choice > 7){
            cout << "Invalid choice. Please enter a choice between 1 and 7 shown above.\n";
            cout << menu;
            cin >> choice;
        }

        if(choice == 7){
            cout << "You chose to exit. Have a nice day!\n";
            break;
        }

        cin.ignore();


        switch(choice){
            case 1:{
                string newName;
                cout << "Enter a new name: ";
                getline(cin, newName);
                shows[i]->setName(newName);
                break;
            }
            case 2:{
                string newGenre;
                cout << "Enter a new genre: ";
                getline(cin, newGenre);
                shows[i]->setGenre(newGenre);
                break;

            }
            case 3:{
                double newEpiLength;
                cout << "Enter a new episode length: ";
                cin >> newEpiLength;
                shows[i]->setEpisodeLength(newEpiLength);
                break;
            }
            case 4:{
                double newNumEpi;
                cout << "Enter a new number of episodes: ";
                cin >> newNumEpi;
                shows[i]->setNumEpisodes(newNumEpi);
                break;
            }
            case 5:{
                string newAudienceRating;
                cin.ignore();
                cout << "Enter a new audience rating: ";
                getline(cin, newAudienceRating);
                shows[i]->setAudienceRating(newAudienceRating);
                break;
            }
            case 6:{
                string newService;
                cin.ignore();
                cout << "Enter another streaming service: ";
                getline(cin, newService);
                shows[i]->addStreamingService(newService);
                break;
            }
        }

    }

}

void TVShowList::deleteShow(int i){
    if(i < 0 || i >= shows.size()){
        cout << "Invalid index.\n";
    } else {
        shows.erase(shows.begin() + i);
    }

}

ostream& operator<<(ostream& os, const TVShowList& t){
    os << "Here is your list of TV Shows:\n\n";
    
    for (int i = 0; i < t.shows.size(); i++) {
        os << "SHOW " << i << ":\n";
        os << t.shows[i]->displaySummary(); 
        os << "\n";
    }

    return os;
}

bool operator==(const TVShowList& l1, const TVShowList& l2) {
    return l1.shows == l2.shows;
}

TVShowList::~TVShowList(){
    for (TVShow* show : shows) {
        delete show;
    }
}


