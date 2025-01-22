#include "Automaton.h"
#include "Event.h"

Automaton::Automaton(int numStates, Event *enabledEventStates, int (*MakeTransition)(int state, Event eventOccurred), void (*Loop)(int state))
    : numStates(numStates), enabledEventStates(enabledEventStates), MakeTransition(MakeTransition), Loop(Loop) {}

Automaton::Automaton() {}

Automaton::~Automaton() {}

void Automaton::setEvent(Event event)
{
    actualEvent = event;
}

void Automaton::setActualState(int state)
{
    actualState = state;
}

int Automaton::getActualState()
{
    return actualState;
}

int Automaton::getNumStates()
{
    return numStates;
}

Event Automaton::getEnabledEvent()
{
    return enabledEventStates[actualState];
}

void getEventControllable(Event &eventControllable){
	if(EventControllable_LAgF()){
		setBit(eventControllable,EVENT_LAGF, true);
	} else {
		setBit(eventControllable,EVENT_LAGF, false);
	}
	if(EventControllable_LAgM()){
		setBit(eventControllable,EVENT_LAGM, true);
	} else{
		setBit(eventControllable,EVENT_LAGM, false);
	}
	if(EventControllable_AferF()){
		setBit(eventControllable,EVENT_AFERF, true);
	} else{
		setBit(eventControllable,EVENT_AFERF, false);
	}
	if(EventControllable_ApasF()){
		setBit(eventControllable,EVENT_APASF, true);
	} else{
		setBit(eventControllable,EVENT_APASF, false);
	}
	if(EventControllable_AferM()){
		setBit(eventControllable,EVENT_AFERM, true);
	} else{
		setBit(eventControllable,EVENT_AFERM, false);
	}
	if(EventControllable_ApasM()){
		setBit(eventControllable,EVENT_APASM, true);
		Serial.println(" mandou ligar aquecedor");
	} else{
		setBit(eventControllable,EVENT_APASM, false);
	}
	if(EventControllable_LbFM()){
		setBit(eventControllable,EVENT_LBFM, true);
	} else{
		setBit(eventControllable,EVENT_LBFM, false);
	}
	if(EventControllable_LbFR()){
		setBit(eventControllable,EVENT_LBFR, true);
	} else{
		setBit(eventControllable,EVENT_LBFR, false);
	}
	if(EventControllable_LbMF()){
		setBit(eventControllable,EVENT_LBMF, true);
	} else{
		setBit(eventControllable,EVENT_LBMF, false);
	}
	if(EventControllable_LbMR()){
		setBit(eventControllable,EVENT_LBMR, true);
	} else {
		setBit(eventControllable,EVENT_LBMR, false);
	}
	if(EventControllable_LbRF()){
		setBit(eventControllable,EVENT_LBRF, true);
	} else{
		setBit(eventControllable,EVENT_LBRF, false);
	}
	if(EventControllable_LbRM()){
		setBit(eventControllable,EVENT_LBRM, true);
	} else{ 
		setBit(eventControllable,EVENT_LBRM, false);
	}
	if(EventControllable_Gdir()){
		setBit(eventControllable,EVENT_GDIR, true);
	} else{
		setBit(eventControllable,EVENT_GDIR, false);
	}
	if(EventControllable_Gesq()){
		setBit(eventControllable,EVENT_GESQ, true);
	} else{
		setBit(eventControllable,EVENT_GESQ, false);
	}
	if(EventControllable_Lmis()){
		setBit(eventControllable,EVENT_LMIS, true);
	} else{
		setBit(eventControllable,EVENT_LMIS, false);
	}
	if(EventControllable_Lmoe()){
		setBit(eventControllable,EVENT_LMOE, true);
	} else{
		setBit(eventControllable,EVENT_LMOE, false);
	}
	if(EventControllable_LResF()){
		setBit(eventControllable,EVENT_LRESF, true);
	} else{
		setBit(eventControllable,EVENT_LRESF, false);
	}
	if(EventControllable_LResM()){
		setBit(eventControllable,EVENT_LRESM, true);
	} else{
		setBit(eventControllable,EVENT_LRESM, false);
	}
}


