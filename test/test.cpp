#include <iostream>
#include "../src/Facade.hpp"
#include <gtest/gtest.h>



TEST(PASSWORDRESET1, correctPassword)
{
    std::shared_ptr<UserRepository> u = std::make_shared<UserRepository>();
    Facade * f = new Facade(u);
    f->SetExpiredPasswordsToDefault();
    std::shared_ptr<AbstractUserRepository> repo = f->getUserRepo();
    ASSERT_EQ("supersecret", repo->GetUsers()->at(0).Password);
    ASSERT_EQ("default_password", repo->GetUsers()->at(1).Password);
}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}