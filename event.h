#pragma once
#include <string>
#include <iostream>


enum EventType
{
    mouseClick = 1 << 1,
    anyButton = 1 << 2,
    leftButton = 1 << 3,
    rightButton = 1 << 4,
    upButton = 1 << 5,
    downButton = 1 << 6
};


class QubitEvent
{
private:
    std::string name;
    EventType type;

public:
    QubitEvent(std::string _name, EventType _event);
    std::string getName();
    bool isType(EventType _type) 
    {
        return (type & _type);
    }
    virtual EventType getType() const = 0;
};


class KeyPress : public QubitEvent
{
private:
    int key;

public:
    KeyPress(int _key);
    int getKey();
    static EventType getStaticType() { return anyButton; };
    virtual EventType getType() const override { return getStaticType(); }
    void print();
};



class EventDelegate
{
    template<typename T>
    using func = std::function<bool(T&)>;

public:
    EventDelegate(QubitEvent& _event) : event(_event) {}

    template<typename T>
    bool delegate(func<T> function)
    {
        if (event.getType() == T::getStaticType())
        {
            return function(static_cast<T&>(event));
        }
    
        std::cout << "Your function did not match the required input type." << std::endl;
        return false;    
    }

private:
    QubitEvent& event;
};