void getEventUncontrollable(Event &eventUncontrollable){
	if(EventUncontrollable_DAgF()){
		setBit(eventUncontrollable,EVENT_DAGF, true);
	}
	if(EventUncontrollable_DAgM()){
		setBit(eventUncontrollable,EVENT_DAGM, true);
	}
	if(EventUncontrollable_DAferF()){
		setBit(eventUncontrollable,EVENT_DAFERF, true);
	}
	if(EventUncontrollable_DApasF()){
		setBit(eventUncontrollable,EVENT_DAPASF, true);
	}
	if(EventUncontrollable_DAferM()){
		setBit(eventUncontrollable,EVENT_DAFERM, true);
	}
	if(EventUncontrollable_DApasM()){
		setBit(eventUncontrollable,EVENT_DAPASM, true);
	}
	if(EventUncontrollable_DbFM()){
		setBit(eventUncontrollable,EVENT_DBFM, true);
	}
	if(EventUncontrollable_DbFR()){
		setBit(eventUncontrollable,EVENT_DBFR, true);
	}
	if(EventUncontrollable_DbMF()){
		setBit(eventUncontrollable,EVENT_DBMF, true);
	}
	if(EventUncontrollable_DbMR()){
		setBit(eventUncontrollable,EVENT_DBMR, true);
	}
	if(EventUncontrollable_DbRF()){
		setBit(eventUncontrollable,EVENT_DBRF, true);
	}
	if(EventUncontrollable_DbRM()){
		setBit(eventUncontrollable,EVENT_DBRM, true);
		Serial.println("setou evento desliga bomba true");
	}
	if(EventUncontrollable_Dexa()){
		setBit(eventUncontrollable,EVENT_DEXA, true);
	}
	if(EventUncontrollable_Dven()){
		setBit(eventUncontrollable,EVENT_DVEN, true);
	}
	if(EventUncontrollable_Dmis()){
		setBit(eventUncontrollable,EVENT_DMIS, true);
	}
	if(EventUncontrollable_Dmoe()){
		setBit(eventUncontrollable,EVENT_DMOE, true);
	}
	if(EventUncontrollable_DResF()){
		setBit(eventUncontrollable,EVENT_DRESF, true);
	}
	if(EventUncontrollable_DResM()){
		setBit(eventUncontrollable,EVENT_DRESM, true);
	}
	if(EventUncontrollable_MF()){
		setBit(eventUncontrollable,EVENT_MF, true);
	}
	if(EventUncontrollable_HF()){
		setBit(eventUncontrollable,EVENT_HF, true);
	}
	if(EventUncontrollable_LF()){
		setBit(eventUncontrollable,EVENT_LF, true);
		
	}
	if(EventUncontrollable_MM()){
		setBit(eventUncontrollable,EVENT_MM, true);
		Serial.println("evento MM");
	}
	if(EventUncontrollable_HM()){
		setBit(eventUncontrollable,EVENT_HM, true);
		Serial.println("evento HM");
	}
	if(EventUncontrollable_LM()){
		setBit(eventUncontrollable,EVENT_LM, true);
		Serial.println("evento LM");
	}
	if(EventUncontrollable_MR()){
		setBit(eventUncontrollable,EVENT_MR, true);
	}
	if(EventUncontrollable_HR()){
		setBit(eventUncontrollable,EVENT_HR, true);
	}
	if(EventUncontrollable_LR()){
		setBit(eventUncontrollable,EVENT_LR, true);
	}
	if(EventUncontrollable_FF()){
		setBit(eventUncontrollable,EVENT_FF, true);
		Serial.println("evento FF");
	}
	if(EventUncontrollable_QferF()){
		setBit(eventUncontrollable,EVENT_QFERF, true);
		Serial.println("evento QferF");
	}
	if(EventUncontrollable_QpasF()){
		setBit(eventUncontrollable,EVENT_QPASF, true);
		Serial.println("evento QpasF");
	}
	if(EventUncontrollable_FM()){
		setBit(eventUncontrollable,EVENT_FM, true);
		Serial.println("evento FM");
	}
	if(EventUncontrollable_QferM()){
		setBit(eventUncontrollable,EVENT_QFERM, true);
		Serial.println("evento QferM");
	}
	if(EventUncontrollable_QpasM()){
		setBit(eventUncontrollable,EVENT_QPASM, true);
		Serial.println("evento QpasM");
	}
}


