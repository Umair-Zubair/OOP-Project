#ifndef HEALTH_HPP
#define HEALTH_HPP

class Health {
private:
    int maxHealth;
    int currentHealth;

public:
    // Constructor
    Health(int max);

    // Public member functions
    int getMaxHealth() const;
    int getCurrentHealth() const;
    void decreaseHealth(int amount);
    void increaseHealth(int amount);
};

#endif // HEALTH_HPP
