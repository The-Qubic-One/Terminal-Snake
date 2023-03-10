#pragma once

#include <vector>
#include <memory>

#include "Board.h"
#include "State.h"
#include "io/Input.h"

class Entity;
class Food;
class Head;

class Renderer;
class InputManager;

class Game : public InputObserver {
    Board board;
    State state;
    std::vector<std::shared_ptr<Entity>> entities;

    void on_action(ActionCode code) override;

public:
    Game(Board b, State s);

    void init_game(InputManager* input);    //place snake and food etc.

    void update(InputManager* input);
    void render(Renderer* renderer);

    void attach_entity(std::shared_ptr<Entity> entity);
    void detach_entity(std::shared_ptr<Entity> entity);

    void move_food();

    Board& get_board();
    State& get_state();

    Head* get_head();
    Food* get_food();
};