GenericAction ActionAutomatons0[2]={ &StateActionAutomaton0_AgFState0,&StateActionAutomaton0_AgFState1 };
GenericAction ActionAutomatons1[2]={ &StateActionAutomaton1_AgMState0,&StateActionAutomaton1_AgMState1 };
GenericAction ActionAutomatons2[3]={ &StateActionAutomaton2_AqFState0,&StateActionAutomaton2_AqFState1,&StateActionAutomaton2_AqFState2 };
GenericAction ActionAutomatons3[3]={ &StateActionAutomaton3_AqMState0,&StateActionAutomaton3_AqMState1,&StateActionAutomaton3_AqMState2 };
GenericAction ActionAutomatons4[2]={ &StateActionAutomaton4_BFMState0,&StateActionAutomaton4_BFMState1 };
GenericAction ActionAutomatons5[2]={ &StateActionAutomaton5_BFRState0,&StateActionAutomaton5_BFRState1 };
GenericAction ActionAutomatons6[2]={ &StateActionAutomaton6_BMFState0,&StateActionAutomaton6_BMFState1 };
GenericAction ActionAutomatons7[2]={ &StateActionAutomaton7_BMRState0,&StateActionAutomaton7_BMRState1 };
GenericAction ActionAutomatons8[2]={ &StateActionAutomaton8_BRFState0,&StateActionAutomaton8_BRFState1 };
GenericAction ActionAutomatons9[2]={ &StateActionAutomaton9_BRMState0,&StateActionAutomaton9_BRMState1 };
GenericAction ActionAutomatons10[3]={ &StateActionAutomaton10_ExaVenState0,&StateActionAutomaton10_ExaVenState1,&StateActionAutomaton10_ExaVenState2 };
GenericAction ActionAutomatons11[2]={ &StateActionAutomaton11_MisState0,&StateActionAutomaton11_MisState1 };
GenericAction ActionAutomatons12[2]={ &StateActionAutomaton12_MoedorState0,&StateActionAutomaton12_MoedorState1 };
GenericAction ActionAutomatons13[2]={ &StateActionAutomaton13_ResFState0,&StateActionAutomaton13_ResFState1 };
GenericAction ActionAutomatons14[2]={ &StateActionAutomaton14_ResMState0,&StateActionAutomaton14_ResMState1 };
GenericAction ActionAutomatons15[1]={ &StateActionAutomaton15_SnFState0 };
GenericAction ActionAutomatons16[1]={ &StateActionAutomaton16_SnMState0 };
GenericAction ActionAutomatons17[1]={ &StateActionAutomaton17_SnRState0 };
GenericAction ActionAutomatons18[1]={ &StateActionAutomaton18_StFState0 };
GenericAction ActionAutomatons19[1]={ &StateActionAutomaton19_StMState0 };
GenericAction ActionAutomatons20[1]={[](){}};
GenericAction ActionAutomatons21[1]={[](){}};
GenericAction ActionAutomatons22[1]={[](){}};
GenericAction ActionAutomatons23[1]={[](){}};
GenericAction ActionAutomatons24[1]={[](){}};
GenericAction ActionAutomatons25[1]={[](){}};
GenericAction ActionAutomatons26[1]={[](){}};
GenericAction ActionAutomatons27[1]={[](){}};
GenericAction ActionAutomatons28[1]={[](){}};
GenericAction ActionAutomatons29[1]={[](){}};
GenericAction ActionAutomatons30[1]={[](){}};


void Automaton0Loop_AgF(int State){
	ActionAutomatons0[State]();
}

void Automaton1Loop_AgM(int State){
	ActionAutomatons1[State]();
}

void Automaton2Loop_AqF(int State){
	ActionAutomatons2[State]();
}

void Automaton3Loop_AqM(int State){
	ActionAutomatons3[State]();
}

void Automaton4Loop_BFM(int State){
	ActionAutomatons4[State]();
}

void Automaton5Loop_BFR(int State){
	ActionAutomatons5[State]();
}

