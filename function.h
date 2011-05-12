#ifndef FUNCTION_H
#define FUNCTION_H
//#include <QString>
#include <QtCore>
#include <math.h>

class Function
{
public:
    // new Type: Tfunc a pointer to a function like: double f(double)
    typedef double (*Tfunc)(double);

    Function(){
        m_funcs.insert("sin", &sin);
        m_funcs.insert("cos", &cos);
        m_funcs.insert("tan", &tan);
        m_funcs.insert("cot", this->cot);
        m_funcs.insert("sec", this->sec);
        m_funcs.insert("csc", this->csc);
    }
    double calculate(QString func, double x, double a=1.0, double b=1.0, double c=0.0 ){
        if (m_funcs.contains(func))
            return a*m_funcs[func](b*x+c);
        else
            return 0.0;
    }
    static double cot(double x){
        return 1/tan(x);
    }
    static double csc(double x){
        return 1/sin(x);
    }
    static double sec(double x){
        return 1/cos(x);
    }
    QHash < QString, Tfunc > m_funcs; // Named hash of functions
};

#endif // FUNCTION_H
