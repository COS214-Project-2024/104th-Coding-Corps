#ifndef SAVEPOINTMANAGER_H
#define SAVEPOINTMANAGER_H

#include <vector>
#include <memory>
#include <iostream>
#include "SavePoint.h"

/**
 * @brief Caretaker class that manages SavePoint instances for CityContext.
 */
class SavePointManager {
private:
    std::vector<std::shared_ptr<SavePoint>> savePoints;  
    int currentSaveIndex = -1;  

public:
    SavePointManager();

    void saveState(std::shared_ptr<SavePoint> savePoint);

    std::shared_ptr<SavePoint> undo();
 
    std::shared_ptr<SavePoint> redo();

    void clear();

    ~SavePointManager();
};

#endif 