void Automaton6Loop_BMF(int State){
	ActionAutomatons6[State]();
}

void Automaton7Loop_BMR(int State){
	ActionAutomatons7[State]();
}

void Automaton8Loop_BRF(int State){
	ActionAutomatons8[State]();
}

void Automaton9Loop_BRM(int State){
	ActionAutomatons9[State]();
}

void Automaton10Loop_ExaVen(int State){
	ActionAutomatons10[State]();
}

void Automaton11Loop_Mis(int State){
	ActionAutomatons11[State]();
}

void Automaton12Loop_Moedor(int State){
	ActionAutomatons12[State]();
}

void Automaton13Loop_ResF(int State){
	ActionAutomatons13[State]();
}

void Automaton14Loop_ResM(int State){
	ActionAutomatons14[State]();
}

void Automaton15Loop_SnF(int State){
	ActionAutomatons15[State]();
}

void Automaton16Loop_SnM(int State){
	ActionAutomatons16[State]();
}

void Automaton17Loop_SnR(int State){
	ActionAutomatons17[State]();
}

void Automaton18Loop_StF(int State){
	ActionAutomatons18[State]();
}

void Automaton19Loop_StM(int State){
	ActionAutomatons19[State]();
}

void Automaton20Loop_SupBFMBFRSnFBFReFMcTF(int State){
	ActionAutomatons20[State]();
}

void Automaton21Loop_SupBMFBMRSnMBMReMFcTM(int State){
	ActionAutomatons21[State]();
}

void Automaton22Loop_SupBMRBFRSnRBMReFRcTR(int State){
	ActionAutomatons22[State]();
}

void Automaton23Loop_SupBRFBMFSnFBMFeRFcTF(int State){
	ActionAutomatons23[State]();
}

void Automaton24Loop_SupBRFBRMSnRBRFeRMcTR(int State){
	ActionAutomatons24[State]();
}

void Automaton25Loop_SupBRMBFMSnMBFMeRMcTM(int State){
	ActionAutomatons25[State]();
}

void Automaton26Loop_SupExaVenMoedorEXAcMOE(int State){
	ActionAutomatons26[State]();
}

void Automaton27Loop_SupResFAqFStFTFcAQeRES(int State){
	ActionAutomatons27[State]();
}

void Automaton28Loop_SupResMAqMStMTMcAQeRES(int State){
	ActionAutomatons28[State]();
}

void Automaton29Loop_SupSnFAgFResFAqFMisTFcSn(int State){
	ActionAutomatons29[State]();
}

void Automaton30Loop_SupSnMExaVenAgMResMAqMMoedorTMcSn(int State){
	ActionAutomatons30[State]();
}



int MakeTransitionAutomaton0_AgF(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_LAGF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAGF))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton1_AgM(int State, Event eventOccurred) 
{ 
	//Serial.println(getBit(eventOccurred,EVENT_LAGM));
	if (State == 0 && (getBit(eventOccurred,EVENT_LAGM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAGM))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton2_AqF(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_AFERF))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_APASF))){ 
		return 2;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAFERF))){ 
		return 0;
	}
	if (State == 2 && (getBit(eventOccurred,EVENT_DAPASF))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton3_AqM(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_AFERM))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_APASM))){ 
		return 2;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAFERM))){ 
		return 0;
	}
	if (State == 2 && (getBit(eventOccurred,EVENT_DAPASM))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton4_BFM(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_LBFM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBFM))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton5_BFR(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_LBFR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBFR))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton6_BMF(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_LBMF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBMF))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton7_BMR(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_LBMR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBMR))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton8_BRF(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_LBRF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBRF))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton9_BRM(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_LBRM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBRM))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton10_ExaVen(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_GDIR))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_GESQ))){ 
		return 2;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DEXA))){ 
		return 0;
	}
	if (State == 2 && (getBit(eventOccurred,EVENT_DVEN))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton11_Mis(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_LMIS))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DMIS))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton12_Moedor(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_LMOE))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DMOE))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton13_ResF(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_LRESF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DRESF))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton14_ResM(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_LRESM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DRESM))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton15_SnF(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_MF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_HF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LF))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton16_SnM(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_MM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_HM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LM))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton17_SnR(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_MR))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_HR))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LR))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton18_StF(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_FF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_QFERF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_QPASF))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton19_StM(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_FM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_QFERM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_QPASM))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton20_SupBFMBFRSnFBFReFMcTF(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_HF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DBFR))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DBFM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_MF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_HF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LF))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBFR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBFM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_MF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LBFM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LBFR))){ 
		return 1;
	}

	return(State);
}

