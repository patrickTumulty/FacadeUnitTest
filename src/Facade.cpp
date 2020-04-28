#include<iostream>
#include<algorithm>
#include<vector>
#include<memory>
#include"Facade.hpp"

User::User(std::string UserName, std::string Password, bool IsExpired)
{
    this->UserName = UserName;
    this->Password = Password;
    this->IsExpired = IsExpired;
}

UserRepository::UserRepository()
{
    this->m_users = new std::vector<User>();
    this->m_users->push_back(User("Steve", "supersecret", false));
    this->m_users->push_back(User("Roger", "notsosecret", true));
}

UserRepository::~UserRepository()
{
    delete this->m_users;
}

std::vector<User> * UserRepository::GetUsers()
{
    return this->m_users;
}


std::vector<User> * UserService::GetUsersWithExpiredPassword(std::vector<User> * users)
{
    std::vector<User> * usersWithExpiringPasswords = new std::vector<User>();
    for(auto u : *users)
    {
      if(u.IsExpired)
      {
        usersWithExpiringPasswords->push_back(u);
      }
    }
    return usersWithExpiringPasswords;
}

void UserService::SetUserPassword(User *user, std::string newPassword)
{
    user->Password = newPassword;
}

Facade::Facade(std::shared_ptr<AbstractUserRepository> userRepository)
{
    this->m_userRepo = userRepository;
    this->m_userService = new UserService();
}

Facade::~Facade()
{
    delete this->m_userService;
}

void Facade::SetExpiredPasswordsToDefault()
{
    int length = this->m_userRepo->GetUsers()->size();
    for (int i = 0; i < length; i++)
    {
        if (this->m_userRepo->GetUsers()->at(i).IsExpired == true)
        {
            this->m_userRepo->GetUsers()->at(i).Password = "default_password";
        }
    }
}

std::shared_ptr<AbstractUserRepository> Facade::getUserRepo()
{
    return this->m_userRepo;
}