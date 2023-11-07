#include <iostream>
#include <string>
#include <ctime>

using std::cout;
using std::cin;

class Person
{
protected:
	std::string firstname;
	std::string lastname;
	std::tm birthday;
	std::string phoneNumber;
public:
	Person() {}
	Person(std::string _lastname, std::string _firstname) :
		lastname(_lastname), firstname(_firstname)
	{
		setBirthday();
		setPhoneNumber();
	}

	void setFullName() // установка сразу полного имени
	{
		cout << "Enter your First Name :" << std::endl;
		std::getline(cin, firstname);
		cout << "Enter your Last Name :" << std::endl;
		std::getline(cin, lastname);
	}

	std::string getFirstName()
	{
		return firstname;
	}

	std::string getLastName()
	{
		return lastname;
	}

	void setBirthday() // установка даты рождения
	{
		int birthDay;
		int birthMonth;
		int birthYear;

		cout << "Enter your date of birth (example 01.01.2000): " << std::endl;
		cin >> birthDay;
		cin.ignore();
		cin >> birthMonth;
		cin.ignore();
		cin >> birthYear;

		birthday.tm_year = birthYear - 1900;
		birthday.tm_mon = birthMonth - 1;
		birthday.tm_mday = birthDay;
	}
	std::string getBirthday() const //возвращение даты рождения в string
	{
		char bday[100];
		std::strftime(bday, 100, "%d.%m.%Y", &birthday);
		return std::string(bday);
	}

	void setPhoneNumber() // установка номера телефона из 10 чисел
	{
		do
		{
			cout << "Enter your phone number (exemple 067*******) : " << std::endl;
			cin.ignore();
			std::getline(cin, phoneNumber);
			if (phoneNumber.length() != 10)
			{
				cout << " Incorrect phone number!\n Phone number must contain 10 digits!" << std::endl;
				cout << std::endl;
			}
		} while (phoneNumber.length() != 10);
	}

	std::string getPhoneNumber() 
	{
		return phoneNumber;
	}
};

class JobStats
{
protected:
	std::string previousWork;
	std::tm startPrevWorkingDate;
	std::tm endedWorkingDate;
	double payPerHour = 0;
public:
	JobStats() {}
	JobStats(std::string prevWork, double _payPerHour) :
		previousWork(prevWork), payPerHour(_payPerHour)
	{
		setStartPrevWorkDate();
		setEndedWorkingDate();
	}
	void setpreviousWork() // установка названия места предыдущей работы
	{
		cout << "Write what was your last job :" << std::endl;
		std::getline(cin, previousWork);
	}
	
	std::string getPreviusWork()
	{
		return previousWork;
	}

	void setStartPrevWorkDate() // дата трудоустройства на предыдущую работу
	{
		int* prevWorkDay = new int;
		int* prevWorkMonth = new int;
		int* prevWorkYear = new int;

		cout << "Write the date when you started working at your previous place (example 01.01.2000): " << std::endl;
		cin >> *prevWorkDay;
		cin.ignore();
		cin >> *prevWorkMonth;
		cin.ignore();
		cin >> *prevWorkYear;

		startPrevWorkingDate.tm_year = *prevWorkYear - 1900;
		startPrevWorkingDate.tm_mon = *prevWorkMonth - 1;
		startPrevWorkingDate.tm_mday = *prevWorkDay;

		delete prevWorkDay;
		delete prevWorkMonth;
		delete prevWorkYear;
	}

	std::string getStartPrevWorkDate() const
	{
		char stPrevWork[100];
		std::strftime(stPrevWork, 100, "%d.%m.%Y", &startPrevWorkingDate);
		return std::string(stPrevWork);
	}

	void setEndedWorkingDate() // дата увольнения с предыдущей работы
	{
		int* prevEndWorkDay = new int;
		int* prevEndWorkMonth = new int;
		int* prevEndWorkYear = new int;

		cout << "Write the date when you ended working at your previous place (example 01.01.2000): " << std::endl;
		cin >> *prevEndWorkDay;
		cin.ignore();
		cin >> *prevEndWorkMonth;
		cin.ignore();
		cin >> *prevEndWorkYear;

		endedWorkingDate.tm_year = *prevEndWorkYear - 1900;
		endedWorkingDate.tm_mon = *prevEndWorkMonth - 1;
		endedWorkingDate.tm_mday = *prevEndWorkDay;

		delete prevEndWorkDay;
		delete prevEndWorkMonth;
		delete prevEndWorkYear;
	}

	std::string getEndedPrevWorkingDate() const
	{
		char endPrevWork[100];
		std::strftime(endPrevWork, 100, "%d.%m.%Y", &endedWorkingDate);
		return std::string(endPrevWork);
	}

	void setPayPerHour() //почасовая оплата на предыдущей работе
	{
		cout << "How much did you earn per hour at your previous job?" << std::endl;
		cin >> payPerHour;
	}

