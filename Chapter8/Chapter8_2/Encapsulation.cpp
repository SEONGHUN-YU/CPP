#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
	// access specifier : private�� �⺻�������� �Ǿ� �ִ�
	int m_month;
	int m_day;
	int m_year;

public:
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}

	void setMonth(const int& month_input)
	{
		m_month = month_input;
	}

	void setDay(const int& day_input)
	{
		m_day = day_input;
	}

	void setYear(const int& year_input) // setter
	{
		m_year = year_input;
	}

	int getMonth() // getter
	{
		return m_month;
	}

	int getDay() // ���簡 �Ǵϱ� �޸������� �� ���ٰ� �����ż� ref�� return �Ϸ��� ��찡 �ִµ�
	{
		return m_day;
	}

	const int& getYear() // ref�� ���� ���� �ٲ� �� ���� const��
	{
		return m_year;
	}

	void copyFrom(const Date& original)
	{
		m_month = original.m_month;
		m_day = original.m_day;
		m_year = original.m_year;
	}
};

int main()
{
	Date today; //{ 8,4,2025 };
	/*today.m_month = 8;
	today.m_day = 4;
	today.m_year = 2025;*/
	today.setDate(8, 4, 2025);
	today.setMonth(10);
	cout << today.getDay() << endl;

	Date copy;
	copy.copyFrom(today);

	return 0;
}