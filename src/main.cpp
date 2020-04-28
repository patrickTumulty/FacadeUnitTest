
// #include <bits/c++config.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<memory>

#include "Facade.hpp"
//facade
// struct User
// {
//   std::string UserName;
//   std::string Password;
//   bool IsExpired;

//   User(std::string UserName, std::string Password, bool IsExpired)
//   {
//     this->UserName = UserName;
//     this->Password = Password;
//     this->IsExpired = IsExpired;
//   }
// };

// class AbstractUserRepository
// {
// public:
//   virtual std::vector<User> * GetUsers() = 0;
// };    

// class UserRepository : public AbstractUserRepository
// {
// private:
//   std::vector<User> * m_users;
// public:
//   std::vector<User> *GetUsers() { return this->m_users; }

//   UserRepository()
//   {
//     this->m_users = new std::vector<User>();
//     this->m_users->push_back(User("Steve", "hunter2", false));
//     this->m_users->push_back(User("Paul", "supersecret", true));
//   }

//   ~UserRepository()
//   {
//     delete this->m_users;
//   }
// };

// class UserService
// {
// public:
//   std::vector<User> * GetUsersWithExpiredPassword(std::vector<User> * users)
//   {
//     std::vector<User> * usersWithExpiringPasswords = new std::vector<User>();
//     for(auto u : *users)
//     {
//       if(u.IsExpired)
//       {
//         usersWithExpiringPasswords->push_back(u);
//       }
//     }
//     return usersWithExpiringPasswords;
//   }

//   void SetUserPassword(User *user, std::string newPassword)
//   {
//     user->Password = newPassword;
//   }
// };


// class Facade
// {
// private:
//   std::shared_ptr<AbstractUserRepository> m_userRepo;
//   UserService * m_userService;
// public:
//   Facade(std::shared_ptr<AbstractUserRepository> userRepository)
//   {
//     this->m_userRepo = userRepository;
//     this->m_userService = new UserService();
//   }

//   ~Facade()
//   {
//     delete this->m_userService;
//   }

//   void SetExpiredUsersPasswordsToDefault()
//   {
//     std::vector<User> *users = this->m_userRepo.get()->GetUsers();

//     std::vector<User> *usersWithExpiringPasswords = this->m_userService->GetUsersWithExpiredPassword(users);

//     for(auto u : *usersWithExpiringPasswords)
//     {
//       this->m_userService->SetUserPassword(&u, "hunter2");
//     }
//   }
// };    


int main() 
{
  std::shared_ptr<UserRepository> u = std::make_shared<UserRepository>();
  Facade * f = new Facade(u);
  f->SetExpiredPasswordsToDefault();
  std::shared_ptr<AbstractUserRepository> repo = f->getUserRepo();
  int length =  repo->GetUsers()->size();
  for (int i = 0; i < length; i++)
  {
    std::cout << repo->GetUsers()->at(i).UserName << std::endl;
  }



}