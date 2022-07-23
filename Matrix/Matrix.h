#pragma once
#include <iostream>

using namespace std;

template<class T>
class Matrix
{
	T** arr = nullptr;
	int rows = 0;
	int columns = 0;

	void copy(const Matrix& m);
	void forDelete();

public:
	Matrix(int r = 0, int c = 0);
	~Matrix();
	Matrix(const Matrix& m);

	void set(T min = 0, T max = 9);
	void addRow(size_t pos, T* arr = nullptr);
	void delRow(int pos);
	void addColumn(int pos);
	void delColumn(int pos);
	void sortByRow();
	void transform();

	Matrix& operator = (const Matrix& m);
	template <class T> friend ostream& operator <<(ostream&, const Matrix<T>&);
	T*& operator [](int Array);
	Matrix operator + (const Matrix& m);
	Matrix operator*(int scalar);
};

template<class T>
void Matrix<T>::copy(const Matrix& m)
{
	rows = m.rows;
	columns = m.columns;
	arr = new T * [rows];
	for (size_t i = 0; i < rows; ++i)
	{
		arr[i] = new T[columns];
	}
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			arr[i][j] = m.arr[i][j];
		}
	}
}

template<class T>
void Matrix<T>::forDelete()
{
	for (size_t i = 0; i < rows; ++i)
	{
		delete[]this->arr[i];
	}
	delete[]this->arr;
}

template<class T>
Matrix<T>::Matrix(int r, int c)
{
	if (r > 0 && c > 0)
	{
		rows = r;
		columns = c;
		arr = new T * [rows];
		for (size_t i = 0; i < rows; ++i)
		{
			arr[i] = new T[columns];
		}
	}
	else
		return;
}

template<class T>
Matrix<T>::~Matrix()
{
	this->forDelete();
}

template<class T>
Matrix<T>::Matrix(const Matrix& m)
{
	copy(m);
}

template<class T>
void Matrix<T>::set(T min, T max)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			arr[i][j] = rand() % (max - min + 1) + min;
		}
	}
}

template<>
void Matrix<double>::set(double min, double max)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			arr[i][j] = round(((double)(rand()) / RAND_MAX * (max - min) + min) * 10) / 10;
		}
	}
}

template<>
void Matrix<char>::set(char min, char max)
{
	if (min == 0 && max == 9)
	{
		min = 'A';
		max = 'Z';
	}
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < columns; ++j)
		{
			arr[i][j] = rand() % (max - min + 1) + min;
		}
	}
}

template<class T>
void Matrix<T>::addRow(size_t pos, T* arr)
{
	T** tmp = new T * [rows + 1];
	if (arr != nullptr)
	{
		for (size_t i = 0; i < rows + 1; ++i)
		{
			tmp[i] = new T[columns]{};
		}

		for (size_t i = 0; i < columns; ++i)
		{
			tmp[pos][i] = arr[i];
		}

		for (size_t i = 0, k = 0; i < rows + 1; ++i)
		{
			if (i == pos)
			{
				continue;
			}
			for (size_t j = 0; j < columns; ++j)
			{
				tmp[i][j] = this->arr[k][j];
			}
			++k;
		}
	}
	else
	{
		for (size_t i = 0; i < rows + 1; ++i)
		{
			tmp[i] = new T[columns]{};
		}

		for (size_t i = 0, k = 0; i < rows + 1; ++i)
		{

			if (i == pos)
			{
				continue;
			}

			for (size_t j = 0; j < columns; ++j)
			{
				tmp[i][j] = this->arr[k][j];
			}
			++k;
		}
	}
	forDelete();
	++rows;
	this->arr = tmp;
}

template<class T>
void Matrix<T>::delRow(int pos)
{
	T** tmp = new T * [rows - 1];

	for (size_t i = 0, k = 0; i < rows - 1; ++k)
	{
		if (k == pos)
		{
			continue;
		}

		tmp[i] = new T[columns]{};

		for (size_t j = 0; j < columns; ++j)
		{
			tmp[i][j] = this->arr[k][j];
		}
		++i;
	}

	forDelete();
	--rows;
	arr = tmp;
}

template<class T>
void Matrix<T>::addColumn(int pos)
{
	T** tmp = new T * [rows]; 

	for (size_t i = 0; i < rows; i++)
	{
		tmp[i] = new T[columns + 1]{};
	}

	for (size_t i = 0; i < rows; i++)
	{

		for (size_t j = 0, k = 0; j < columns + 1; k++)
		{
			if (k == pos)
			{
				continue;
			}
			tmp[i][k] = this->arr[i][j];
			++j;
		}
	}

	forDelete();
	++columns;
	arr = tmp;
}

template<class T>
void Matrix<T>::delColumn(int pos)
{
	T** tmp = new T * [rows];

	for (size_t i = 0; i < rows; i++)
	{
		tmp[i] = new T[columns + 1]{};
	}

	for (size_t i = 0; i < rows; i++)
	{

		for (size_t j = 0, k = 0; j < columns - 1; k++)
		{
			if (k == pos)
			{
				continue;
			}
			tmp[i][j] = this->arr[i][k];
			++j;
		}
	}

	forDelete();
	--columns;
	arr = tmp;
}

template<class T>
void Matrix<T>::sortByRow()
{
	for (size_t k = 0; k < rows; k++)
	{
		T x;
		long i, j;

		for (i = 0; i < columns; i++) 
		{
			x = arr[k][i];

			for (j = i - 1; j >= 0 && arr[k][j] > x; j--)
			{
				arr[k][j + 1] = arr[k][j];
			}
		  
			arr[k][j + 1] = x;
		}
	}
	
}

template<class T>
void Matrix<T>::transform()
{
	T** tmp = new T * [columns];

	for (size_t i = 0; i < columns; ++i)
	{
		tmp[i] = new T[rows];
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			tmp[j][i] = arr[i][j];
		}
	}
	forDelete();
	int temp = rows;
	rows = columns;
	columns = temp;
	arr = tmp;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& m)
{
	this->forDelete();
	copy(m);
	return *this;
}

template<class T>
ostream& operator<<(ostream& out, const Matrix<T>& m)
{
	for (size_t i = 0; i < m.rows; ++i)
	{
		for (size_t j = 0; j < m.columns; ++j)
		{
			cout << m.arr[i][j] << "  ";
		}
		cout << "\n";
	}
	return out;
}

template<class T>
T*& Matrix<T>::operator[](int pointerOnArr)
{
	return arr[pointerOnArr];
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix& m)
{
	Matrix newMatrix(*this);
	if (rows == m.rows && columns == m.columns)
	{

		for (size_t i = 0; i < newMatrix.rows; ++i)
		{
			for (size_t j = 0; j < newMatrix.columns; ++j)
			{
				newMatrix.arr[i][j] += m.arr[i][j];
			}
		}
	}
	return newMatrix;
}

template<class T>
Matrix<T> Matrix<T>::operator*(int scalar)
{
	Matrix newMatrix(*this);

	for (size_t i = 0; i < newMatrix.rows; ++i)
	{
		for (size_t j = 0; j < newMatrix.columns; ++j)
		{
			newMatrix.arr[i][j] *= scalar;
		}
	}
	return newMatrix;
}
