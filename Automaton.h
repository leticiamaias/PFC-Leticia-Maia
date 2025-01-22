
#ifndef AUTOMATON_H
#define AUTOMATON_H

#include "Event.h"
#include <HCSR04.h> //Biblioteca Sensor Nível
#include <OneWire.h> // Bibliotecas Sensor Temp
#include <DallasTemperature.h>
#include <ArduinoQueue.h> // Biblioteca para trabalhar com filas

#define NIVEL_ALTO_R 5
#define NIVEL_BAIXO_R 23
#define NIVEL_MEDIO_INFERIOR_R 9
#define NIVEL_MEDIO_SUPERIOR_R 20
#define NIVEL_ALTO_M 5
#define NIVEL_BAIXO_M 16
#define NIVEL_MEDIO_INFERIOR_M 7
#define NIVEL_MEDIO_SUPERIOR_M 9
#define NIVEL_ALTO_F 5
#define NIVEL_BAIXO_F 16
#define NIVEL_MEDIO_INFERIOR_F 7
#define NIVEL_MEDIO_SUPERIOR_F 9
#define TEMP_FRIA_F 36
#define TEMP_FRIA_M 29
#define TEMP_FERMENTACAO 45
#define TEMP_PASTEURIZACAO 40
extern float TempF, TempM, DistR, DistF, DistM;
extern unsigned long agFTimer, agMTimer, aqFerFTimer, aqPasFTimer, moeTimer, exaTimer, venTimer, misTimer, aqFerMTimer, aqPasMTimer;  
extern const int AgM, AgF, Moedor, Misturador, ExaVen, ExaVenGnd, ResMgnd, ResM, ResF, ResFgnd, FerM, FerF, PasM, PasF, BRM, BRMgnd, BRF, BRFgnd, BFR, BFRgnd, BFM, BFMgnd, BMR, BMRgnd, BMF, BMFgnd, StM, StF, SnREcho, SnMEcho, SnFEcho, SnMtrig, SnFtrig, SnRtrig;
extern bool DBFM, DBFR, DBMF, DBMR, DBRF, DBRM, DagF, DagM, Dexa, Dven, Dmis, Dmoe, DresF, DresM, DAFerF, DAPasF , DAFerM, DAPasM, QFerF, QFerM, QPasF, QPasM, FF, FM, MM, MF, MR, HM, HF, HR, LM, LF, LR;
extern bool LBFM, LBFR, LBMF, LBMR, LBRF, LBRM, LagF, LagM, AferF, ApasF, AferM , ApasM, GdirExa, GesqVen, Lmis, Lmoe, LresF, LresM;
extern int FlagAgF, FlagAgM, FlagAqFerF, FlagAqFerM, FlagBM, FlagBF, FlagBRM, FlagBRF;
extern bool AgFFer, AgMFer;
extern bool agFEnd, agMEnd, aqFerFEnd, aqFerMEnd, aqPasFEnd, aqPasMEnd, moeEnd, exaEnd, misEnd, venEnd;
extern int estadoLimpeza, estadoSecagem, estadoFermentacao, estadoPasteurizacao, estadoCozimento, estadoMistura, estadoMoagem;
extern bool tanqueMOcupado, tanqueFOcupado;
// Estrutura para representar processos
struct Processo {
    String nome;
    void (*executar)(); // Ponteiro para a função do processo
    int* estado;        // Ponteiro para a variável de estado do processo
};

// Filas de processos para cada tanque
extern ArduinoQueue<Processo> filaTanqueM;
extern ArduinoQueue<Processo> filaTanqueF;


typedef void (*GenericAction)();

class Automaton
{
public:
    Automaton(int numStates, Event *enabledEventStates, int (*MakeTransition)(int state, Event eventOccurred), void (*Loop)(int state));
    Automaton();
    ~Automaton();

    int getActualState();                                  // Returns the current state of the automaton
    int getNumStates();                                    // Returns the total number of states in the automaton
    Event getEnabledEvent();                               // Returns the value of enabled events for the automaton
    void setActualState(int state);                        // Sets the current state of the automaton
    void setEvent(Event event);                            // Sets the value of the current event of the automaton
    Event * enabledEventStates;                             // Pointer to the list of enabled event values
    int (*MakeTransition)(int state, Event eventOccurred); // Pointer to the state transition function
    void (*Loop)(int state);                               // Pointer to the current state execution function

private:
    int actualState = 0; // Current state of the automaton
    Event actualEvent;   // Value of the current event of the automaton
    int numStates;       // Total number of states in the automaton
};

