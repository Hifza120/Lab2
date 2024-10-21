#include<iostream>
using namespace std;
class Employee{
public:
virtual	double calculateSalary() = 0;
};
class  FullTimeEmployee : public Employee{
	double Salary;
public:
	FullTimeEmployee(double S) :Salary(S){}
	void setSalary(double Sal){
		this->Salary = Sal;
	}
	double getSalary()const{
		return Salary;
	}
	double calculateSalary(){
		return Salary;
	}
};
class  PartTimeEmployee : public Employee {
	double hours_Worked;
	double hourly_rate;
public:
	PartTimeEmployee(double hourlyRate, double hourWorked) :hourly_rate(hourlyRate), hours_Worked(hourWorked){

	}
	double getHoursworked()const{
		return hours_Worked;
	}
	double  getHourlyrate()const{
		return  hourly_rate;
	}
	void setHoursworked(double  hoursworked){
		this->hours_Worked = hoursworked;
	}
	void setHourlyrate(double  hourlyRate){
		this->hourly_rate = hourlyRate;
	}
	double calculateSalary(){
		return hourly_rate*hours_Worked;
	}
};
int main(){
	Employee *E;
	FullTimeEmployee e1(20000);
	E = &e1;
	cout << " full Time Empolyee Salary   : ";
	cout << E->calculateSalary();
	cout << endl;
	Employee *P;
	PartTimeEmployee  e2(200, 40);
	P = &e2;
cout << " PART Time Empolyee Salary   : ";
cout<<P->calculateSalary();
cout << endl;


	return 0;
}