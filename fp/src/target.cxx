
#include "target.hxx"

target::target(ge211::Random &rng, ge211::Dimensions const& screen_dim)
    :pos_(0.0,0.0)
    ,size_({0, 0})
    ,vel_({0.0, 0.0})
    ,accel_({0.5, 0.5})
{
    live_ = false;
    int length = rng.between(min_size_, max_size_);
    //For now, target is a square, but may change
    size_.height = length;
    size_.width = length;

    //Allowing the target to be friendly 1 out of 5 times
    friendly_ = false;
    int placeholder = rng.between(1, 10);
    if (placeholder < 3)
    {
        friendly_ = true;
    }

    //Set random acceleration and velocity initially
    //Initial accel and velocity is defined positively
    accel_.height = rng.between(-2 , 2);
    accel_.width = rng.between(0 , 2);
    vel_.height = rng.between(-4, 4);
    vel_.width = rng.between(6, 9);

    //50% chance target begins on the left vs being on the right
    direction_ = true;
    placeholder = rng.between(1, 2);
    if (placeholder < 2)
    {
        //Flip direction of acceleration and velocity if target is going right
        direction_ = false;
        accel_.width *= -1;
        vel_.width *= -1;
    }

    //Set position off the screen, based on the direction
    placeholder = rng.between(1, screen_dim.height - size_.height);
    pos_.y = placeholder;
    if (direction_)
    {
        pos_.x = -1 * size_.width;
    } else
    {
        pos_.x = screen_dim.width;
    }

    point_value_ = 50 - size_.height/10;
}

void target::update_vel(double dt)
{
    vel_ = vel_ + accel_*dt;
}

void target::update_accel(ge211::Basic_dimensions<double> new_accel)
{

    //Flip acceleration direction based on direction; acceleration cannot be in the
    // opposite direction that the target is travelling because backwards travelling is not
    // allowed
    if (direction_){
        accel_ = new_accel;
    } else {
        accel_ = {(-1 * new_accel.width) , new_accel.height+0};
    }

}

void target::update_point_val()
{
    //value is subject to change
    point_value_ -= 1;
}

void target::make_live()
{
    live_ = true;
}

bool target::is_friendly()
{
    return(friendly_);
}

ge211::Basic_position<double> target::get_pos()
{
    return pos_;
}

bool target::get_direction() const
{
    return direction_;
}

ge211::Dimensions target::get_size()
{
    return size_;
}

target target::next()
{
    target result(*this);

    result.pos_  += result.vel_;
    return result;
}

void target::reflect_vertical()
{
    vel_.height = vel_.height * -1;
}

bool target::hit_top() const
{
    return pos_.y < 0;
}

bool target::hit_bottom(const ge211::Dimensions &screen_dim) const
{
    int y_limit = screen_dim.height - size_.height;
    return pos_.y > y_limit;
}

bool target::hit_right(const ge211::Dimensions &screen_dim) const
{
    int x_limit = screen_dim.width;
    return pos_.x > x_limit;
}

bool target::hit_left() const
{
    return pos_.x < (-1 * size_.width);
}

bool target::get_live() const {
    return live_;
}

int target::get_point_val() const
{
    return point_value_;
}
