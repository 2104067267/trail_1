#include <gtest/gtest.h>
#include"Executor.h"
namespace adas
{
//"MRMMRLL"
TEST(ExecutorTest, should_return_facing_N21_given_command_is_MRMMRLL_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("MRMMRLLFL");
    const Pose target({2, 2, 'W'});
    ASSERT_EQ(target, executor->Query());
}

//"FMMML"
TEST(ExecutorTest, should_return_facing_N70_given_command_is_FMML_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    executor->Execute("FMMML");
    const Pose target({7, 0, 'N'});  // 加速状态下，前进6格，然后左转
    ASSERT_EQ(target, executor->Query());
}

//"FMRML"
TEST(ExecutorTest, should_return_facing_N33_given_command_is_FMRML_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("FMRML");
    const Pose target({3, 3, 'N'});  // 进入加速状态，前进2格然后右转，再前进2格左转，
    ASSERT_EQ(target, executor->Query());
}

//FMRMLFM
TEST(ExecutorTest, should_return_facing_Sn3n4_given_command_is_FMRML_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    executor->Execute("FMRMLFM");
    const Pose target({-3, -4, 'S'});  // 进入加速状态，前进2格然后右转，再前进2格左转，取消加速状态，前进一格
    ASSERT_EQ(target, executor->Query());
}

//FMRMLFMRR
TEST(ExecutorTest, should_return_facing_Nn3n4_given_command_is_FMRML_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    executor->Execute("FMRMLFMRR");
    const Pose target({-3, -4, 'N'});  // 进入加速状态，前进2格然后右转，再前进2格左转，取消加速状态，前进一格
    ASSERT_EQ(target, executor->Query());
}

//FMRMLFMFMR
TEST(ExecutorTest, should_return_facing_Wn3n4_given_command_is_FMRML_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    executor->Execute("FMRMLFMFMR");
    const Pose target({-3, -7, 'W'});  // 进入加速状态，前进2格然后右转，再前进2格左转，取消加速状态，前进一格
    ASSERT_EQ(target, executor->Query());
}



}