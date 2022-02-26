#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel
{
public: 
    string Name;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;

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
};

int main()
{
    YouTubeChannel ytChannel("CodeBeauty", "Saldina");
    ytChannel.PublishedVideoTitles.push_back("C++ for beginners Video 1");
    ytChannel.PublishedVideoTitles.push_back("HTML & CSS Video 1");
    ytChannel.PublishedVideoTitles.push_back("C++ OOP Video 1");

    YouTubeChannel ytChannel2("AmySings", "Amy");

    ytChannel.GetInfo();

    system("pause>0");
}
