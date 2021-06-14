#pragma once

/**
 * Stores level information
 */
class Level
{
public:
    /**
     * Gold that the AI gets at the start of the level
     */
    int starting_ai_gold;

    /**
     * Gold that the Player gets at the start of the level
     */
    int starting_player_gold;

    /**
     * Gold that the Player gets every stat update tick
     */
    int player_income;

    /**
     * Gold that the AI gets when killing an AttackerEntity
     */
    int ai_income;

    /**
     * AMount of lives the AI has. When this rwaches 0 the level is won.
     */
    int ai_lives;

    /**
     * Creates new level
     * 
     * @param ai_gold Starting AI gold
     * @param player_gold Starting player gold
     * @param p_income Income of the player
     * @param a_income Income of the AI for every kill
     * @param lives Lives that the AI has
     */
    Level(int ai_gold, int player_gold, int p_income, int a_income, int lives);
};