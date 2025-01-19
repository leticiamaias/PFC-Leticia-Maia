

#ifndef EVENT_H
#define EVENT_H

#include <Arduino.h>
#include <stdint.h>

#define NUMBER_EVENT 51
#define SIZE_EVENT 7

struct Event
{
    uint8_t data[SIZE_EVENT];
};

Event createEvent();
Event createEventFromData(uint8_t *data);
void copyEvent(const Event source, Event &destination);

void setBit(Event &event, int position, bool value);
bool getBit(const Event event, int position);

void bitwiseAnd(Event &result, const Event &event1, const Event &event2);
void bitwiseOr(Event &result, const Event &event1, const Event &event2);
void bitwiseXor(Event &result, const Event &event1, const Event &event2);
void bitwiseNot(Event &result, const Event &event);

bool areEqual(const Event &event1, const Event &event2);

void zeroEvent(Event &event);
void oneEvent(Event &event);

void printEvent(const Event event);

#define EVENT_DAGF 50
#define EVENT_LAGF 49
#define EVENT_DAGM 48
#define EVENT_LAGM 47
#define EVENT_DAFERF 46
#define EVENT_DAPASF 45
#define EVENT_AFERF 44
#define EVENT_APASF 43
#define EVENT_DAFERM 42
#define EVENT_DAPASM 41
#define EVENT_AFERM 40
#define EVENT_APASM 39
#define EVENT_DBFM 38
#define EVENT_LBFM 37
#define EVENT_DBFR 36
#define EVENT_LBFR 35
#define EVENT_DBMF 34
#define EVENT_LBMF 33
#define EVENT_DBMR 32
#define EVENT_LBMR 31
#define EVENT_DBRF 30
#define EVENT_LBRF 29
#define EVENT_DBRM 28
#define EVENT_LBRM 27
#define EVENT_DEXA 26
#define EVENT_DVEN 25
#define EVENT_GDIR 24
#define EVENT_GESQ 23
#define EVENT_DMIS 22
#define EVENT_LMIS 21
#define EVENT_DMOE 20
#define EVENT_LMOE 19
#define EVENT_DRESF 18
#define EVENT_LRESF 17
#define EVENT_DRESM 16
#define EVENT_LRESM 15
#define EVENT_MF 14
#define EVENT_HF 13
#define EVENT_LF 12
#define EVENT_MM 11
#define EVENT_HM 10
#define EVENT_LM 9
#define EVENT_MR 8
#define EVENT_HR 7
#define EVENT_LR 6
#define EVENT_FF 5
#define EVENT_QFERF 4
#define EVENT_QPASF 3
#define EVENT_FM 2
#define EVENT_QFERM 1
#define EVENT_QPASM 0


#endif