#ifndef HEALTH_HPP
#define HEALTH_HPP

class Health {
private:
    int maxHealth;
    int currentHealth;

public:
    // Constructor
    Health();

    // Public member functions
    int getCurrentHealth() const;
    void decreaseHealth();
    void increaseHealth(int amount);
};

#endif // HEALTH_HPP
