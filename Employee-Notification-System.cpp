#include<bits/stdc++.h>
using namespace std;

class notificationSystem{
    public:
    virtual void notification(const string &message)=0;
    virtual ~notificationSystem(){}
};

class email:public notificationSystem{
    public:
    void notification(const string &message) override{
        cout<<"email notification : "<<message<<endl;
    }
};

class sms:public notificationSystem{
    public:
    void notification(const string &message) override{
        cout<<"sms notification : "<<message<<endl;
    }
};

class push:public notificationSystem{
    public:
    void notification(const string &message) override{
        cout<<"push notification : "<<message<<endl;
    }
};

void notify(notificationSystem *n, const string &message){
    if(n){
        n->notification(message);
    }
}

int main(){
    string newPolicy="new policy announced";
    string eventReminder="event remainder";
    string systemAlert="system alert";

    notificationSystem *n=nullptr;

    n=new email();
    notify(n, newPolicy);
    delete n;

    n=new sms();
    notify(n, eventReminder);
    delete n;

    n=new push();
    notify(n,  systemAlert);
    delete n;

    return 0;
}