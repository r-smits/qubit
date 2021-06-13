#include "event.h"


QubitEvent::QubitEvent(std::string _name, EventType _type)
{
    name = _name;
    type = _type;
}

std::string QubitEvent::getName()
{
    return name;
}


KeyPress::KeyPress(int _key) : QubitEvent("A key press", anyButton) 
{
    key = _key;
}

int KeyPress::getKey()
{
    return key;
}

void KeyPress::print()
{
    std::cout << "This event is called: '" << getName() << "'" << std::endl;
    std::cout << "The key that was pressed: " << getKey() << std::endl;
}


class EventDispatch
{


};


