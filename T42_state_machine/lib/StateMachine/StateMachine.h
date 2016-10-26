#ifndef _STATE_MACHINE_H
#define _STATE_MACHINE_H

#include <Arduino.h>
#define BYTE byte
class StateMachine
{
public:
    enum { EVENT_IGNORED = 0xFE, CANNOT_HAPPEN };

    StateMachine(BYTE maxStates, BYTE initialState = 0);
    virtual ~StateMachine() {}

    BYTE GetCurrentState() { return m_currentState; }

protected:
    void ExternalEvent(BYTE newState, const EventData* pData = NULL);
    void InternalEvent(BYTE newState, const EventData* pData = NULL);

private:
    const BYTE MAX_STATES;
    BYTE m_currentState;
    BYTE m_newState;
    BOOL m_eventGenerated;
    const EventData* m_pEventData;

    virtual const StateMapRow* GetStateMap() = 0;
    virtual const StateMapRowEx* GetStateMapEx() = 0;

    void SetCurrentState(BYTE newState) { m_currentState = newState; }

    void StateEngine(void);
    void StateEngine(const StateMapRow* const pStateMap);
    void StateEngine(const StateMapRowEx* const pStateMapEx);
};

#endif // _STATE_MACHINE_H
