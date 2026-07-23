#include<iostream> 
#include<bits/stdc++.h>

using namespace std;

// Abstract observer interface: Subscribers must implement update()
class ISubscriber {
public:
    virtual void update() = 0;
    virtual ~ISubscriber() {}
}; 

// Abstract observable interface: a Youtube channel interface
class IChannel {
public:
    virtual void subscribe(ISubscriber* subscriber) = 0;
    virtual void unsubscribe(ISubscriber* subscriber) = 0;
    virtual void notifySubscribers() = 0;
    virtual ~IChannel() {}
};

// Concrete subject: a Youtube channel that subscribers can subscribe to
class Channel : public IChannel {
private:
    vector<ISubscriber*> subscribers; // list of subscribers
    string name;
    string latestVideo;

public:
    Channel(const string &name)
    {
        this->name = name;
    }

    //add a subscriber
    void subscribe(ISubscriber* subscriber)
    {
        if(find(subscribers.begin() , subscribers.end() , subscriber) == subscribers.end())
        {
            subscribers.push_back(subscriber);
        }
        else
        {
            cout << "You are already subscriber to this channel !" << endl;
        }
    }

    //remove a subscriber
    void unsubscribe(ISubscriber* subscriber)
    {
        auto it = find(subscribers.begin() , subscribers.end() , subscriber);

        if(it != subscribers.end())
        {
            subscribers.erase(it);
        }
        else 
        {
            cout << "You have not subscribed to this channel yet !" << endl; 
        }
    }

    //notify all subscribers of the latest video
    void notifySubscribers()
    {
        for(ISubscriber* sub : subscribers)
        {
            sub->update();
        }
    }

    //upload a new video and notify all subscribers
    void uploadVideo(const string &title)
    {
        this->latestVideo = title;
        cout << "\n[" << name << " uploaded \"" << title << "\"]" << endl;
        notifySubscribers();
    }

    //read video data
    string getVideoData()
    {
        return "\nCheckout our new video : " + latestVideo + "\n";
    }
};

// concrete observer : Represents a subscriber to the channel

class Subscriber : public ISubscriber {
private:
    string name;
    Channel* channel;

public:
    Subscriber(const string &name , Channel* channel)
    {
        this->name = name;
        this->channel = channel;
    }

    //called by channel : prints notification message
    void update()
    {
        cout << "Hey " << name << "," << this->channel->getVideoData();
    }
};

int main()
{
    //create a channel and subscribers
    Channel* channel = new Channel("CoderArmy");

    Subscriber* s1 = new Subscriber("Manav" , channel);
    Subscriber* s2 = new Subscriber("Varun" , channel);

    channel->subscribe(s1);
    channel->subscribe(s2);

    channel->uploadVideo("Observer pattern tutorial");

    channel->unsubscribe(s2);

    channel->uploadVideo("Decorator pattern tutorial");

    return 0;
}