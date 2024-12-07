#include"Executorlmpl.h"
#include<gtest/gtest.h>

namespace adas{

//"RMFB"
TEST(ExecutorlmplTest, should_return_facing_W40_given_command_is_MRMMRLL_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("RMFRRBFB");
    const Pose target({5, -1, 'W'});
    ASSERT_EQ(target, executor->Query());
}

//"RMFMMRB"
TEST(ExecutorlmplTest, should_return_facing_S62_given_command_is_MRMMRLL_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("RMFMMRB");
    const Pose target({6, 2, 'S'});
    ASSERT_EQ(target, executor->Query());
}

//"RMFMMRBFBL"
TEST(ExecutorlmplTest, should_return_facing_E63_given_command_is_MRMMRLL_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("RMFMMRBFBL");
    const Pose target({6, 3, 'E'});
    ASSERT_EQ(target, executor->Query());
}

//"RMFMMRBBRFB"
TEST(ExecutorlmplTest, should_return_facing_W73_given_command_is_MRMMRLL_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("RMFMMRBBRFB");
    const Pose target({7, 3, 'W'});
    ASSERT_EQ(target, executor->Query());
}

//"MRMMRLLFL"
TEST(ExecutorlmplTest, should_return_facing_N21_given_command_is_MRMMRLL_and_facing_is_N)
{
    std::unique_ptr<Executorlmpl> executorlmpl(Executorlmpl::NewExecutorlmpl({0, 0, 'N'}));
    executorlmpl->Execute("MRMMRLLFL");
    const Pose target({2, 2, 'W'});
    ASSERT_EQ(target, executorlmpl->Query());
}

//"FMMML"
TEST(ExecutorlmplTest, should_return_facing_N70_given_command_is_FMML_and_facing_is_E)
{
    std::unique_ptr<Executorlmpl> executorlmpl(Executorlmpl::NewExecutorlmpl({0, 0, 'E'}));
    executorlmpl->Execute("FMMML");
    const Pose target({7, 0, 'N'});  // 加速状态下，前进6格，然后左转
    ASSERT_EQ(target, executorlmpl->Query());
}

//"FMRML"
TEST(ExecutorlmplTest, should_return_facing_N33_given_command_is_FMRML_and_facing_is_N)
{
    std::unique_ptr<Executorlmpl> executorlmpl(Executorlmpl::NewExecutorlmpl({0, 0, 'N'}));
    executorlmpl->Execute("FMRML");
    const Pose target({3, 3, 'N'});  // 进入加速状态，前进2格然后右转，再前进2格左转，
    ASSERT_EQ(target, executorlmpl->Query());
}

//FMRMLFM
TEST(ExecutorTestlmpl, should_return_facing_Sn3n4_given_command_is_FMRML_and_facing_is_S)
{
    std::unique_ptr<Executorlmpl> executorlmpl(Executorlmpl::NewExecutorlmpl({0, 0, 'S'}));
    executorlmpl->Execute("FMRMLFM");
    const Pose target({-3, -4, 'S'});  // 进入加速状态，前进2格然后右转，再前进2格左转，取消加速状态，前进一格
    ASSERT_EQ(target, executorlmpl->Query());
}

//FMRMLFMRR
TEST(ExecutorlmplTest, should_return_facing_Nn3n4_given_command_is_FMRML_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    executor->Execute("FMRMLFMRR");
    const Pose target({-3, -4, 'N'});  // 进入加速状态，前进2格然后右转，再前进2格左转，取消加速状态，前进一格
    ASSERT_EQ(target, executor->Query());
}

//FMRMLFMFMR
TEST(ExecutorlmplTest, should_return_facing_Wn3n4_given_command_is_FMRML_and_facing_is_S)
{
    std::unique_ptr<Executorlmpl> executorlmpl(Executorlmpl::NewExecutorlmpl({0, 0, 'S'}));
    executorlmpl->Execute("FMRMLFMFMR");
    const Pose target({-3, -7, 'W'});  // 进入加速状态，前进2格然后右转，再前进2格左转，取消加速状态，前进一格
    ASSERT_EQ(target, executorlmpl->Query());
}

}