void setupPin();
void doEveryLoop();
void getEventControllable(Event &eventControllable);     // Obtains Controllablble events
void getEventUncontrollable(Event &eventUncontrollable); // Obtains Uncontrollablble events

// Funções Processos
void executarLimpeza();
void executarSecagem();
void executarFermentacao();
void executarPasteurizacao();
void executarMoagem();
void executarCozimento();
void executarMistura();

// Funções Controlador
void inicializarFilas(); // Inicializa as filas de processos
void executarProcessos(); // Gerencia a execução dos processos

void Automaton0Loop_AgF(int State); 

void Automaton1Loop_AgM(int State); 

void Automaton2Loop_AqF(int State); 

void Automaton3Loop_AqM(int State); 

void Automaton4Loop_BFM(int State); 

void Automaton5Loop_BFR(int State); 

void Automaton6Loop_BMF(int State); 

void Automaton7Loop_BMR(int State); 

void Automaton8Loop_BRF(int State); 

void Automaton9Loop_BRM(int State); 

void Automaton10Loop_ExaVen(int State); 

void Automaton11Loop_Mis(int State); 

void Automaton12Loop_Moedor(int State); 

void Automaton13Loop_ResF(int State); 

void Automaton14Loop_ResM(int State); 

void Automaton15Loop_SnF(int State); 

void Automaton16Loop_SnM(int State); 

void Automaton17Loop_SnR(int State); 

void Automaton18Loop_StF(int State); 

void Automaton19Loop_StM(int State); 

void Automaton20Loop_SupBFMBFRSnFBFReFMcTF(int State); 

void Automaton21Loop_SupBMFBMRSnMBMReMFcTM(int State); 

void Automaton22Loop_SupBMRBFRSnRBMReFRcTR(int State); 

void Automaton23Loop_SupBRFBMFSnFBMFeRFcTF(int State); 

void Automaton24Loop_SupBRFBRMSnRBRFeRMcTR(int State); 

void Automaton25Loop_SupBRMBFMSnMBFMeRMcTM(int State); 

void Automaton26Loop_SupExaVenMoedorEXAcMOE(int State); 

void Automaton27Loop_SupResFAqFStFTFcAQeRES(int State); 

void Automaton28Loop_SupResMAqMStMTMcAQeRES(int State); 

void Automaton29Loop_SupSnFAgFResFAqFMisTFcSn(int State); 

void Automaton30Loop_SupSnMExaVenAgMResMAqMMoedorTMcSn(int State); 



// ADD-EVENT-CONTROLLABLE

bool EventControllable_LAgF();
bool EventControllable_LAgM();
bool EventControllable_AferF();
bool EventControllable_ApasF();
bool EventControllable_AferM();
bool EventControllable_ApasM();
bool EventControllable_LbFM();
bool EventControllable_LbFR();
bool EventControllable_LbMF();
bool EventControllable_LbMR();
bool EventControllable_LbRF();
bool EventControllable_LbRM();
bool EventControllable_Gdir();
bool EventControllable_Gesq();
bool EventControllable_Lmis();
bool EventControllable_Lmoe();
bool EventControllable_LResF();
bool EventControllable_LResM();

// ADD-EVENT-UNCONTROLLABLE
bool EventUncontrollable_DAgF();
bool EventUncontrollable_DAgM();
bool EventUncontrollable_DAferF();
bool EventUncontrollable_DApasF();
bool EventUncontrollable_DAferM();
bool EventUncontrollable_DApasM();
bool EventUncontrollable_DbFM();
bool EventUncontrollable_DbFR();
bool EventUncontrollable_DbMF();
bool EventUncontrollable_DbMR();
bool EventUncontrollable_DbRF();
bool EventUncontrollable_DbRM();
bool EventUncontrollable_Dexa();
bool EventUncontrollable_Dven();
bool EventUncontrollable_Dmis();
bool EventUncontrollable_Dmoe();
bool EventUncontrollable_DResF();
bool EventUncontrollable_DResM();
bool EventUncontrollable_MF();
bool EventUncontrollable_HF();
bool EventUncontrollable_LF();
bool EventUncontrollable_MM();
bool EventUncontrollable_HM();
bool EventUncontrollable_LM();
bool EventUncontrollable_MR();
bool EventUncontrollable_HR();
bool EventUncontrollable_LR();
bool EventUncontrollable_FF();
bool EventUncontrollable_QferF();
bool EventUncontrollable_QpasF();
bool EventUncontrollable_FM();
bool EventUncontrollable_QferM();
bool EventUncontrollable_QpasM();


void StateActionAutomaton0_AgFState0();
void StateActionAutomaton0_AgFState1();

void StateActionAutomaton1_AgMState0();
void StateActionAutomaton1_AgMState1();

