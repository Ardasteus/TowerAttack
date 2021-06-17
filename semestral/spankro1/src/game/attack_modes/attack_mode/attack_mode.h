#pragma once

using namespace std;

#include <string>
#include <vector>
#include <memory>

class GameManager;
class AttackerEntity;
class IVector2;

class AttackMode
{
public:
    virtual vector<shared_ptr<AttackerEntity>> GetAttackersToDamage(const IVector2& position, const int& radius, GameManager& game_manager) const = 0;
};