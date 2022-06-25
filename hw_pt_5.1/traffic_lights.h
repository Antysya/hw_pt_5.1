#pragma once

class Traficlight
{
    class State* current;
public:
    Traficlight();
    void setCurrent(State* s);

    void red();
    void yellow_r();
    void green();  
    void yellow_g();
};

class State
{
public:
    virtual void red(Traficlight* m);
    virtual void yellow_r(Traficlight* m);
    virtual void green(Traficlight* m);
    virtual void yellow_g(Traficlight* m);    
};

class Yellow : public State
{
public:
    Yellow();
    ~Yellow(){};
    void yellow_g(Traficlight* m);
    void yellow_r(Traficlight* m);
};

class Red : public State
{
public:
    Red();
    ~Red(){};
    void yellow_r(Traficlight* m);
};

class Green : public State
{
public:
    Green();
    ~Green(){};
    void yellow_g(Traficlight* m);
};