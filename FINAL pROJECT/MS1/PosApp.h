#ifndef POSAPP_H
#define POSAPP_H
#include <string>
namespace sdds
{
class PosApp {
public:
    PosApp(std::string filename);
    void run();

private:
    std::string filename;

    int  menu();
    void addItem();
    void removeItem();
    void stockItem();
    void listItems();
    void POS();
    void saveRecs();
    void loadRecs();
};
}

#endif
