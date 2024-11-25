#include <gtest/gtest.h>
#include"Executor.h"
namespace adas
{
//"MRMMRLL"
TEST(ExecutorTest,should_return_facing_N21_given_command_is_RMRM_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("MRMMRLL");
    const Pose target({2, 1, 'N'});
    ASSERT_EQ(target, executor->Query());
}

//"RMRMMLLR"
TEST(ExecutorTest,should_return_facing_E1n2_given_command_is_RMRM_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("RMRMMLLR");
    const Pose target({1, -2, 'E'});
    ASSERT_EQ(target, executor->Query());
}

//"MMRMMRLRLL"
TEST(ExecutorTest,should_return_facing_N22_given_command_is_RMRM_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("MMRMMRLRLL");
    const Pose target({2, 2, 'N'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
{                                                                        //参数初始化列表
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("L");
    const Pose target({0, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest,should_return_facing_E_given_command_is_R_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("R");
    const Pose target({0, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_facing_N_given_command_is_L_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    executor->Execute("L");
    const Pose target({0, 0,'N'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'S'}));
    executor->Execute("L");
    const Pose target({0, 0,'E'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest,should_return_facing_S_given_command_is_R_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    executor->Execute("R");
    const Pose target({0, 0, 'N'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest,should_return_0_1_given_command_is_M_and_facing_is_N)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'N'}));
    executor->Execute("M");
    const Pose target({0, 1, 'N'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest,should_return_n1_0_given_command_is_M_and_facing_is_W)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'W'}));
    executor->Execute("M");
    const Pose target({-1, 0, 'W'});
    ASSERT_EQ(target, executor->Query());
}

TEST(ExecutorTest,should_return_1_0_given_command_is_M_and_facing_is_E)
{
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));
    executor->Execute("M");
    const Pose target({1, 0, 'E'});
    ASSERT_EQ(target, executor->Query());
}


}
