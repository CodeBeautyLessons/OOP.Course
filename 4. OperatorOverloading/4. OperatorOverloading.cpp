#include <iostream>
#include <string>
#include <ostream>
#include <list>

using namespace std;

struct YouTubeChannel {
    string Name;
    int SubscribersCount;

    YouTubeChannel(string name, int subscribersCount) {
        Name = name;
        SubscribersCount = subscribersCount;
    }

    bool operator==(const YouTubeChannel& youTubeChannel) const {
        return this->Name == youTubeChannel.Name;
    }
};

ostream& operator << (ostream& stream, YouTubeChannel& youTubeChannel) {
    stream << "Name: "              << youTubeChannel.Name              << endl 
           << "Subscribers count: " << youTubeChannel.SubscribersCount  << endl;

    return stream;
}

struct MyCollection {
    list<YouTubeChannel> MyChannels;

    void operator+=(YouTubeChannel& youTubeChannel) {
        this->MyChannels.push_back(youTubeChannel);
    }

    void operator-=(YouTubeChannel& youTubeChannel) {
        this->MyChannels.remove(youTubeChannel);
    }
};

ostream& operator << (ostream& stream, MyCollection& myCollection) {
    for (auto ytChannel : myCollection.MyChannels) {
        stream << ytChannel << endl;
    }

    return stream;
}

int main()
{ 
    YouTubeChannel yt1 = YouTubeChannel("CodeBeauty", 75000);
    YouTubeChannel yt2 = YouTubeChannel("MySecondChannel", 80000);
    cout << yt1 << yt2;

    //also works fine
    operator<<(cout, yt2);

    MyCollection myCollection;

    myCollection += yt1;
    myCollection += yt2;
    myCollection -= yt2;

    cout << myCollection;

    cin.get();
}
