#include "view.hxx"
#include <string>
#include <iostream>

//Setting Constants
ge211::Color const crosshair_color   {255, 0, 0, 255};
ge211::Color  black_color       {0, 0, 0};
int const crosshair_radius = 6;
ge211::Dimensions instructions_dimensions {800, 450};
int const score_size = 30;
int const title_size = 60;

View::View(Model const& model)
        : model_(model),
          sans_("duckhunt.ttf", score_size)
{}

void View::draw(ge211::Sprite_set& set,
                ge211::Position mouse_move_pos,
                bool before_start)
{
    if (before_start) {
        // START SCREEN W/ INSTRUCTIONS
        black_box_sprite_.recolor({0,0,0});
        set.add_sprite(black_box_sprite_, {
            (model_.get_screen().width/2 - instructions_dimensions.width/2),
            (model_.get_screen().height/2 - instructions_dimensions.height/2)},
                    1);
        ge211::Text_sprite::Builder builder(sans_);
        builder.word_wrap(600);
        builder << "              INSTRUCTIONS" <<
                "                     \n            " <<

                "\r                \nWelcome To Duck Hunt!" <<
                "                     \n             " <<
                "                 ------------------------------------" <<
                "                 Press 'q' To Quit" <<
                "                 Press 'r' To Reset" <<
                "                 Press Space To Start" <<
                "                 ------------------------------------" <<
                "                 Click On The Ducks To Score" <<
                "                 Click On The Bombs, You Lose Points" <<
                "                 Miss The Ducks, You Lose Points" <<
                "                 Miss The Bombs, You Gain Points";

        instructions_sprite_.reconfigure(builder);

        ge211::Position instructions_position = {
                (model_.get_screen().width/2 -
                 instructions_dimensions.width/2 +
                 20),
                (model_.get_screen().height/2 -
                 instructions_dimensions.height/2 +
                 30)};
        set.add_sprite(instructions_sprite_, instructions_position, 2);
    }



    //Set background sprite and crosshair sprite, which is visible at all times
    set.add_sprite(background_, {0,0}, 0);
    mouse_move_pos.x -= (crosshair_radius);
    mouse_move_pos.y -= (crosshair_radius);
    set.add_sprite(crosshair2, mouse_move_pos, 5);

    //Setting Text Sprites
    //Score Sprite
    score_sprite_.reconfigure(
            ge211::Text_sprite::Builder(sans_) << model_.get_score());
    score_label_sprite_.reconfigure(
            ge211::Text_sprite::Builder(sans_) << "Score:");
    ge211::Position score_label_pos = {(model_.get_screen().width/2 - 25),
                                       (model_.get_screen().height - 2*score_size - 20 )};
    ge211::Position score_pos = {(model_.get_screen().width/2 - 25),
                                 (model_.get_screen().height - score_size - 20)};
    set.add_sprite(score_sprite_, score_pos, 1);
    set.add_sprite(score_label_sprite_, score_label_pos, 1);
    //Time Left Sprite
    int time_left_int = model_.get_time();
    time_sprite_.reconfigure(
            ge211::Text_sprite::Builder(sans_) << time_left_int);
    time_label_sprite_.reconfigure(
            ge211::Text_sprite::Builder(sans_) << "Time Left");
    ge211::Position time_label_pos = {10,
                                       (model_.get_screen().height - 2* score_size - 20 )};
    ge211::Position time_pos = {70,
                                 (model_.get_screen().height - score_size - 20)};
    set.add_sprite(time_sprite_, time_pos, 1);
    set.add_sprite(time_label_sprite_, time_label_pos, 1);
    //Missed Target Sprite
    missed_sprite_.reconfigure(
            ge211::Text_sprite::Builder(sans_) << model_.get_missed());
    missed_label_sprite_.reconfigure(
            ge211::Text_sprite::Builder(sans_) << "Missed Targets");
    ge211::Position missed_label_pos = {(model_.get_screen().width - 250),
                                      (model_.get_screen().height - 2*score_size - 20 )};
    ge211::Position missed_pos = {(model_.get_screen().width - 135),
                                (model_.get_screen().height - score_size - 20)};
    set.add_sprite(missed_sprite_, missed_pos, 1);
    set.add_sprite(missed_label_sprite_, missed_label_pos, 1);


    //Add Title on Top Middle
    duck_hunt_title.reconfigure(
            ge211::Text_sprite::Builder({"duckhunt.ttf", title_size}) << "DUCK"
                                                                        " HUNT");
    ge211::Position title_pos = {(model_.get_screen().width/2 - 170),
                                  (20)};
    set.add_sprite(duck_hunt_title, title_pos, 1);

    //Drawing each target
    if(model_.get_time() > 0) {
        int              num_targets = model_.get_targets().size();
        ge211::Position  newpos      = {0, 0};
        ge211::Transform transformation;
        double           scale       = 0;
        for (int         i           = 0; i < num_targets; i++) {
            if (model_.get_targets()[i].get_live()) {
                if (model_.get_targets()[i].is_friendly()) {
                    newpos.x = model_.get_targets()[i].get_pos().x;
                    newpos.y = model_.get_targets()[i].get_pos().y;
                    scale =
                            ((double) model_.get_targets()[i].get_size()
                                                             .width) /
                            100;
                    set.add_sprite(friendly_target_, newpos, 2,
                                   transformation.set_scale(scale));
                } else {
                    newpos.x = model_.get_targets()[i].get_pos().x;
                    newpos.y = model_.get_targets()[i].get_pos().y;
                    scale = model_.get_targets()[i].get_size().width / 100;
                    if (model_.get_targets()[i].get_direction()) {
                        set.add_sprite(bad_target_, newpos, 2,
                                       transformation.set_scale(scale));
                    } else {
                        set.add_sprite(bad_target_flip_, newpos, 2,
                                       transformation.set_scale(scale));
                    }
                }
            }
        }
    } else {
        black_box_sprite_.recolor({255,0,0});
    }
}

ge211::Dimensions View::initial_window_dimensions() const
{
    ge211::Dimensions new_dim = model_.get_screen();
    return new_dim;
}

std::string View::initial_window_title() const
{
    return "Duck Hunt!";
}


