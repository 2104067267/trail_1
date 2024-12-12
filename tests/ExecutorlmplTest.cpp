#include"Executorlmpl.h"
#include<gtest/gtest.h>

namespace adas{

//测试跑车： 前进、转弯、加速、后退功能（自己加的）,兼容需求功能。
//pose中 car 0：普通车  1:跑车  2; bus

//测试跑车需求前进功能
TEST(ExecutorlmplTest,sportscarM)
{
  std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',1,2,1,0}));
  executor->Execute("MMLMR");
  const Pose target({-3, 5, 'N',1,2,1,0});
  ASSERT_EQ(target, executor->Query());
}

//测试跑车需求转弯功能
TEST(ExecutorlmplTest,sportscarT)
{
  std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',1,2,1,0}));
  executor->Execute("LRLRR");
  const Pose target({-1, 2, 'E',1,2,1,1});
  ASSERT_EQ(target, executor->Query());
}

//测试跑车需求加速功能
//跑车 非加速：与需求一致。 加速下：M:前进三格，转弯：先转，再前进俩格
TEST(ExecutorlmplTest, sportscarF)
{
  std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',1,2,1,0}));
  executor->Execute("MMLFMRF");
  const Pose target({-4, 6, 'N',1,2,1,0});
  ASSERT_EQ(target, executor->Query());
}

//测试跑车需求后退功能
//加速下：后退3格；非加速：后退俩格
TEST(ExecutorlmplTest, sportscarB)
{
  std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',1,2,1,0}));
  executor->Execute("MMLFMRFBFB");
  const Pose target({-4, 1, 'N',1,3,1,0});
  ASSERT_EQ(target, executor->Query());
}



//测试bus： 前进、转弯、加速、后退功能（自己加的）,兼容需求功能。
//测试bus需求前进功能
TEST(ExecutorlmplTest,busM)
{
    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',2,1,2,0}));
    executor->Execute("MMLMR");
    const Pose target({-2, 3, 'N',2,1,2,0});
    ASSERT_EQ(target, executor->Query());
}

//测试bus需求转弯功能
TEST(ExecutorlmplTest,busT)
{
    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',2,1,2,0}));
    executor->Execute("LRLRR");
    const Pose target({-2, 3, 'E',2,1,2,1});
    ASSERT_EQ(target, executor->Query());
}

//测试bus需求加速功能
//bus 非加速：与需求一致。 加速速度为2 ：M:前进2格，  转弯：只转弯
TEST(ExecutorlmplTest, busF)
{
    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',2,1,2,0}));
    executor->Execute("MMLFMRF");
    const Pose target({-2, 3, 'N',2,1,2,0});
    ASSERT_EQ(target, executor->Query());
}

//测试bus需求后退功能
//加速下：后退2格；非加速：后退1格
TEST(ExecutorlmplTest, busB)
{
    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',2,1,2,0}));
    executor->Execute("MMLFMRFBFB");
    const Pose target({-2, 0, 'N',2,2,2,0});
    ASSERT_EQ(target, executor->Query());
}




//一般汽车功能
//"RMFB"
TEST(ExecutorlmplTest, should_return_facing_S52_given_command_is_MRMMRLL_and_facing_is_N)
{
    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',0,1,1,0}));
    executor->Execute("RMFMMRB");
    const Pose target({6, 2, 'S',0,2,1,2});
    ASSERT_EQ(target, executor->Query());
}

//"RMFB"
TEST(ExecutorlmplTest, should_return_facing_En10_given_command_is_MRMMRLL_and_facing_is_N)
{
    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',0,1,1,0}));
    executor->Execute("RMFB");
    const Pose target({-1, 0, 'E',0,2,1,1});
    ASSERT_EQ(target, executor->Query());
}

//"MRMMRLL"
TEST(ExecutorlmplTest, should_return_facing_N21_given_command_is_MRMMRLL_and_facing_is_N)
{
    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',0,1,1,0}));
    executor->Execute("MRMMRLLFL");
    const Pose target({2, 2, 'W',0,2,1,3});
    ASSERT_EQ(target, executor->Query());
}

//"FMMML"
TEST(ExecutorlmplTest, should_return_facing_N70_given_command_is_FMML_and_facing_is_E)
{
    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'E',0,1,1,1}));
    executor->Execute("FMMML");
    const Pose target({7, 0, 'N',0,2,1,0});  // 加速状态下，前进6格，然后左转
    ASSERT_EQ(target, executor->Query());
}

//"FMRML"
TEST(ExecutorlmplTest, should_return_facing_N33_given_command_is_FMRML_and_facing_is_N)
{
    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',0,1,1,0}));
    executor->Execute("FMRML");
    const Pose target({3, 3, 'N',0,2,1,0});  // 进入加速状态，前进2格然后右转，再前进2格左转，
    ASSERT_EQ(target, executor->Query());
}

//FMRMLFM
TEST(ExecutorlmplTest, should_return_facing_Sn3n4_given_command_is_FMRML_and_facing_is_S)
{
    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'S',0,1,1,2}));
    executor->Execute("FMRMLFM");
    const Pose target({-3, -4, 'S',0,1,1,2});  // 进入加速状态，前进2格然后右转，再前进2格左转，取消加速状态，前进一格
    ASSERT_EQ(target, executor->Query());
}

