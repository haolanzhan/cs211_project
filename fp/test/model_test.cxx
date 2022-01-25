#include "model.hxx"
#include <catch.hxx>
#include <ge211.hxx>

struct Random_test_access { ge211::Random random; };

TEST_CASE("Testing Initial Values")
{
    Random_test_access t;;
    Model model(t.random);

    CHECK(model.get_missed() == 0);
    CHECK(model.get_score() == 0);
    CHECK(model.get_time() == 60);

    //This is requirement #10 in proposal, Check that predetermined number of
    // targets is correct
    CHECK(model.get_targets().size() == 35);

    int num_targets = model.get_targets().size();

    for (int i = 0; i<num_targets; i++)
    {
        CHECK(!model.get_targets()[i].get_live());
    }

    //This is requirement 4:
    // Different targets have set, specific point values (smaller target =
    // higher point value)
    for (int i = 1; i<num_targets; i++)
    {
        if (model.get_targets()[i].get_size().height >= model.get_targets()[i-1]
                .get_size().height)
        {
            CHECK(model.get_targets()[i].get_point_val() <=
                  model.get_targets()[i-1].get_point_val() );
        } else
        {
            CHECK(model.get_targets()[i].get_point_val() >=
                  model.get_targets()[i-1].get_point_val() );
        }
    }

    // This tests for requirement 6:
    // The targets are released at a random height and side of screen
    int count = 0;
    for (int i = 1; i<num_targets; i++)
    {
        if(model.get_targets()[i].get_pos().y ==
        model.get_targets()[i-1].get_pos().y)
        {
            count++;
        }
    }
    CHECK(count < 34);
    for (int i = 0; i<num_targets; i++)
    {
        if (model.get_targets()[i].get_direction())
        {
            CHECK(model.get_targets()[i].get_pos().x < 0);
        }
        else
        {
            CHECK(model.get_targets()[i].get_pos().x >=
            model.get_screen().width);
        }
    }

}

TEST_CASE("Hitting first Target")
{
    Random_test_access t;
    Model model(t.random);

    model.launch_target();
    CHECK(model.get_targets()[0].get_live());

    int num_targets = model.get_targets().size();

    for (int i = 1; i<num_targets; i++)
    {
        CHECK(!model.get_targets()[i].get_live());
    }

    int target_score_val = model.get_targets()[0].get_point_val();

    //This checks for requirement 9: when the target is selected it disappears
    bool friendly = model.get_targets()[0].is_friendly();
    model.destroy_hit_target(0);
    CHECK(model.get_targets().size() == 34);
    num_targets--;
    for (int i = 0; i<num_targets; i++)
    {
        CHECK(!model.get_targets()[i].get_live());
    }

    // This Checks for requirement 3:
    // Each time a target is selected by the mouse the score changes
    if (friendly)
    {
        CHECK(model.get_score() == -1*target_score_val);
    }else
    {
        CHECK(model.get_score() == target_score_val);
    }
}

TEST_CASE("Hitting middle Target")
{
    Random_test_access t;
    Model model(t.random);

    int num_targets = model.get_targets().size();

    for (int i = 0; i<num_targets; i++)
    {
        model.launch_target();
        CHECK(model.get_targets()[i].get_live());
    }

    model.destroy_hit_target(12);
    CHECK(model.get_targets().size() == 34);
    num_targets--;
}

TEST_CASE("Hitting friendly Target")
{
    Random_test_access t;
    Model model(t.random);

    int num_targets = model.get_targets().size();
    bool found = false;
    int score = 0;
    for (int i = 0; i<num_targets; i++)
    {
        if (model.get_targets()[i].is_friendly())
        {
            score = model.get_targets()[i].get_point_val();
            model.destroy_hit_target(i);
            found = true;
            break;
        }
    }

    CHECK(model.get_score() == -1 * score);
}

TEST_CASE("Missing a Nonfriendly Target")
{
    Random_test_access t;
    Model model(t.random);

    //Tests for requirement 13: point deduction for missing
    int num_targets = model.get_targets().size();
    bool found = false;
    int score = 0;
    std::vector<int> index;
    for (int i = 0; i<num_targets; i++)
    {
        if (!model.get_targets()[i].is_friendly())
        {
            score = model.get_targets()[i].get_point_val();
            found = true;
            index.push_back(i);
            break;
        }
    }

    model.destroy_missed_target(index);
    CHECK(model.get_targets().size() == 34);

    CHECK(model.get_score() == -1*score/2);

    //Checke for requirement 12: The missed target
    // value will only increment upon the far side of the
    // target colliding with the side which is when the target will disappear
    CHECK(model.get_missed() == 1);

    index.clear();
    index.push_back(3);
    index.push_back(12);

    model.destroy_missed_target(index);
    CHECK(model.get_targets().size() == 32);
}

TEST_CASE("Missing a friendly Target")
{
    Random_test_access t;
    Model model(t.random);

    //Tests for requirement 13: point deduction for missing
    int num_targets = model.get_targets().size();
    bool found = false;
    int score = 0;
    std::vector<int> index;
    for (int i = 0; i<num_targets; i++)
    {
        if (model.get_targets()[i].is_friendly())
        {
            score = model.get_targets()[i].get_point_val();
            found = true;
            index.push_back(i);
            break;
        }
    }

    model.destroy_missed_target(index);
    CHECK(model.get_targets().size() == 34);

    CHECK(model.get_score() == score);
}

TEST_CASE("decrement time")
{
    Random_test_access t;
    Model model(t.random);
    std::vector<int> point_vec;
    std::vector<int> point_vec_after;

    //Tests requirement 14: As time increases,
    // the point value for a given target decreases
    // in order to incentivize quick selection of the target
    int num_targets = model.get_targets().size();
    for (int i = 0; i<num_targets; i++)
    {
        point_vec.push_back(model.get_targets()[i].get_point_val());
        model.get_targets()[i].update_point_val();
    }

    model.update(10);
    CHECK(model.get_time() == 50);

    for (int i = 0; i<num_targets; i++)
    {
        point_vec_after.push_back(model.get_targets()[i].get_point_val());
    }

    for (int i = 0; i<num_targets; i++)
    {
        CHECK(point_vec[i] > point_vec_after[i]);
    }
}

//Rest of the requirements can be verified by running the game and observing
// the view

