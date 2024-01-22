#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca {
    extern unsigned int g_sysClock;
    class Event {
    private:
        char* description{nullptr};
        unsigned int startTime{ 0 };
    public:
        Event();

        Event(const Event& other);

        ~Event();

        Event& operator=(const Event& other);

        void display();

        void set(const char* desc = nullptr);
    };

    

}  

#endif  // SENECA_EVENT_H
