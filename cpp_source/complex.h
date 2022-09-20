#ifndef Complex_h
#define Complex_h

#include <iostream>
class complex{
public:
    complex(double real = 0.0, double imag = 0.0): m_real(real), m_imag(imag){ };
public:
    friend complex operator+(const complex & A, const complex & B);
    friend complex operator-(const complex & A, const complex & B);
    friend complex operator*(const complex & A, const complex & B);
    friend complex operator/(const complex & A, const complex & B);
    friend std::istream & operator>>(std::istream & in, complex & A);
    friend std::ostream & operator<<(std::ostream & out, complex & A);
private:
    double m_real;  //实部
    double m_imag;  //虚部
};

//重载加法运算符
complex operator+(const complex & A, const complex &B){
    complex C;
    C.m_real = A.m_real + B.m_real;
    C.m_imag = A.m_imag + B.m_imag;
    return C;
}

//重载减法运算符
complex operator-(const complex & A, const complex &B){
    complex C;
    C.m_real = A.m_real - B.m_real;
    C.m_imag = A.m_imag - B.m_imag;
    return C;
}

//重载乘法运算符
complex operator*(const complex & A, const complex &B){
    complex C;
    C.m_real = A.m_real * B.m_real - A.m_imag * B.m_imag;
    C.m_imag = A.m_imag * B.m_real + A.m_real * B.m_imag;
    return C;
}

//重载除法运算符
complex operator/(const complex & A, const complex & B){
    complex C;
    double square = A.m_real * A.m_real + A.m_imag * A.m_imag;
    C.m_real = (A.m_real * B.m_real + A.m_imag * B.m_imag)/square;
    C.m_imag = (A.m_imag * B.m_real - A.m_real * B.m_imag)/square;
    return C;
}

//重载输入运算符
std::istream & operator>>(std::istream & in, complex & A){
    in >> A.m_real >> A.m_imag;
    return in;
}

//重载输出运算符
std::ostream & operator<<(std::ostream & out, complex & A){
    out << A.m_real <<" + "<< A.m_imag <<" i ";;
    return out;
}



void operation_overload_test() {
    complex c1, c2, c3;
    std:: cin >> c1 >> c2;
 
    c3 = c1 + c2;
    std::cout << "c1 + c2 = " << c3 << std::endl;

    c3 = c1 - c2;
    std::cout << "c1 - c2 = " << c3 << std::endl;

    c3 = c1 * c2;
    std::cout << "c1 * c2 = " << c3 << std::endl;

    c3 = c1 / c2;
    std::cout << "c1 / c2 = " << c3 << std::endl;
}
#endif