int MakeTransitionAutomaton21_SupBMFBMRSnMBMReMFcTM(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_HM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DBMR))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DBMF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_MM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_HM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LM))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBMR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBMF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_MM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LBMF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LBMR))){ 
		return 1;
	}
	return(State);
}

int MakeTransitionAutomaton22_SupBMRBFRSnRBMReFRcTR(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_HR))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LR))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DBFR))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DBMR))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_MR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_HR))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBFR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBMR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_MR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LBMR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LBFR))){ 
		return 1;
	}

	return(State);
}

int MakeTransitionAutomaton23_SupBRFBMFSnFBMFeRFcTF(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_MF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DBMF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DBRF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_HF))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LBRF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LBMF))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_MF))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBMF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBRF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_HF))){ 
		return 1;
	}

	return(State);
}

int MakeTransitionAutomaton24_SupBRFBRMSnRBRFeRMcTR(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_MR))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_HR))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DBRM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DBRF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LR))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LBRF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LBRM))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_MR))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_HR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBRM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBRF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LR))){ 
		return 1;
	}

	return(State);
}

int MakeTransitionAutomaton25_SupBRMBFMSnMBFMeRMcTM(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_MM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DBFM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DBRM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_HM))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LBRM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LBFM))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_MM))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBFM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DBRM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_HM))){ 
		return 1;
	}

	return(State);
}

int MakeTransitionAutomaton26_SupExaVenMoedorEXAcMOE(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_DVEN))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DEXA))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DMOE))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_GESQ))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_GDIR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DVEN))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DEXA))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DMOE))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_GESQ))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_GDIR))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LMOE))){ 
		return 0;
	}

	return(State);
}

int MakeTransitionAutomaton27_SupResFAqFStFTFcAQeRES(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_FF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DAPASF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DRESF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DAFERF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_QFERF))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_QPASF))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_APASF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_AFERF))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_FF))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAPASF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DRESF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAFERF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_QFERF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_QPASF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LRESF))){ 
		return 1;
	}

	return(State);
}

int MakeTransitionAutomaton28_SupResMAqMStMTMcAQeRES(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_FM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DAPASM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DRESM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DAFERM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_QFERM))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_QPASM))){ 
		return 1;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_APASM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_AFERM))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_FM))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAPASM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DRESM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAFERM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_QFERM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_QPASM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LRESM))){ 
		return 1;
	}
	Serial.println("Sup28 estado:");
	Serial.println(State);
	return(State);
}

int MakeTransitionAutomaton29_SupSnFAgFResFAqFMisTFcSn(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_HF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DMIS))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DAFERF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DAPASF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DRESF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DAGF))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_MF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_HF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LF))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DMIS))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAFERF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAPASF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DRESF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAGF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_MF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LAGF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LRESF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_AFERF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_APASF))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LMIS))){ 
		return 1;
	}

	return(State);
}

int MakeTransitionAutomaton30_SupSnMExaVenAgMResMAqMMoedorTMcSn(int State, Event eventOccurred) 
{ 
	if (State == 0 && (getBit(eventOccurred,EVENT_HM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_LM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DMOE))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DAPASM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DVEN))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DRESM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DAGM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DEXA))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_DAFERM))){ 
		return 0;
	}
	if (State == 0 && (getBit(eventOccurred,EVENT_MM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_HM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LM))){ 
		return 0;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DMOE))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAPASM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DVEN))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DRESM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAGM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DEXA))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_DAFERM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_MM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_GDIR))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_GESQ))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LAGM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LRESM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_AFERM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_APASM))){ 
		return 1;
	}
	if (State == 1 && (getBit(eventOccurred,EVENT_LMOE))){ 
		return 1;
	}
	Serial.println("Sup30 estado:");
	Serial.println(State);
	return(State);
}


