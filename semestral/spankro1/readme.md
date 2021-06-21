## Tower Attack Game by Roman Španko (spankro1)

#### How to play:
The first thing you see is the main menu, you can either continue an old save game or start a new one. If there is not an old save game and you choose to continue, it creates a new one anyway.

Once you continue or start a new one a random map will be picked for you to play on. You will be presented with a set of buttons, these buttons will spawn attackers to run and try to
get to the end. Once they get to the end, AI loses one life. If you manage to take down the AI lives to 0, you win this level and you move on to the next one.

However, you do not instantly go to the next level, you can choose a power up after you win a level. There are three power ups in the game:
 - Bonus Health points - increases the HP of your attackers
 - Bonus Starting gold - gives you more gold at the start of the level
 - Bonus Income - increases your income, so you get more money as time goes on

The AI also generates money, however they get money for every kill. Once you reach the final level, you get to go all over again, the game never ends.

#### How to edit the game files:
The files you can edit usually have the first row filled with the column names used in this file.
If you forget or add a parameter, the game will fail to load the data and you will be unable to play. I will list here quick explanations of each editable file.

##### Attacker Definitions (assets/attacker_definitions)
This file is used to load all available templates for attackers, this is what you see in the "Selection" window when playing the game.

The parameters are:
 - Name - Name of the attacker
 - HP - How much punishment can it outlast
 - Cost - How expensive it will be to spawn
 - Icon - How it will look ingame
 - ArmorType - Armor type of the attacker

There are currently 4 armor types:
 - Normal - Only takes bonus damage from Chaos attacks
 - Physical Resistance - Takes less damage from Physical attacks, but more from Magical
 - Magical Resistance - Same thing but for magic, also takes bit less damage from Chaos
 - Limited Immunity - Ignores the first three attacks, then acts as Normal armor type

#### Defender Definitions (assets/defender_definitions)
This file is used to load all available defender templates, this is what the AI uses.

The parameters are:
 - Name - Name of the defender
 - Damage - Base damage to deal
 - Radius - Reach of the defender
 - Cost - How costly it is to spawn
 - Icon - How it will be represented in game
 - AttackMode - What entities it targets
 - DamageType - What type of damage does this defender use

There are currently 3 attack modes:
 - AoE - the defender targets every attacker in its reach
 - Closest - the defender targets only the closest attacker
 - Furthest - targets the attacker that is furthest away

#### Level Definitions (assets/level)
This file stores the information about levels in the game. There always must be atleast one level. This determines values like gold and income, which can make the game harder.

The parameters are:
 - AIGold - How much gold does the AI start with
 - PlayerGold - How much gold does the Player start with
 - AIOnKillIncome - How much gold does the AI get for each kill
 - PlayerIncome - How much gold does the Player over time
 - Lives - How many lives does the AI have, when at 0 move to the next level or start over

#### Save Game (assets/save_game)
Currently there is only one save game, if a save game does not exist, the game automatically generates a new blank one.
The save game stores the info about current level and power ups.

The parameters are:
 - CurrentLevel - Current level that the player is on
 - BonusGold - How much bonus gold does the player get at the start of a level
 - BonusIncome - Bonus overtime income of the player
 - BonusHP - Bonus health points for attackers spawned by the player

#### Maps (assets/maps/<map_files>, assets/maps/map_list)
Maps are defined as 60 by 20 2D grid.

There are three important characters that must be in a map:
 - dot character '.' - signifies that on this position there is a path for attackers to walk on
 - dollar character '$' - signifies the tile that the attackers are trying to reach
 - roof character '^' - signifies that on this position the attackers spawn

There is one more character 'x' which signifies that this tile is unavailable for the AI to spawn towers on, also used to make maps look a bit better than just black and white, as these tiles are drawn in red.

##### Inlcuding maps
To include a map, you need to make an entry in the map list. Each new line is a map to be added. This way you can filter our maps you dont like, or play on one specific map, you have control over the maps you play on.

#### AI Settings (assets/maps/ai_settings)
This file is used to tweak the difficulty/settings of the AI.

The parameters are:
 - UpdateTime - How fast will the AI try to place defenders down
 - ChoiceStrategy - Which defenders will it opt for
 - PlacementStrategy - Where will the AI place the defenders

There are currently 5 choice strategies:
 - AoE - Spawns only AoE defenders
 - Closest - Spawns only defenders with the Closest attack mode
 - Furthest - Spawns only defenders with the Furthest attack mode
 - Cyclic - Tries to spawn Closest then Furthest then AoE and repeats.
 - Random - Picks a completely random defender to spawn

There are currently 2 placement strategies:
 - Random - Picks a completely random spot to place the defender
 - Path - Picks a random spot around the vicinity of a path