#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel
{
private: 
    string Name;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;

public:
    YouTubeChannel(string name, string ownerName)
    {
        Name = name;
        OwnerName = ownerName; 
        SubscribersCount = 0;
    }

    void GetInfo()
    {
        cout << "Name: " << Name << endl;
        cout << "OwnerName: " << OwnerName << endl;
        cout << "SubscribersCount: " << SubscribersCount << endl;
        cout << "Videos:" << endl;
        for (string videoTitle : PublishedVideoTitles)
        {
            cout << videoTitle << endl;
        }
    }

    string GetName()
    {
        return Name;
    }

    void SetName(string name)
    {
        Name = name;
    }

    string GetOwnerName()
    {
        return OwnerName;
    }

    void SetOwnerName(string ownerName)
    {
        OwnerName = ownerName;
    }

    void Subscribe()
    {
        SubscribersCount++;
    }

    void Unsubscribe()
    {
        if (SubscribersCount <= 0)
        {
            return;
        }

        SubscribersCount--;
    }

    void PublishVideo(string title)
    {
        PublishedVideoTitles.push_back(title);
    }
};

int main()
{
    YouTubeChannel ytChannel("CodeBeauty", "Saldina");

    YouTubeChannel ytChannel2("AmySings", "Amy");

    ytChannel.PublishVideo("C++ for beginners Video 1");
    ytChannel.PublishVideo("HTML & CSS Video 1");
    ytChannel.PublishVideo("C++ OOP Video 1");

    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Unsubscribe();

    ytChannel.GetInfo();

    system("pause>0");
}
