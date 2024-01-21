#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca {

class Event {
private:
    static int counter; 

    char description[129];  
    int startTime;         
public:
    Event();
    
    void display();

    void set(const char* desc = nullptr);
};

}  

#endif  // SENECA_EVENT_H