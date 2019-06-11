#ifndef _MISC_H_
#define _MISC_H_

double sgn(double x);

class PID {

    private:
        double error,
        integral,
        derivative,
        prevError,
        kP, kI, kD,
        output;
        bool integrate;

    public:
        PID(double _kP, double _kI, double _kD);
        void setError(double _error);
        double runPID();

};

#endif