#include "model.hxx"
#include "target.hxx"




Model::Model(ge211::Random& rng)
    :     rng_(rng)
{
    for (int i = 0; i < target_number; i++)
    {
        target new_target(rng, screen_dims_);
        targets_.push_back(new_target);
    }

    score_ = 0;
    time_left_ = 60;
    missed_targets_ = 0;
    time_till_launch_ = 2.861;
    launch_count_ = 0;
    time_till_decrement_ = 1;
    decrement_count_ = 0;
}

std::vector<target>& Model::get_targets() const {
    //this is what clion tells me to do, idk if it actually does that
    return (std::vector<target> &) targets_;
}

int Model::get_score() const
{
    return score_;
}

double Model::get_time() const
{
    return time_left_;
}

int Model::get_missed() const {
    return missed_targets_;
}

void Model::launch_target() {
    int num_targets = targets_.size();

    for (int i = 0; i < num_targets; i++)
    {
        if (!targets_[i].get_live())
        {
            targets_[i].make_live();
            return;
        }
    }
}

void Model::target_hit_top_or_bottom()
{
    int num_targets = targets_.size();

    for (int i = 0; i < num_targets; i++) {
        if (targets_[i].get_live()) {
            if (targets_[i].hit_top() || targets_[i].hit_bottom(screen_dims_)) {
                targets_[i].reflect_vertical();
            }

        }
    }
}

void Model::target_hit_left_or_right()
{
    int num_targets = targets_.size();
    //True means going right, false means going left
    bool direction;
    std::vector<int> index;

    for (int i = 0; i < num_targets; i++)
    {
        if(targets_[i].get_live()) {
            // True is right
            direction = targets_[i].get_direction();
            if (direction) {
                if (targets_[i].hit_right(screen_dims_)) {
                    index.push_back(i);
                }
            } else {
                if (targets_[i].hit_left()) {
                    index.push_back(i);
                }
            }
        }
    }

    int size_index = index.size();
    if (size_index > 0)
    {
        destroy_missed_target(index);
    }
}

void Model::destroy_missed_target(std::vector<int> &index) {
    int size_index = index.size();
    int missed_target_index;

    //Goes backwards in the index vector, and deletes the highest index first, so that the indices do not
    //get messed up (the same algorithm will not work if you start at the smallest index that needs to be
    //deleted
    for (int i = (size_index - 1); i >= 0; i--)
    {
        missed_target_index = index[i];

        if (targets_[missed_target_index].is_friendly())
        {
            score_ += targets_[missed_target_index].get_point_val();
        }
        else
        {
            score_ -= targets_[missed_target_index].get_point_val()/2;
            //The score system for missing a target can be subject to change
            missed_targets_++;
        }

        std::swap(targets_[missed_target_index], targets_.back());
        targets_.pop_back();
    }
}

void Model::destroy_hit_target(int index) {
    if (targets_[index].is_friendly())
    {
        score_ -= targets_[index].get_point_val();
    }
    else
    {
        score_ += targets_[index].get_point_val();
    }

    std::swap(targets_[index], targets_.back());
    targets_.pop_back();
}

// called in on_frame()
void Model::decrement_time(double dt)
{
    time_left_  = time_left_ - dt;
    launch_count_ = launch_count_ + dt;
    decrement_count_ += dt;
    if(launch_count_ > time_till_launch_){
        launch_target();
        launch_count_ = 0;
        // As the game progresses, targets launch more quickly
        time_till_launch_ -= 0.06746;
    }
}

void Model::update(double dt)
{
    //deal with dt and then decide when to launch target ...
    decrement_time(dt);

    target_hit_top_or_bottom();
    target_hit_left_or_right();

    ge211::Basic_dimensions<double> new_accel;

    int num_targets = targets_.size();
    for (int i = 0; i < num_targets; i++)
    {
        if (targets_[i].get_live()){
            if (decrement_count_ > time_till_decrement_){
                targets_[i].update_point_val();
                new_accel.width = rng_.between(0, 6);
                new_accel.height = rng_.between(-6, 6);
                targets_[i].update_accel(new_accel);
            }
            targets_[i].update_vel(dt);

            targets_[i] = targets_[i].next();
        }
    }

    // Makes sure that all scores are decremented BEFORE resetting the count
    if (decrement_count_ > time_till_decrement_){
        decrement_count_ = 0;
    }
}

ge211::Dimensions Model::get_screen() const
{
    return screen_dims_;
}

void Model::reset(ge211::Random& rng)
{
    targets_.clear();

    for (int i = 0; i < target_number; i++)
    {
        target new_target(rng, screen_dims_);
        targets_.push_back(new_target);
    }

    score_ = 0;
    time_left_ = 60;
    missed_targets_ = 0;
    time_till_launch_ = 2.861;
    launch_count_ = 0;
    time_till_decrement_ = 1;
    decrement_count_ = 0;
}







