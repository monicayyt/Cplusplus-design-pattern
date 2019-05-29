#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;
 
struct Creature
{
    int attack, health;
 
    Creature(int attack, int health) : attack(attack), health(health) {}
};
 
struct CardGame
{
    vector<Creature> creatures;
 
    CardGame(const vector<Creature> &creatures) : creatures(creatures) {}
 
    // return the index of the creature that won (is a live)
    // example:
    // - creature1 alive, creature2 dead, return creature1
    // - creature1 dead, creature2 alive, return creature2
    // - no clear winner: return -1
    int combat(int creature1, int creature2)
    {
        // todo
        hit(creatures[creature1], creatures[creature2]);
        if (creatures[creature1].health > 0 && creatures[creature2].health <= 0)
            return creature1;
        else if (creatures[creature1].health <= 0 && creatures[creature2].health > 0)
            return creature2;
        else
            return -1;
    }
 
    virtual void hit(Creature& attacker, Creature& other) = 0;
};
 
struct TemporaryCardDamageGame : CardGame
{
    TemporaryCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}
 
    void hit(Creature &attacker, Creature &other) override
    {
        // todo
        if (attacker.health <= other.attack)
            attacker.health = 0;            
        if (other.health <= attacker.attack)
            other.health = 0;
    }
};
 
struct PermanentCardDamageGame : CardGame
{
    PermanentCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}
 
    void hit(Creature &attacker, Creature &other) override
    {
        // todo
        attacker.health -= other.attack;
        other.health -= attacker.attack;
    }
};
