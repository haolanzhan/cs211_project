#pragma once

#include <ge211.hxx>
#include "target.hxx"

//
// Model constants:
//


const int target_number = 35; //The number of targets in the array at start

//
// Model classes:
//

// The current state of the game, keeps track of all the targets, where they are, the score, the time, and the
// amount of targets that the player has missed.
class Model
{

//
// PRIVATE DATA MEMBERS
//

    // The vector of targets
    std::vector<target> targets_;
    // Total score for the game
    int score_;
    // Missed Targets
    int missed_targets_;
    // This variable holds the time left
    double time_left_;
    double time_till_launch_;
    double launch_count_;
    double time_till_decrement_;
    double decrement_count_;
    const ge211::Dimensions screen_dims_ = {1200, 700};
    ge211::Random& rng_;

public :
//
// PUBLIC MEMBER FUNCTIONS
//

// Constructor for the model. Set time_left_ to 60 seconds, score_ to 0, missed_targets_ to 0
// Create a vector of 35 targets
// Takes a Random object rng, pass it to target() when initializing target;
// Controller must be subset of Abstract_game, and use get_random() to pass into it's model
explicit Model(ge211::Random& rng);

//Resets Model
void reset(ge211::Random& rng);

// Views the states of all the targets - return a reference to targets_ vector
std::vector<target>& get_targets() const;

//gets the score of the game
int get_score() const;

//gets the screen dimensions
ge211::Dimensions get_screen() const;

//gets the current time of the game
double get_time() const;

//gets the number of missed targets;
int get_missed() const;

// Sets live to true for the next target that is not already live
// should be called in update, depending on the time_left_ variable (or called in on_frame() maybe?)
// Iterates through the targets_ vector, and makes the first dead target alive
// only responsible for launching a single target at a time
// Probably should be private function
void launch_target();

// Loops through all of the targets, and test for collision with the top or bottom.
// If there is collision, reflect the vertical velocity
// This should be called in update()
// This should call hit_bottom() and hit_top() from target.hxx
void target_hit_top_or_bottom();

// Loops through all of the targets, and test for collision with the sides
// Must test using get_direction() from target.hxx
// If target is going right, use hit_right() from target.hxx to test for collision
// If target is going left, use hit_left() from target.hxx to test for collision
// If collision is detected, get store the index in a vector of ints
// call destroy_missed_target() with the vector of indexes, if this vector is not zero
// if the index vector is zero, than there is no collision with the sides, and this function does nothing
// Probably called in update()
void target_hit_left_or_right();

// Called in target_hit_left_or_right
// decrements the score if the missed target is not friendly
// increments the score if the missed target is friendly
// increments the missed targets counter if the target is not friendly
// starting with the last index in the input vector, swap the corresponding index in the targets_
// vector with the last index in the target vector and call pop_back()
// thus, all the indexes can be deleted
void destroy_missed_target(std::vector<int>& index);

//Called in controller on_mouse_up()
//If the mouse clicks on the target, get that index and pass it into this function
// increment the score if the target is not friendly
// decrement the score of the target is friendly
// swaps the hit index with the last index of the targets_ vector
// pop_back() on the targets_ vector
void destroy_hit_target(int index);

//Based on on_frame(), decrement the time_left_ variable
// Increment the time counter variables
// Based on the time, launch the targets with the given algorithm:
//  At each call, increment launch_count_ and decrement_count_
//  When launch_count_ is greater than a predetermined time_till_launch_, than enough time has passed;
//  At this point, launch the target, decrement time_till_launch_ (so targets launch at increasing speeds)
//  and reset launch_count_ to zero to begin the countdown to the next launch time.
void decrement_time(double dt);

// Updates the model state for
// one time step.
// Updates the time by calling decrement_time()
// Updates targets based on whether they were hit or went out of bounds
// Velocity is incremented with the acceleration FOR all LIVE TARGETS
// Moves the target's position based on velocity for all live targets
// Update the point value of the target:
//      At each call to decrement time, a decrement_count is incremented
//      When decrement_count is greater than a set time_till_decrement_, than enough time has passed to
//      decrement the score
//      At this point, each target will have their score decremented. After all score has been decremented,
//      decrement_count is reset to zero to begin the count to the next time_to_decrement_
//      In this same algorithm, give a new random acceleration to every target every one second
// Should be called in on_frame()
void update(double dt);

private :

    //ToDO May need to update this list. some of these may have to be moved up to public. some of the public may
    // need to move down here. A good strategie would be making everything public for now, and then at the end
    // observe which functions are never used ouside the model.hxx file, and then make it private.
    // And some of the below functions may be deleted because we just bsed it for the proposal

//
// POSSIBLE HELPER FUNCTIONS
//

//TODO not sure what this does
//
// Test access3
    friend struct Test_access;
};