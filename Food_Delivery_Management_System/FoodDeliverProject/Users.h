using namespace std;
class User
{
        public:
          string UserName;
          string Password;
          bool IsAdmin;
};
class Users
{
public:
	bool IsAdmin=false;
	bool LoginSuccess=false;
	string UserName;
	User users[100];
	int UsersCount=0;
	Users();
        bool Login(string username,string password);
	void SignUp();
	void LoginWithRetrys();

};

