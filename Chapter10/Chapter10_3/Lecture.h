#pragma once

#include <vector>
#include "Student.h"
#include "Teacher.h"

class Lecture
{
private:
	std::string m_name;

	// �ּ� ó���� �͵��� composition���� § ��

	/*Teacher teacher;
	std::vector<Student> students;*/

	Teacher *teacher;
	std::vector<Student*> students;

public:
	Lecture(const std::string& name_in)
		: m_name(name_in)
	{}

	~Lecture()
	{
		// do NOT delete teacher
		// do NOT delete students
	}

	/*void assignTeacher(const Teacher& const teacher_input)
	{
		teacher = teacher_input;
	}*/

	void assignTeacher(Teacher* const teacher_input)
		// �ּҸ� �Ѱ��ִ� �Ŷ� const Teacher���� const�� ���� �Ѵ�
	{
		teacher = teacher_input;
	}

	//void registerStudent(const Student& const student_input)
	//{
	//	students.push_back(student_input);
	//	// &student_input != &students[0]
	//	// �����ؼ� �־��� ������ �ּҰ� �ٸ���
	//}

	void registerStudent(Student* const student_input)
	{
		students.push_back(student_input);
	}

	void study()
	{
		std::cout << m_name << " Study" << std::endl;
		
		//for (auto& element : students) //Note: 'auto element' doesn't work
		//	// &���� auto�� ����, ���� ������Ʈ�� �� ��
		//	element.setIntel(element.getIntel() + 1);

		for (auto element : students) //Note: 'auto element' works
		// �� ���� auto�� auto&�� �������
			(*element).setIntel((*element).getIntel() + 1);
			//element->setIntel(element->getIntel() + 1); �� �� ���� �ִ�
	}

	friend std::ostream& operator<< (std::ostream& out, const Lecture& lecture)
	{
		out << "Lecture name : " << lecture.m_name << std::endl;
		
		/*out << lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << element << std::endl;*/

		out << *lecture.teacher << std::endl;
		for (auto element : lecture.students)
			out << *element << std::endl;
		return out;
	}
};