	double getPayPerHour()
	{
		return payPerHour;
	}
};

class Programmer : public Person, public JobStats
{
protected:
	bool javaSkill;
	std::string javaCompay;
	std::tm javaStart;

	bool cppSkill;
	std::string cppCompany;
	std::tm cppStart;
public:
	Programmer() {}
	Programmer(std::string lastname, std::string firstname, std::string prevWork, double _payPerHour, bool java, bool cpp) :
		Person(lastname, firstname), JobStats(prevWork, _payPerHour), javaSkill(java), cppSkill(cpp)
	{
		setJavaDescription();
		setCPPDescription();
	}

	void setBoolJavaSkill() //Запись статистики
	{
		cout << "Do you have experience with Java? " << std::endl;
		cout << "Type 1 if you have,or type 0 if you don't" << std::endl;
		cin >> javaSkill;
		if (javaSkill == true) setJavaDescription();
		else return;
	}

	void setJavaDescription() //Установка дополнительных сведений если скилл == тру
	{
		if (javaSkill == false)
		{
			cout << "This person do not have experience with Java" << std::endl;
			return;
		}
		else
		{
			cout << "When did you statr learning Java (only year) :" << std::endl; // запись начала изучения скила

			int* yearStartSkill = new int;

			cin.ignore();
			cin >> *yearStartSkill;

			javaStart.tm_year = *yearStartSkill - 1900;
			javaStart.tm_mon = 0;
			javaStart.tm_mday = 0;
			javaStart.tm_hour = 0;
			javaStart.tm_min = 0;

			delete yearStartSkill;

			cout << "Type where did you work with Java (company name):" << std::endl; // Название компании где работали на Java
			cin.ignore();
			std::getline(cin, javaCompay);

		}
	}

	void printJavaStats() //Вывод статистики по Java
	{
		if (javaSkill == true)
		{
			int javaYear = javaStart.tm_year + 1900;

			cout << std::endl;
			cout << "This person started learning Java in: " << javaYear << std::endl;
			cout << "Previously worked in: " << javaCompay << std::endl;

		}
		else cout << "This person do not have experience with Java" << std::endl;

	}

	void setBoolCPPSkill()
	{
		cout << "Do you have experience with C++? " << std::endl;
		cout << "Type 1 if you have,or type 0 if you don't" << std::endl;
		cin >> cppSkill;
		if (cppSkill == true) setCPPDescription();
		else return;
	}

	void setCPPDescription() //Установка дополнительных сведений если скилл == тру
	{
		if (cppSkill == false)
		{
			cout << "This person do not have experience with Java" << std::endl;
			return;
		}
		else
		{
			cout << "When did you statr learning C++ (only year) :" << std::endl; // запись начала изучения скила

			int* yearStartSkill = new int;

			cin >> *yearStartSkill;

			cppStart.tm_year = *yearStartSkill - 1900;
			cppStart.tm_mon = 0;
			cppStart.tm_mday = 0;
			cppStart.tm_hour = 0;
			cppStart.tm_min = 0;

			delete yearStartSkill;

			cout << "Type where did you work with C++ (company name):" << std::endl; // Название компании где работали на C++
			cin.ignore();
			std::getline(cin, cppCompany);

		}
	}

	void printCPPStats() //Вывод статистики по с++
	{
		if (cppSkill == true)
		{
			int cppYear = cppStart.tm_year + 1900;

			cout << std::endl;
			cout << "This person started learning C++ in: " << cppYear << std::endl;
			cout << "Previously worked in: " << cppCompany << std::endl;

		}
	}

	void alloutStat()  //Вывод полной статистики со всех базовыйх класов + данного класса
	{
		cout << std::endl;
		cout << "Full name: " << getLastName() << " " << getFirstName() << std::endl;
		cout << "Birthday: " << getBirthday() << std::endl;
		cout << "Phone number: +38" << getPhoneNumber() << std::endl;
		cout << std::endl;
		cout << "Previus work: " << getPreviusWork() << std::endl;
		cout << "Previus work start date: " << getStartPrevWorkDate() << std::endl;
		cout << "Previus work end date: " << getEndedPrevWorkingDate() << std::endl;
		cout << "Previus work pay per hour: " << getPayPerHour() << std::endl;
		cout << std::endl;
		printJavaStats();
		printCPPStats();

	}
};

int main()
{
	system("chcp 1251");

	// После вызвоа этой строки будет вызвано довольно много функций в которых прийдется записивать данные в ручную 
	// Построение одного конструтора для общего для всех базовых и производного класса было бы плохой идеей
	// Так как запись всех параметров разтянулась бы в одну очень большую строку

	Programmer vasa("Korolov", "Vasily", "Kingston.inc", 250, 0, 1);

	vasa.alloutStat();

	return 0;
}