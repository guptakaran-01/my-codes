#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//oberver design Pattern for Notification

class Isubscrber{
public:
virtual void update()=0;
virtual ~Isubscrber(){}
};

class Ichannel{
    public:
    virtual void subscribe(Isubscrber* subscriber)=0;
    virtual void unsubscribe(Isubscrber* subscriber)=0;
    virtual void notify()=0;
    virtual ~Ichannel(){}
};


class channel : public Ichannel{
 
    private:
    string name , latest_video;
    vector<Isubscrber*>subscribers;

    public:
    channel(const string& name){
        this->name=name;
    }
    
    //add subscriber
    void subscribe(Isubscrber* subscriber) override{
        if(find(subscribers.begin(),subscribers.end(),subscriber)==subscribers.end()){
            subscribers.push_back(subscriber);
        }
    }

    void unsubscribe(Isubscrber* subscriber){
        auto it =find(subscribers.begin(),subscribers.end(),subscriber);
        if(it != subscribers.end()){
            subscribers.erase(it);
        }        
    }
    void notify()override{
        for(Isubscrber* sub : subscribers){
            sub->update();
        }
    }

    void upload_video(const string& title){
        latest_video=title;
        cout<<"New Video Uploaded on "<<name<<" and the title of the video is "<<latest_video<<endl;
        notify();
    }

    string get_video(){
        return "\nCheckout out new vidoe : " +latest_video+ "\n";
    }
    
};

class Subscriber : public Isubscrber{
    string name ;
    channel* ch;
    public:
    Subscriber (const string& name , channel* ch){
        this->name=name;
        this->ch=ch;
    }

    void update ()override{
        cout<<"Hey "<<name<<" , "<<ch->get_video()<<endl;
    }
};

int main()
{
    channel* ch=new channel("lets_code");
    Subscriber* sub1=new Subscriber("Nikhil",ch);
    Subscriber* sub2=new Subscriber("Bunny" ,ch);

    ch->subscribe(sub1);
    ch->subscribe(sub2);

    ch->upload_video("  LEETCODE PROBLEM : 1 ");

    ch->unsubscribe(sub2);

    ch->upload_video("  LEETCODE PROBLEM : 2 ");

    
    return 0;
}

