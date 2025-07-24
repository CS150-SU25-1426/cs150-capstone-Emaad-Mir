#include "TVShow.h"

int main() {

    TVShow t1("The Good Place", "Comedy", 22.1, 53, "TV-14", {});
    t1.addStreamingService("Netflix");
    t1.addStreamingService("Amazon Video");
    t1.addStreamingService("Apple TV");

    cout << t1 << "\n";

    cout << "Is " << t1.getName() << " available on Netflix? " << (t1.isAvailable("Netflix") ? "yes!" : "no") << "\n";
    cout << "Is " << t1.getName() << " available on Peacock? " << (t1.isAvailable("Peacock") ? "yes!" : "no") << "\n\n";


    TVShow t2("Breaking Bad", "Drama", 47.0, 62, "TV-14", {});
    t2.addStreamingService("Netflix");
    t2.addStreamingService("Apple TV");


    cout << t2 << "\n";

    cout << "Is " << t2.getName() << " available on Netflix? " << (t1.isAvailable("Netflix") ? "yes!" : "no") << "\n";
    cout << "Is " << t2.getName() << " available on Paramount+? " << (t1.isAvailable("Paramount+") ? "yes!" : "no") << "\n\n";


    cout << "Are the summaries for The Good Place and Breaking Bad the same? " << ((t1 == t2) ? "yes" : "no") << "\n";

    return 0;
}