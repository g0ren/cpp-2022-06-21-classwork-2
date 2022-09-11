#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Observer {
public:
	virtual void handleEvent(string) = 0;
	virtual ~Observer() {
	}
};

class Person: public Observer {
public:
	string name, surname;
	Person(string _surname, string _name) {
		name = _name;
		surname = _surname;
	}
	void handleEvent(string notification) {
		cout << "Dear " << surname << ' ' << name << '\t' << endl;
		cout << notification << endl;
	}
};

class Employer: public Observer {
public:
	string name, surname, organization;
	Employer(string surname, string name, string organization) :
			surname(surname), name(name), organization(organization) {
	}
	void handleEvent(string notification) {
		cout << "Dear " << surname << ' ' << name << " from " << organization
				<< '\t' << endl;
		cout << notification << endl;
	}
};

class Observable {
public:
	virtual void addObserver(Observer *observer) = 0;
	virtual void removeObserver() = 0;
	virtual void Notification(string notification) = 0;
	virtual ~Observable() {
	}
};

class HH: public Observable {
public:
	vector<Observer*> staff;
	vector<Observer*> employers;
	vector<string> vacancy;

	void addEmployer(Employer *observer) {
		employers.push_back(observer);
	}

	void addObserver(Person *observer) {
		staff.push_back(observer);
		for (auto &person : employers) {
			person->handleEvent("New candidate: "+observer->surname+" "+observer->name);
		}
	}

	void removeObserver() {
		staff.erase(staff.begin() + rand() % staff.size());
	}

	void Notification(string notification) {
		for (auto &person : staff) {
			person->handleEvent(notification);
		}
	}
	void addVacancy(string vacancy) {
		this->vacancy.push_back(vacancy);
		Notification(
				"Open NEW vacancy on HH: " + vacancy
						+ "\tclick to more info...");
	}

	void removeVacancy() {
		vector<string>::iterator it = vacancy.begin() + rand() % vacancy.size();
		Notification(
				"Vacancy " + *it
						+ " find yoursefl lucky(\tclick to look other vacancy...");
		vacancy.erase(it);
	}

};

int main() {

}
