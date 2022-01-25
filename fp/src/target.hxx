//Header file for making the target class

#pragma once

#include <ge211.hxx>

//This class creates target objects for the user to click on
class target
{
    //Private member variables

    //pos_ is defined to be top left of the target
    ge211::Basic_position<double> pos_;
    ge211::Dimensions size_;

    //true defined as starting left going right, false defined as starting right going left
    bool direction_;

    //Note: if the target is moving right, horizontal acceleration should only be positive,
    // since the object slowing down horizontally makes the game too easy and does not make sense.
    // The horizontal velocity should always be positive to prevent backwards movement.
    // If the target is moving left, horizontal acceleration should only be negative, to prevent decelleration.
    // The horizontal velocity should always be negative to prevent backwards movement
    ge211::Basic_dimensions<double> vel_;
    ge211::Basic_dimensions<double> accel_;

    bool friendly_;
    int point_value_;
    bool live_;

    size_t min_size_ = 100; //Min value is 100 ... Can't Scale Down
    size_t max_size_ = 150;

public:

    //public member functions

    //Create a single target of a random size, with live_ set to false,
    // with a random friendly boolean, with 0 initial velocity and 0 acceleration,
    // with a random direction, and with an initial position off the screen
    // (on the left or right side depending on its random direction)
    // Initialize the point_value_ on an algorithm based on its size
    explicit target(ge211::Random& rng, ge211::Dimensions const& screen_dim);

    // ToDo perhaps add another constructor that does not take a screen_dim and fills it out with the default one

    //Updates the velocity based on acceleration
    void update_vel(double dt);

    // Updates the acceleration based on the new inputs. Every 3 seconds,
    // the acceleration is a random generated positive double that can only accelerate, not decelerate
    void update_accel(ge211::Basic_dimensions<double> new_accel);

    //Decrements the point_val by five poitns after each second for live targets
    void update_point_val();

    int get_point_val() const;

    //Make the target live
    void make_live();

    // ToDo As of now, do not think we need a make_dead

    //Returns true if the target is friendly
    bool is_friendly();

    //Gets the position of the target
    ge211::Basic_position<double> get_pos();

    //Gets the direction of the target: true means going left to right
    bool get_direction() const;

    //Gets the state of the target, dead or live
    bool get_live() const;

    //return the size of the target
    ge211::Dimensions get_size();

    //Updates the position and returns a new hypothetical target
    target next();

    // Negates the vertical component of this ball's velocity.
    void reflect_vertical();

    //Test if target hits top of the screen
    bool hit_top() const;

    //Test if target hits bottom of the screen
    bool hit_bottom(ge211::Dimensions const& screen_dim) const;

    //Test if target hits bottom of the screen
    bool hit_left() const;

    //Test if target hits bottom of the screen
    bool hit_right(ge211::Dimensions const& screen_dim) const;


};