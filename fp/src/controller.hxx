#pragma once

#include "model.hxx"
#include <ge211.hxx>
#include "view.hxx"


//Creates a controller class, which is in charge of the user interaction with the model
class Controller : public ge211::Abstract_game
{

private:
    //Private member variables
    View view_;
    Model model_;
    ge211::Position mouse_move_pos_;
    bool before_start_;

public:
    //public member functions

    //Constructor for making a controller object
    Controller();

protected:
    //Protected ge211 functions

    // Defines how the game responds to mouse clicks, which is checking if the click position
    // intersects with the position of any target
    void on_mouse_up(ge211::Mouse_button, ge211::Position pos) override;

    // Defines how the game responds to mouse movement (which is by telling
    // view where to draw the crosshair).
    void on_mouse_move(ge211::Position pos) override;

    // Updates the model to reflect the passage of time, by calling
    // `Model::update`.
    //
    // While this function is passed `dt`, the elapsed time in seconds since the
    // previous frame, we aren't using that for now.
    void on_frame(double dt) override;

    //Launch game
    void on_key(ge211::Key) override;


    // These three delegate to the view:
    void draw(ge211::Sprite_set& sprites) override;
    ge211::Dimensions initial_window_dimensions() const override;
    std::string initial_window_title() const override;









};