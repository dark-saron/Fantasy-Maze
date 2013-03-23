#pragma once


//abstract class

class CPhase
{
public:
    enum EType
    {
        menu,
        game,
        exit,
        unknown
    };

    virtual CPhase::EType GetPhase() const = 0;

    virtual void Begin() = 0;
    virtual void Draw() = 0;
    virtual void End() = 0;
    virtual CPhase::EType Run(int timeLeft) = 0;

};

