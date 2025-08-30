#include "LinkedList.h"
#include <string>

int main()
{
    LinkedList<int> list;
    list.addFirst(23);
    list.add(45);
    list.add(56);
    list.add(78);
    std::cout << "First element: " << list.getFirst() << std::endl;
    std::cout << "List size: " << list.getSize() << std::endl;
    std::cout << "Last element: " << list.getLast() << std::endl;
    
    try
    {
        list.removeFirst();
    }
    catch (const char *msg)
    {
        std::cout << "Exception at thread main: " << msg << std::endl;
    }

    list.printList();

    LinkedList<std::string> words;
    words.add("Hello");
    words.add("World");
    words.add("from");
    words.removeAtIndex(1);
    words.printList();

    return 0;
}
