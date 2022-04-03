#include <iostream>
#include <string>
#include <ostream>
#include <list>

using namespace std;

class YouTubeChannel {
private:
    string Name;
    int SubscribersCount;

public:
    YouTubeChannel(string name, int subscribersCount) {
        Name = name;
        SubscribersCount = subscribersCount;
    }

    bool operator==(const YouTubeChannel& youTubeChannel) const {
        return this->Name == youTubeChannel.Name;
    }

    friend ostream& operator << (ostream& stream, YouTubeChannel& youTubeChannel);
};

ostream& operator << (ostream& stream, YouTubeChannel& youTubeChannel) {
    stream << "Name: " << youTubeChannel.Name << endl
        << "Subscribers count: " << youTubeChannel.SubscribersCount << endl;

    return stream;
}

class MyCollection {
private:
    list<YouTubeChannel> MyChannels;

public:
    void operator+=(YouTubeChannel& youTubeChannel) {
        this->MyChannels.push_back(youTubeChannel);
    }

    void operator-=(YouTubeChannel& youTubeChannel) {
        this->MyChannels.remove(youTubeChannel);
    }

    friend ostream& operator << (ostream& stream, MyCollection& myCollection);
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
