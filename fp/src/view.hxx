#pragma once

#include "model.hxx"

extern ge211::Color const crosshair_color;
extern ge211::Color  black_color;

extern int const crosshair_radius;
extern ge211::Dimensions  instructions_dimensions;



class View
{
public:
    explicit View(Model const&);

    // You will probably want to add arguments here so that the
    // controller can communicate UI state (such as a mouse or
    // cursor position):
    void draw(ge211::Sprite_set& set, ge211::Position mouse_move_pos, bool before_start);

    ge211::Dimensions initial_window_dimensions() const;

    std::string initial_window_title() const;

private:
    Model const& model_;

    ge211::Font             sans_;

    //Sprites
    ge211::Image_sprite const
            bad_target_ {"duck2.jpg"};
    ge211::Image_sprite const
            bad_target_flip_ {"duck_flip.jpg"};
    ge211::Image_sprite const
            friendly_target_ {"bomb_good.jpg"};
    ge211::Circle_sprite const
            crosshair2 {crosshair_radius, crosshair_color};
    ge211::Image_sprite const
            background_ {"new_background.jpg"};
    ge211::Text_sprite
            score_sprite_;
    ge211::Text_sprite
            score_label_sprite_;
    ge211::Text_sprite
            time_sprite_;
    ge211::Text_sprite
            time_label_sprite_;
    ge211::Text_sprite
            missed_sprite_;
    ge211::Text_sprite
            missed_label_sprite_;

    //Title
    ge211::Text_sprite
            duck_hunt_title;

    //Welcome Screen
    ge211::Text_sprite
            instructions_sprite_;
    ge211::Rectangle_sprite
            black_box_sprite_{instructions_dimensions, black_color};

};