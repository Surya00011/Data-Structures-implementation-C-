#include "LinkedList.h"
#include <string>

int main()
{
    LinkedList<int> list;
    list.addFirst(23);
    list.add(45);
    list.add(56);
    list.add(78);
    list.addAtIndex(2, 100);
    std::cout << "First element: " << list.getFirst() << std::endl;
    std::cout << "List size: " << list.getSize() << std::endl;
    std::cout << "Last element: " << list.getLast() << std::endl;
    std::cout << list << std::endl;
    try
    {
        list.removeFirst();
    }
    catch (const char *msg)
    {
        std::cout << "Exception at thread main: " << msg << std::endl;
    }
    list.removeAtIndex(1);
    list.printList();

    LinkedList<std::string> words;
    words.add("Hello");
    words.add("World");
    words.add("from");
    words.removeAtIndex(2);
    words.add("C++");
    words.contains("World") ? std::cout << "List contains 'World'\n" : std::cout << "List does not contain 'World'\n";
    words.removeByValue("Hello");
    words.printList();

    return 0;
}
