#include "TVShow.h"
#include "TVShowList.h"
#include "AnimatedShow.h"

int main() {

    TVShowList list;
    string name, genre, audienceRating;
    double episodeLength;
    int numEpisodes;
    int numServs;
    string service;
    vector<string> servs;

    int pick;

    do {
		cout << "************************************************************************\n";
		cout << "**                                                                    **\n";
		cout << "**                          WELCOME TO THE                            **\n";
		cout << "**                         TV SHOW INVENTORY                          **\n";
		cout << "**                                                                    **\n";
		cout << "************************************************************************\n";
		cout << "** What would you like to do?                                         **\n";
		cout << "** 1)  Add a new TV Show                                              **\n";
		cout << "** 2)  Edit a TV Show                                                 **\n";
		cout << "** 3)  Remove a TV Show                                               **\n";
		cout << "** 4)  Display all TV Shows                                           **\n";
        cout << "** 5)  Exit                                                           **\n";
		cout << "************************************************************************\n";
		cout << ">> ";
		cin >> pick;
    
		cin.ignore(); // To ignore the \n after choice (preventing brand from being "\n")
        string hold;

    switch (pick){
		case 1: {
			string name, genre, audienceRating, animationStudio;
			double episodeLength;
			int numEpisodes, numServs, numActors;
			vector<string> servs, voiceActors;
			char isAnimated;

			cout << "Is this an animated show? (y/n): ";
			cin >> isAnimated;
			cin.ignore();

			cout << "Enter show name: ";
			getline(cin, name);
			cout << "Enter genre: ";
			getline(cin, genre);
			cout << "Enter episode length (in minutes): ";
			cin >> episodeLength;
			cout << "Enter number of episodes: ";
			cin >> numEpisodes;
			cin.ignore(); // flush newline
			cout << "Enter audience rating: ";
			getline(cin, audienceRating);

			cout << "Enter number of streaming services: ";
			cin >> numServs;
			cin.ignore();
			for (int i = 0; i < numServs; ++i) {
				string service;
				cout << "Enter streaming service " << i + 1 << ": ";
				getline(cin, service);
				servs.push_back(service);
			}

			TVShow* show = nullptr;

			if (tolower(isAnimated) == 'y') {
				cout << "Enter animation studio: ";
				getline(cin, animationStudio);
				cout << "Enter number of voice actors: ";
				cin >> numActors;
				cin.ignore();
				for (int i = 0; i < numActors; ++i) {
					string actor;
					cout << "Enter voice actor " << i + 1 << ": ";
					getline(cin, actor);
					voiceActors.push_back(actor);
				}

				show = new AnimatedShow(name, genre, episodeLength, numEpisodes,
										audienceRating, servs, animationStudio, voiceActors);
			} else {
				show = new TVShow(name, genre, episodeLength, numEpisodes, audienceRating, servs);
			}

			list.addShow(show);
			break;
		}
		case 2:{
            cout << list << "\n";
            int index;
            cout << "Which TV Show would you like to edit? (enter number above the show): ";
            cin >> index;
            list.editShow(index);
            break;
        }
		case 3:{
			cout << list << "\n";
            int index;
            cout << "Which TV Show would you like to remove? (enter number above the show): ";
            cin >> index;
            list.deleteShow(index);
			break;
        }
		case 4:
			cout << list << endl;
            break;
        
        case 5:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }

	} while (pick != 5);

    return 0;
}