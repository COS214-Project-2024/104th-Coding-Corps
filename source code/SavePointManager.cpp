#include "SavePointManager.h"

/**
 * @brief Constructs a SavePointManager instance.
 * 
 * Initializes an empty list of save points and sets the current save index to -1.
 */
SavePointManager::SavePointManager() = default;

/**
 * @brief Saves the current state of the CityContext.
 * 
 * Adds a new `SavePoint` to the list of save points. 
 * If new save states are added after undoing to a previous state, 
 * any redo states will be erased.
 * 
 * @param savePoint A shared pointer to the `SavePoint` representing the current state.
 */
void SavePointManager::saveState(std::shared_ptr<SavePoint> savePoint) {
    // Remove any redo states if a new save is created
    if (currentSaveIndex != savePoints.size() - 1) {
        savePoints.erase(savePoints.begin() + currentSaveIndex + 1, savePoints.end());
    }

    savePoints.push_back(savePoint);
    currentSaveIndex++;
}

/**
 * @brief Reverts to the previous state (Undo operation).
 * 
 * Retrieves the `SavePoint` prior to the current save state, 
 * effectively undoing the last save. If there is no previous state, 
 * returns nullptr.
 * 
 * @return A shared pointer to the previous `SavePoint` or nullptr if no prior state exists.
 */
std::shared_ptr<SavePoint> SavePointManager::undo() {
    if (currentSaveIndex > 0) {
        currentSaveIndex--;
        return savePoints[currentSaveIndex];
    }
    return nullptr;  
}

/**
 * @brief Advances to the next state (Redo operation).
 * 
 * Retrieves the `SavePoint` after the current save state, 
 * effectively redoing the previously undone save. If there is no future state, 
 * returns nullptr.
 * 
 * @return A shared pointer to the next `SavePoint` or nullptr if no future state exists.
 */
std::shared_ptr<SavePoint> SavePointManager::redo() {
    if (currentSaveIndex < savePoints.size() - 1) {
        currentSaveIndex++;
        return savePoints[currentSaveIndex];
    }
    return nullptr;  // Return null if no future state exists
}

/**
 * @brief Clears all saved states in the manager.
 * 
 * Removes all `SavePoint` instances from the manager and 
 * resets the current save index to -1, indicating no saved states.
 */
void SavePointManager::clear() {
    savePoints.clear();
    currentSaveIndex = -1;
}

/**
 * @brief Destructor for the SavePointManager.
 * 
 * Ensures the manager is properly cleaned up. Uses default destructor behavior.
 */
SavePointManager::~SavePointManager() = default;
