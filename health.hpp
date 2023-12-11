#ifndef HEALTH_HPP
#define HEALTH_HPP
#include <iostream>
class Health{
private:
    int maxHealth;
    int currentHealth;

public:
    // Constructor
    Health();

    // Public member functions
    int getCurrentHealth() const;
    void decreaseEnemyHealth();
    void increaseHealth(int amount);
};

#endif // HEALTH_HPP
