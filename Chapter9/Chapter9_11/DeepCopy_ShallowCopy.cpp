#include <iostream>
#include <cassert>

using namespace std;

class MyString
{
public:
	char* m_data = nullptr;
	int m_length = 0;

public:
	MyString(const char* source = "")
	{
		assert(source);

		m_length = std::strlen(source) + 1; // null character �߰��� ���� 1ĭ �߰�
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	//MyString(const MyString& source) = delete; ���� �����ڸ� ���ƹ����� ����� ����, �ٸ� ����å���� ���� ��

	MyString(const MyString& source) // ���� ������
	{
		cout << "Copy constructor " << endl;

		m_length = source.m_length;
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];
			for (int i = 0; i < m_length; ++i) // ���� �����ϴ� ��
				m_data[i] = source.m_data[i];
		}
		else m_data = nullptr; // ������� �⺻������ �־����, �� �κ��� ��� ũ�� ������ ���� ������ �־��
	}

	MyString& operator= (const MyString& source) // �Ҵ� ������ �����ε�
	{
		// copy constructor�� ���� �ڵ尡 default�� <- shallow copy�� ������ ���� �� ����
		/*this->m_data = source.m_data;
		this->m_length = source.m_length;*/

		cout << "Assignment operator " << endl;

		if (this == &source) // prevent self-assignment
			return *this;
		delete[] m_data; // ���� �������� ���� ���� �����ϴ� �Ŵϱ� ������ �� ����µ�
		// �Ҵ� �������� ��� ���� �ּҸ� ������ ���� �� �ֱ� ������
		// ������ ���� �� �־ �ϴ� �����, �ּҸ� �ٽ� �����

		m_length = source.m_length;
		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];
			for (int i = 0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else m_data = nullptr;
	}

	~MyString()
	{
		delete[] m_data;
	}
	
	char* getString() { return m_data; }
	int getLength() { return m_length; }
};

int main()
{
	MyString hello("Hello");
	cout << (int*)hello.m_data << endl;
	cout << hello.getString() << endl;

	{
		MyString copy = hello; // ���� ����
		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
	} // �� �������� ���纻�� ������ heap �޸𸮸� ��������, ����(������)�� �����鼭 �Ҹ��ڰ� �ߵ��ϱ� ����

	cout << hello.getString() << endl; // ������ �޸𸮿� �����Ϸ� �ϴ�, �����Ⱚ�� ����

	MyString str = hello; // ����� ���ÿ� �ʱ�ȭ�ϸ� ������ ����, ���� ������ �ߵ�
	MyString str2; // �⺻ ������ �ߵ�
	str2 = hello; // �Ҵ� ������ �ߵ�

	return 0;
}