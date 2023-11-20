#include "health.hpp"

Health::Health(int max) : maxHealth(max), currentHealth(max) {}

int Health::getMaxHealth() const {
    return maxHealth;
}

int Health::getCurrentHealth() const {
    return currentHealth;
}

void Health::decreaseHealth(int amount) {
    currentHealth -= amount;

    // Ensure currentHealth doesn't go below 0
    if (currentHealth < 0) {
        currentHealth = 0;
    }
}

void Health::increaseHealth(int amount) {
    currentHealth += amount;

    // Ensure currentHealth doesn't exceed maxHealth
    if (currentHealth > maxHealth) {
        currentHealth = maxHealth;
    }
}