//FMRMLFMRR
TEST(ExecutorlmplTest, should_return_facing_Nn3n4_given_command_is_FMRML_and_facing_is_S)
{
    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'S',0,1,1,2}));
    executor->Execute("FMRMLFMRR");
    const Pose target({-3, -4, 'N',0,1,1,0});  // 进入加速状态，前进2格然后右转，再前进2格左转，取消加速状态，前进一格
    ASSERT_EQ(target, executor->Query());
}

//FMRMLFMFMR
TEST(ExecutorlmplTest, should_return_facing_Wn3n4_given_command_is_FMRML_and_facing_is_S)
{
    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'S',0,1,1,2}));
    executor->Execute("FMRMLFMFMR");
    const Pose target({-3, -7, 'W',0,2,1,3});  // 进入加速状态，前进2格然后右转，再前进2格左转，取消加速状态，前进一格
    ASSERT_EQ(target, executor->Query());
}





}
//
////"RMFB"
//TEST(ExecutorlmplTest, should_return_facing_W40_given_command_is_MRMMRLL_and_facing_is_N)
//{
//    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N',0,1,1,3}));
//    executor->Execute("RMFRRBFB");
//    const Pose target({5, -1, 'W',0,1,1,3});
//    ASSERT_EQ(target, executor->Query());
//}
//
////"RMFMMRB"
//TEST(ExecutorlmplTest, should_return_facing_S62_given_command_is_MRMMRLL_and_facing_is_N)
//{
//    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N'}));
//    executor->Execute("RMFMMRB");
//    const Pose target({6, 2, 'S'});
//    ASSERT_EQ(target, executor->Query());
//}
//
////"RMFMMRBFBL"
//TEST(ExecutorlmplTest, should_return_facing_E63_given_command_is_MRMMRLL_and_facing_is_N)
//{
//    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N'}));
//    executor->Execute("RMFMMRBFBL");
//    const Pose target({6, 3, 'E'});
//    ASSERT_EQ(target, executor->Query());
//}
//
////"RMFMMRBBRFB"
//TEST(ExecutorlmplTest, should_return_facing_W73_given_command_is_MRMMRLL_and_facing_is_N)
//{
//    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'N'}));
//    executor->Execute("RMFMMRBBRFB");
//    const Pose target({7, 3, 'W'});
//    ASSERT_EQ(target, executor->Query());
//}
//
////"MRMMRLLFL"
//TEST(ExecutorlmplTest, should_return_facing_N21_given_command_is_MRMMRLL_and_facing_is_N)
//{
//    std::unique_ptr<Executorlmpl> executorlmpl(Executorlmpl::NewExecutorlmpl({0, 0, 'N'}));
//    executorlmpl->Execute("MRMMRLLFL");
//    const Pose target({2, 2, 'W'});
//    ASSERT_EQ(target, executorlmpl->Query());
//}
//
////"FMMML"
//TEST(ExecutorlmplTest, should_return_facing_N70_given_command_is_FMML_and_facing_is_E)
//{
//    std::unique_ptr<Executorlmpl> executorlmpl(Executorlmpl::NewExecutorlmpl({0, 0, 'E'}));
//    executorlmpl->Execute("FMMML");
//    const Pose target({7, 0, 'N'});  // 加速状态下，前进6格，然后左转
//    ASSERT_EQ(target, executorlmpl->Query());
//}
//
////"FMRML"
//TEST(ExecutorlmplTest, should_return_facing_N33_given_command_is_FMRML_and_facing_is_N)
//{
//    std::unique_ptr<Executorlmpl> executorlmpl(Executorlmpl::NewExecutorlmpl({0, 0, 'N'}));
//    executorlmpl->Execute("FMRML");
//    const Pose target({3, 3, 'N'});  // 进入加速状态，前进2格然后右转，再前进2格左转，
//    ASSERT_EQ(target, executorlmpl->Query());
//}
//
////FMRMLFM
//TEST(ExecutorTestlmpl, should_return_facing_Sn3n4_given_command_is_FMRML_and_facing_is_S)
//{
//    std::unique_ptr<Executorlmpl> executorlmpl(Executorlmpl::NewExecutorlmpl({0, 0, 'S'}));
//    executorlmpl->Execute("FMRMLFM");
//    const Pose target({-3, -4, 'S'});  // 进入加速状态，前进2格然后右转，再前进2格左转，取消加速状态，前进一格
//    ASSERT_EQ(target, executorlmpl->Query());
//}
//
////FMRMLFMRR
//TEST(ExecutorlmplTest, should_return_facing_Nn3n4_given_command_is_FMRML_and_facing_is_S)
//{
//    std::unique_ptr<Executorlmpl> executor(Executorlmpl::NewExecutorlmpl({0, 0, 'S'}));
//    executor->Execute("FMRMLFMRR");
//    const Pose target({-3, -4, 'N'});  // 进入加速状态，前进2格然后右转，再前进2格左转，取消加速状态，前进一格
//    ASSERT_EQ(target, executor->Query());
//}
//
////FMRMLFMFMR
//TEST(ExecutorlmplTest, should_return_facing_Wn3n4_given_command_is_FMRML_and_facing_is_S)
//{
//    std::unique_ptr<Executorlmpl> executorlmpl(Executorlmpl::NewExecutorlmpl({0, 0, 'S'}));
//    executorlmpl->Execute("FMRMLFMFMR");
//    const Pose target({-3, -7, 'W'});  // 进入加速状态，前进2格然后右转，再前进2格左转，取消加速状态，前进一格
//    ASSERT_EQ(target, executorlmpl->Query());
//}
