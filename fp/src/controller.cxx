#include "controller.hxx"

Controller::Controller()
    : model_(get_random())
    , view_(model_)
    , mouse_move_pos_(-1, -1)
{
    before_start_ = true;
}

void Controller::draw(ge211::Sprite_set & sprites) {

    view_.draw(sprites, mouse_move_pos_, before_start_);
}

ge211::Dimensions Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}

std::string Controller::initial_window_title() const
{
    return view_.initial_window_title();
}

void Controller::on_frame(double dt) {
    if (!before_start_)
    {
        if(model_.get_time() < 0){
            ge211::Sound_effect music4("game-over.ogg",
                                       ge211::Abstract_game::mixer());
            ge211::Abstract_game::mixer().play_effect(music4);
            before_start_ = true;

        }
        model_.update(dt);
    }

}

void Controller::on_mouse_move(ge211::Position pos) {
    mouse_move_pos_ = pos;
}

void Controller::on_mouse_up(ge211::Mouse_button, ge211::Position pos) {
    int num_targets = model_.get_targets().size();


    for (int i = 0; i < num_targets; i++)
    {
        ge211::Basic_position<double> target_pos = model_.get_targets()[i].get_pos();
        ge211::Dimensions  target_size = model_.get_targets()[i].get_size();
        if (model_.get_targets()[i].get_live())
        {
            if ((target_pos.x <= pos.x) && ((target_pos.x + target_size.width) >= pos.x)
                && (target_pos.y <= pos.y) && ((target_pos.y + target_size.height) >= pos.y))
            {
                if (model_.get_targets()[i].is_friendly()){
                    ge211::Sound_effect music2("bombblows.ogg",
                                               ge211::Abstract_game::mixer());
                    ge211::Abstract_game::mixer().play_effect(music2);
                } else {
                    ge211::Sound_effect music3("duckdies.ogg",
                                               ge211::Abstract_game::mixer());
                    ge211::Abstract_game::mixer().play_effect(music3);
                }
                model_.destroy_hit_target(i);
                return; //You gotta shoot twice, no collatorals
            }
        }
    }
}

void Controller::on_key(ge211::Key key)
{
    if (key == ge211::Key::code('q'))
        quit();


    if (key == ge211::Key::code(' '))
    {
        if (before_start_) {
            before_start_ = false;
            //Add Duck Hunt Music
            ge211::Music_track music("duckhunt.ogg",
                                     ge211::Abstract_game::mixer());
            ge211::Abstract_game::mixer().play_music(music);
        }
    }

    if (key == ge211::Key::code('r'))
    {
        model_.reset(get_random());
        before_start_ = true;
    }




}