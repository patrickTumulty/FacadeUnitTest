
#ifndef FACADE_HPP
#define FACADE_HPP

#include<iostream>
#include<algorithm>
#include<vector>
#include<memory>

struct User
{
    User(std::string UserName, std::string Password, bool IsExpired);

    std::string UserName;
    std::string Password;
    bool IsExpired;
};

class AbstractUserRepository
{
public:
    virtual std::vector<User> * GetUsers() = 0;

};

class UserRepository : public AbstractUserRepository
{
private:
    std::vector<User> * m_users;
public:
    UserRepository();
    virtual ~UserRepository();

    std::vector<User> * GetUsers();

};

class UserService
{
public:
    std::vector<User> * GetUsersWithExpiredPassword(std::vector<User> * users);
    void SetUserPassword(User *user, std::string newPassword);

private:

};

class Facade
{
private:
    std::shared_ptr<AbstractUserRepository> m_userRepo;
    UserService * m_userService;
public:
    Facade(std::shared_ptr<AbstractUserRepository> userRepository);
    ~Facade();
    
    void SetExpiredPasswordsToDefault();
    std::shared_ptr<AbstractUserRepository> getUserRepo();


};

#endif