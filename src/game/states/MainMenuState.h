#pragma once

#include "game/GameState.h"
#include "game/layout/menu/Logo.h"
#include "game/layout/menu/MainMenuBtn.h"
#include "game/layout/menu/PieceRain.h"

#include <array>


class Texture;
class Music;
class SoundEffect;


class MainMenuState: public GameState {
public:
    MainMenuState(AppContext&);
    ~MainMenuState();
    void update(const std::vector<Event>&, AppContext&) final;
    void draw(GraphicsContext&) final;

private:
    std::unique_ptr<Texture> tex_background;
    Layout::Logo logo;
    std::array<Layout::PieceRain, 2> rains;

    std::vector<Layout::MainMenuButton> buttons;
    unsigned current_button_index;

    std::shared_ptr<Music> music;
    std::unique_ptr<Transition<uint8_t>> state_transition_alpha;

    void updatePositions(GraphicsContext&);
    void onFadeoutComplete(AppContext&, std::unique_ptr<GameState>&&);
};