void StateActionAutomaton2_AqFState0();
void StateActionAutomaton2_AqFState1();
void StateActionAutomaton2_AqFState2();

void StateActionAutomaton3_AqMState0();
void StateActionAutomaton3_AqMState1();
void StateActionAutomaton3_AqMState2();

void StateActionAutomaton4_BFMState0();
void StateActionAutomaton4_BFMState1();

void StateActionAutomaton5_BFRState0();
void StateActionAutomaton5_BFRState1();

void StateActionAutomaton6_BMFState0();
void StateActionAutomaton6_BMFState1();

void StateActionAutomaton7_BMRState0();
void StateActionAutomaton7_BMRState1();

void StateActionAutomaton8_BRFState0();
void StateActionAutomaton8_BRFState1();

void StateActionAutomaton9_BRMState0();
void StateActionAutomaton9_BRMState1();

void StateActionAutomaton10_ExaVenState0();
void StateActionAutomaton10_ExaVenState1();
void StateActionAutomaton10_ExaVenState2();

void StateActionAutomaton11_MisState0();
void StateActionAutomaton11_MisState1();

void StateActionAutomaton12_MoedorState0();
void StateActionAutomaton12_MoedorState1();

void StateActionAutomaton13_ResFState0();
void StateActionAutomaton13_ResFState1();

void StateActionAutomaton14_ResMState0();
void StateActionAutomaton14_ResMState1();

void StateActionAutomaton15_SnFState0();

void StateActionAutomaton16_SnMState0();

void StateActionAutomaton17_SnRState0();

void StateActionAutomaton18_StFState0();

void StateActionAutomaton19_StMState0();



int MakeTransitionAutomaton0_AgF(int State, Event eventOccurred);
int MakeTransitionAutomaton1_AgM(int State, Event eventOccurred);
int MakeTransitionAutomaton2_AqF(int State, Event eventOccurred);
int MakeTransitionAutomaton3_AqM(int State, Event eventOccurred);
int MakeTransitionAutomaton4_BFM(int State, Event eventOccurred);
int MakeTransitionAutomaton5_BFR(int State, Event eventOccurred);
int MakeTransitionAutomaton6_BMF(int State, Event eventOccurred);
int MakeTransitionAutomaton7_BMR(int State, Event eventOccurred);
int MakeTransitionAutomaton8_BRF(int State, Event eventOccurred);
int MakeTransitionAutomaton9_BRM(int State, Event eventOccurred);
int MakeTransitionAutomaton10_ExaVen(int State, Event eventOccurred);
int MakeTransitionAutomaton11_Mis(int State, Event eventOccurred);
int MakeTransitionAutomaton12_Moedor(int State, Event eventOccurred);
int MakeTransitionAutomaton13_ResF(int State, Event eventOccurred);
int MakeTransitionAutomaton14_ResM(int State, Event eventOccurred);
int MakeTransitionAutomaton15_SnF(int State, Event eventOccurred);
int MakeTransitionAutomaton16_SnM(int State, Event eventOccurred);
int MakeTransitionAutomaton17_SnR(int State, Event eventOccurred);
int MakeTransitionAutomaton18_StF(int State, Event eventOccurred);
int MakeTransitionAutomaton19_StM(int State, Event eventOccurred);
int MakeTransitionAutomaton20_SupBFMBFRSnFBFReFMcTF(int State, Event eventOccurred);
int MakeTransitionAutomaton21_SupBMFBMRSnMBMReMFcTM(int State, Event eventOccurred);
int MakeTransitionAutomaton22_SupBMRBFRSnRBMReFRcTR(int State, Event eventOccurred);
int MakeTransitionAutomaton23_SupBRFBMFSnFBMFeRFcTF(int State, Event eventOccurred);
int MakeTransitionAutomaton24_SupBRFBRMSnRBRFeRMcTR(int State, Event eventOccurred);
int MakeTransitionAutomaton25_SupBRMBFMSnMBFMeRMcTM(int State, Event eventOccurred);
int MakeTransitionAutomaton26_SupExaVenMoedorEXAcMOE(int State, Event eventOccurred);
int MakeTransitionAutomaton27_SupResFAqFStFTFcAQeRES(int State, Event eventOccurred);
int MakeTransitionAutomaton28_SupResMAqMStMTMcAQeRES(int State, Event eventOccurred);
int MakeTransitionAutomaton29_SupSnFAgFResFAqFMisTFcSn(int State, Event eventOccurred);
int MakeTransitionAutomaton30_SupSnMExaVenAgMResMAqMMoedorTMcSn(int State, Event eventOccurred);


#endif