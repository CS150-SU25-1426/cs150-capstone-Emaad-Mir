#include "TVShow.h"
#include "TVShowList.h"

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
		case 1:
		{
			cout << "Enter Name: ";
			getline(cin, name);
			cout << "Enter Genre: ";
			getline(cin, genre);
			cout << "Enter Episode Length: ";
			cin >> episodeLength;
			cout << "Enter Number of Episodes: ";
			cin >> numEpisodes;
			cout << "Enter Audience Rating: ";
			cin >> audienceRating;
			cout << "Enter the number of streaming services you would like to add: ";
            cin >> numServs;
            cin.ignore();

            servs.clear();

            for(int i = 0; i < numServs; i++){
                cout << "Enter a streaming service: ";
                getline(cin, service);
                servs.push_back(service);
            }

			TVShow show(name, genre, episodeLength, numEpisodes, audienceRating, servs);
			list.addShow(show);

			cout << "\n";
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