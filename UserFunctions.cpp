#include "Automaton.h"
#include <HCSR04.h>
#include <OneWire.h>
#include <DallasTemperature.h>


float TempF = 0, TempM = 0, DistR = 0, DistF = 28, DistM = 28;
unsigned long agFTimer = 0, agMTimer = 0, aqFerFTimer = 0, aqPasFTimer = 0, moeTimer = 0, exaTimer = 0, venTimer = 0, misTimer = 0, aqFerMTimer = 0, aqPasMTimer = 0;  
const int AgM = 36, AgF = 53, Moedor = 37, Misturador = 51, ExaVen = 33, ExaVenGnd = 32, ResMgnd= 30, ResM = 31, ResF = 49, ResFgnd= 48, FerM = 34, FerF = 50, PasM = 35, PasF = 52, BRM = 23, BRMgnd = 22, BRF = 25, BRFgnd = 24, BFR = 45, BFRgnd = 44, BFM = 47, BFMgnd = 46, BMR = 28, BMRgnd = 29, BMF = 27, BMFgnd = 26, StM = 12, StF = 13, SnREcho = 40, SnMEcho = 38, SnFEcho = 42, SnMtrig = 39, SnFtrig = 43, SnRtrig = 41;
bool DBFM = false, DBFR = false, DBMF = false, DBMR = false, DBRF = false, DBRM = false, DagF = false, DagM = false, Dexa = false, Dven = false, Dmis = false, Dmoe = false, DresF =false, DresM = false, DAFerF = false, DAPasF = false, DAFerM = false, DAPasM = false, QFerF = false, QFerM = false, QPasF = false, QPasM = false, FF = true, FM = true, MM = false, MF = false, MR = false, HM = false, HF = false, HR = true, LM = true, LF = true, LR = false;
bool LBFM = false, LBFR = false, LBMF = false, LBMR = false, LBRF = false, LBRM = false, LagF = false, LagM = false, AferF = false, ApasF = false, AferM = false, ApasM = false, GdirExa = false, GesqVen = false, Lmis = false, Lmoe = false, LresF = false, LresM = false;
int FlagAgF = 3, FlagAgM = 3, FlagAqFerF = 3, FlagAqFerM = 3, FlagBM = 0, FlagBF = 0, FlagBRM = 0, FlagBRF = 0;
int NivelAtualM = -1, StatusTempAtualM = -1,NivelAtualF = -1, StatusTempAtualF = -1, NivelAtualR = -1;
bool AgFFer = false, AgMFer = false;
bool agFEnd = true, agMEnd = true, aqFerFEnd = true, aqFerMEnd = true,aqPasFEnd = true, aqPasMEnd = true, moeEnd = true, exaEnd = true, venEnd = true, misEnd = true;
HCSR04 SnM(SnMtrig, SnMEcho);
HCSR04 SnR(SnRtrig, SnREcho);
HCSR04 SnF(SnFtrig, SnFEcho);
OneWire oneWireF(StF); 
OneWire oneWireM(StM);   
DallasTemperature StempF(&oneWireF);
DallasTemperature StempM(&oneWireM);

void setupPin()
{
  	pinMode(AgM, OUTPUT);   //AgitadorM
  	pinMode(AgF, OUTPUT);   //AgitadorF
	pinMode(Moedor, OUTPUT);  //Moedor
	pinMode(Misturador, OUTPUT);  //Misturador
	pinMode(ExaVen, OUTPUT);   //Exaustor e Ventilador
	pinMode(ResM, OUTPUT);   //ResfriadorM
  	pinMode(ResF, OUTPUT);   //ResfriadorF
	pinMode(FerM, OUTPUT);  //Aquecedor-FermentaçãoM
	pinMode(FerF, OUTPUT);  //Aquecedor-FermentaçãoF
	pinMode(PasF, OUTPUT);  //Aquecedor-PasteurizaçãoF
	pinMode(PasM, OUTPUT);  //Aquecedor-PasteurizaçãoM
	pinMode(BRM, OUTPUT);   //Bomba RM
	pinMode(BRF, OUTPUT);   //Bomba RF
  	pinMode(BFR, OUTPUT);   //Bomba FR
	pinMode(BFM, OUTPUT);  //Bomba FM
	pinMode(BMR, OUTPUT);  //Bomba MR
	pinMode(BMF, OUTPUT);  //Bomba MF


	digitalWrite(BRMgnd, LOW);
	digitalWrite(BRFgnd, LOW);
	digitalWrite(BFRgnd, LOW);
	digitalWrite(BFMgnd, LOW);
	digitalWrite(BMRgnd, LOW);
	digitalWrite(BMFgnd, LOW);
	digitalWrite(ExaVenGnd, LOW);
	digitalWrite(ResFgnd, LOW);
	digitalWrite(ResMgnd, LOW);
	digitalWrite(AferF, LOW);
	digitalWrite(AferM, LOW);
	digitalWrite(ApasF, LOW);
	digitalWrite(ApasM, LOW);
	digitalWrite(AgM, LOW);
	digitalWrite(AgF, LOW);
	digitalWrite(Misturador, LOW);
	digitalWrite(Moedor, LOW);
	
	StempM.begin();
    StempF.begin();
	inicializarFilas();
	
}

// This function will be called every Arduino loop, put here something that you want to repeat always
void doEveryLoop(){


  	StempM.requestTemperatures();
  	StempF.requestTemperatures();    // Send command to get temperatures
  	TempM = StempM.getTempCByIndex(0);
  	TempF = StempF.getTempCByIndex(0);
  	Serial.print("Temperature from StempM is: ");
  	Serial.println(StempM.getTempCByIndex(0));
	Serial.print("Temperature from StempF is: ");
  	Serial.println(StempF.getTempCByIndex(0));
	DistM = SnM.dist();
	Serial.print("Nível M:");
	Serial.println(DistM);
	DistR = SnR.dist();
	Serial.print("Nível R:");
	Serial.println(DistR);
	DistF = SnF.dist();
	Serial.print("Nível F:");
	Serial.println(DistF);

	executarProcessos();

}

// This set of functions should be implemented in a way to handle the controllable events of the system
bool EventControllable_LAgF(){
	return LagF;
}

bool EventControllable_LAgM(){
	return LagM;
}

bool EventControllable_AferF(){
	return AferF;
}

bool EventControllable_ApasF(){
	return ApasF;
}

bool EventControllable_AferM(){
	return AferM;
}

bool EventControllable_ApasM(){
	return ApasM;
}

bool EventControllable_LbFM(){
	return LBFM;
}

bool EventControllable_LbFR(){
	return LBFR;
}

bool EventControllable_LbMF(){
	return LBMF;
}

bool EventControllable_LbMR(){
	return LBMR;
}

bool EventControllable_LbRF(){
	return LBRF;
}

bool EventControllable_LbRM(){
	return LBRM;
}

bool EventControllable_Gdir(){
	return GdirExa;
}

bool EventControllable_Gesq(){
	return GesqVen;
}

bool EventControllable_Lmis(){
	return Lmis;
}

bool EventControllable_Lmoe(){
	return Lmoe;
}

bool EventControllable_LResF(){
	return LresF;
}

bool EventControllable_LResM(){
	return LresM;
}




// This set of functions should be implemented in a way to handle the uncontrollable events of the system
bool EventUncontrollable_DAgF(){
  DagF = false;
  unsigned long delayMillis = 0; // Variável local para tempo de espera

  switch (FlagAgF) {// Definir o tempo de espera com base no valor de FlagAgF
    case 0:
      delayMillis = 10000; // Limpeza: 10 segundos
      break;
    case 1:
      if (AgFFer) { // Se a condição de fermentação for atingida, define DagF como true
        DagF = true;
		LagF = false;
		FlagAgF = 3;
		agFEnd = true;
      }
      return DagF; // Retorna imediatamente
    case 2:
      delayMillis = 15000; // Misturador: 15 segundos
      break;
    default:
	  delayMillis = -1;
      Serial.println("Valor inválido para a variável global.");
      return false;
  }
  // Verificar se o tempo de espera foi atingido
  if ((millis() - agFTimer >= delayMillis) && delayMillis > 0) {
    DagF = true; // Define DagF como true após o tempo decorrido
	FlagAgF = 3;
	LagF = false;
	agFEnd = true;
  }

  return DagF;
}

bool EventUncontrollable_DAgM(){
  DagM = false;
  unsigned long delayMillis = 0; // Variável local para tempo de espera

  switch (FlagAgM) {// Definir o tempo de espera com base no valor de FlagAgF
    case 0:
      delayMillis = 10000; // Limpeza: 10 segundos
      break;
    case 1:
      if (AgMFer) { // Se a condição de fermentação for atingida, define DagF como true
        DagM = true;
		LagM = false;
		FlagAgM = 3;
		agMEnd = true;
      }
      return DagM; // Retorna imediatamente
    case 2:
      delayMillis = 15000; // Misturador: 15 segundos
      break;
    default:
	  delayMillis = -1;
      Serial.println("Valor inválido para a variável global.");
      return false;
  }

  // Verificar se o tempo de espera foi atingido
  if ((millis() - agMTimer >= delayMillis) && delayMillis > 0) {
    DagM = true; // Define DagM como true após o tempo decorrido
	FlagAgM = 3;
	LagM = false;
	agMEnd = true;
  }

  return DagM;
}

bool EventUncontrollable_DAferF(){
	DAFerF = false;
	unsigned long delayMillis = 0; // Variável local para tempo de espera

        // Usando switch-case para definir diferentes tempos de espera
        switch (FlagAqFerF)
        {
            case 0:
                delayMillis = 8000; // Padrão 8 segundos
                break;
            case 1:
                delayMillis = 15000; // Cozimento 45 segundos
                break;
            default:
				delayMillis =-1;
                Serial.println("Invalido FerF.");
                return false;
        }
  // Verificar se o tempo de espera foi atingido
  if (millis() - aqFerFTimer >= delayMillis && delayMillis > 0) {
	Serial.println("Desligou aquecedor");
    DAFerF = true;
	AferF = false;
	aqFerFEnd = true; 
	FlagAqFerF = 2;//
	
  }

  return DAFerF;
}

bool EventUncontrollable_DApasF(){
    DAPasF = false;

    if (millis() - aqPasFTimer >= 8000 && ApasF && aqPasFTimer > 0) {
        DAPasF = true;
		ApasF = false;
		aqPasFEnd = true;
    }

    return DAPasF;
}

bool EventUncontrollable_DAferM(){
	DAFerM = false;
	unsigned long delayMillis = 0; // Variável local para tempo de espera

        // Usando switch-case para definir diferentes tempos de espera
        switch (FlagAqFerM)
        {
            case 0:
                delayMillis = 8000; // Padrão 8 segundos
                break;
            case 1:
                delayMillis = 15000; // Cozimento 45 segundos
                break;
            default:
				delayMillis =-1;
                Serial.println("Inválido FerM.");
                return false;
        }
  // Verificar se o tempo de espera foi atingido
  if (millis() - aqFerMTimer >= delayMillis && delayMillis > 0) {
    DAFerM = true; // Define DAFerM como true após o tempo decorrido
	FlagAqFerM = 2;
	AferM = false;
	aqFerMEnd = true;
  }
  return DAFerM;
}	

bool EventUncontrollable_DApasM(){
	DAPasM = false;

    if (millis() - aqPasMTimer >= 8000 && ApasM && aqPasMTimer > 0) {
		Serial.println("entrando no if do tempo");
        DAPasM = true;
		ApasM = false;
		aqPasMEnd = true;
    }

    return DAPasM;
}

bool EventUncontrollable_DbFM(){
	DBFM = false;

    switch (FlagBF) {
        case 0:
            if ((HM || LF) && LBFM) {
                DBFM = true;
				LBFM = false;
            }
            return DBFM;
        case 1: // Esvaziando agua pasteurização
            if ((MF || HM) && LBFM) {
                DBFM = true;
				LBFM = false;
            }
            return DBFM;
        default:
            Serial.println("Valor inválido para a variável global.");
            return false;
    }
}

bool EventUncontrollable_DbFR(){
	DBFR = false;
	switch (FlagBF)
        {// Leitura sensor nível
            case 0:
				if((HR||LF) && LBFR){
					DBFR = true;
					LBFR = false;
				}
				return DBFR; 
            case 1:    // Esvaziando o tanque F na Pausteurização até o meio
                if((MF || HR) && LBFR){
					DBFR = true;
					LBFR = false;
				}
                return DBFR;
            default:
            Serial.println("Valor inválido para a variável global.");
            return false;
    }
}

bool EventUncontrollable_DbMF(){
	DBMF = false;
	switch (FlagBM)
        {
            case 0:
				if((HF||LM) && LBMF){
					DBMF = true;
					LBMF = false;
				}
				return DBMF; 
            case 1:    // Esvaziando o tanque M na Pausteurização até o meio
                if((MM || HF) && LBMF){
					DBMF = true;
					LBMF = false;
				}
                return DBMF;
            default:
            Serial.println("Valor inválido para a variável global.");
            return false;
    	} 
}

bool EventUncontrollable_DbMR(){
	DBMR = false;
	switch (FlagBM) {// Leitura sensor nível
            case 0:
				if((HR||LM) && LBMR){
					DBMR = true;
					LBMR = false;
				}
				return DBMR; 
            case 1:    // Esvaziando o tanque F na Pausteurização até o meio
                if((MM || HR) && LBMR){
					DBMR = true;
					LBMR = false;
				}
                return DBMR;
            default:
            Serial.println("Valor inválido para a variável global.");
            return false;
    }
}

bool EventUncontrollable_DbRF(){
	DBRF = false;
	switch (FlagBRF) {
        case 0: // Normal
			if((HF || LR) && LBRF){
				DBRF = true;
				LBRF = false;
			}
			return DBRF;
		case 1: // Encher até metade (Secagem, Moagem)
			if((MF||LR) && LBRF){
				DBRF = true;
				LBRF = false;
			}
			return DBRF; 
		default:
            return false;
	}
}

bool EventUncontrollable_DbRM(){
	DBRM = false;
	switch (FlagBRM)
	{
	case 0: //Normal
		if((HM || LR) && LBRM){
		DBRM = true;
		LBRM = false;
		}
		return DBRM;
	case 1: // Encher até metade (Secagem, Moagem)
		if((MM||LR) && LBRM){
			DBRM = true;
			LBRM = false;
		}
		return DBRM; 	
	default:
		return false;
	}
	
}

bool EventUncontrollable_Dexa(){
	Dexa = false;

    if (millis() - moeTimer >= 15000 && GdirExa && Lmoe) {
        Dexa = true;
		GdirExa = false;
		exaEnd = true;
    }
    return Dexa;
}

bool EventUncontrollable_Dven(){
	Dven = false;

    if (millis() - venTimer >= 20000 && GesqVen) {
        Dven = true;
		GesqVen = false;
		venEnd = true;
    }
    return Dven;
}

bool EventUncontrollable_Dmis(){
	Dmis = false;

    if (millis() - misTimer >= 15000 && Lmis) {
        Dmis = true;
		Lmis = false;
		misEnd = true;
    }
    return Dmis;
}

bool EventUncontrollable_Dmoe(){
	Dmoe = false;

    if (millis() - moeTimer >= 15000 && Lmoe) {
        Dmoe = true;
		Lmoe = false;
		moeEnd = true;
    }
    return Dmoe;
}

bool EventUncontrollable_DResF(){
	DresF = false;
	if(FF && LresF){
		DresF = true;
		LresF = false;
	}
	return DresF;
}

bool EventUncontrollable_DResM(){
	DresM = false;
	if(FM && LresM){
		DresM = true;
		LresM = false;
	}
	return DresM;
}

bool EventUncontrollable_MF(){
	MF = false;
    if (DistF > NIVEL_MEDIO_INFERIOR_F && DistF <= NIVEL_MEDIO_SUPERIOR_F && NivelAtualF != 1) {
        MF = true; // Pulso detectado
        NivelAtualF = 1; // Atualiza o estado atual para MF
    }
    return MF;
}

bool EventUncontrollable_HF(){
	HF = false;
    if (DistF <= NIVEL_ALTO_F && NivelAtualF != 2) {
        HF = true; // Pulso detectado
        NivelAtualF = 2; // Atualiza o estado atual para HF
    }
    return HF;
}

bool EventUncontrollable_LF(){
	LF = false;
    if (DistF >= NIVEL_BAIXO_F && NivelAtualF != 0) {
        LF = true; // Pulso detectado
        NivelAtualF = 0; // Atualiza o estado atual para LF
    }
    return LF;
}

bool EventUncontrollable_MM(){
	MM = false;
    if (DistM > NIVEL_MEDIO_INFERIOR_M && DistM <= NIVEL_MEDIO_SUPERIOR_M && NivelAtualM != 1) {
        MM = true; // Pulso detectado
        NivelAtualM = 1; // Atualiza o estado atual para MM
    }
    return MM;
}

bool EventUncontrollable_HM(){
	HM = false;
    if (DistM <= NIVEL_ALTO_M && NivelAtualM != 2) {
        HM = true; // Pulso detectado
        NivelAtualM = 2; // Atualiza o estado atual para HM
    }
    return HM;
}

bool EventUncontrollable_LM(){
	LM = false;
    if (DistM >= NIVEL_BAIXO_M && NivelAtualM != 0) {
        LM = true; // Pulso detectado
        NivelAtualM = 0; // Atualiza o estado atual para LM
    }
    return LM;
}

bool EventUncontrollable_MR(){
	MR = false;
    if (DistR > NIVEL_MEDIO_INFERIOR_R && DistR <= NIVEL_MEDIO_SUPERIOR_R && NivelAtualR != 1) {
        MR = true; // Pulso detectado
        NivelAtualR = 1; // Atualiza o estado atual para MR
    }
    return MR;
}

bool EventUncontrollable_HR(){
	HR = false;
    if (DistR <= NIVEL_ALTO_R && NivelAtualR != 2) {
        HR = true; // Pulso detectado
        NivelAtualR = 2; // Atualiza o estado atual para HR
    }
    return HR;
}

bool EventUncontrollable_LR(){
	LR = false;
    if (DistR >= NIVEL_BAIXO_R && NivelAtualR != 0) {
        LR = true; // Pulso detectado
        NivelAtualR = 0; // Atualiza o estado atual para LR
    }
    return LR;
}

bool EventUncontrollable_FF(){
	FF = false;
	if (TempF <= TEMP_FRIA_F && StatusTempAtualF != 0){
		FF = true;
        Serial.println("Frio");
		StatusTempAtualF = 0; // Atualiza o estado para Frio
    }
	return FF;
}

bool EventUncontrollable_QferF(){
	QFerF = false;
	if (TempF > TEMP_FERMENTACAO && StatusTempAtualF != 2){
        QFerF = true;
        Serial.println("Temperatura de fermentação atingida.");
		StatusTempAtualF = 2; // Atualiza o estado para TFermentação
    }
	return QFerF;
}

bool EventUncontrollable_QpasF(){
	QPasF = false;
	if (TempF >= TEMP_PASTEURIZACAO && TempF <= TEMP_FERMENTACAO && StatusTempAtualF != 1){
        QPasF = true;
        Serial.println("Temperatura de pasteurização atingida.");
		StatusTempAtualF = 1; // Atualiza o estado para TPasteurizacao
    }
	return QPasF;
}

bool EventUncontrollable_FM(){
	FM = false;
	if (TempM <= TEMP_FRIA_M && StatusTempAtualM != 0){
		FM = true;
        Serial.println("Frio");
		StatusTempAtualM = 0; // Atualiza o estado para Frio
    }
	return FM;
}

bool EventUncontrollable_QferM(){
	QFerM = false;
	if (TempM > TEMP_FERMENTACAO && StatusTempAtualM != 2){
        QFerM = true;
        Serial.println("Temperatura de fermentação atingida.");
		StatusTempAtualM = 2; // Atualiza o estado para TFermentação
    }
	return QFerM;
}

bool EventUncontrollable_QpasM(){
	QPasM = false;
	if (TempM >= TEMP_PASTEURIZACAO && TempM <= TEMP_FERMENTACAO && StatusTempAtualM != 1){
        QPasM = true;
        Serial.println("Temperatura de pasteurização atingida.");
		StatusTempAtualM = 1; // Atualiza o estado para TPasteurizacao
    }
	return QPasM;
}
// Here the expected actions should be implemented in each state of the system
void StateActionAutomaton0_AgFState0()
{
	digitalWrite(AgF, false);
	Serial.println("A0S0");
 	
}

void StateActionAutomaton0_AgFState1()
{
	digitalWrite(AgF, true);
	Serial.println("A0S1");
 	
}

void StateActionAutomaton1_AgMState0()
{
	digitalWrite(AgM, false);
	Serial.println("A1S0");
 	
}

void StateActionAutomaton1_AgMState1()
{
	digitalWrite(AgM, true);
	Serial.println("A1S1");
 	
}

void StateActionAutomaton2_AqFState0()
{
	digitalWrite(FerF, false);
	digitalWrite(PasF, false);
	Serial.println("A2S0");
 	
}

void StateActionAutomaton2_AqFState1()
{
	digitalWrite(FerF, true);
	//digitalWrite(PasF, false);
	Serial.println("A2S1");
 	
}

void StateActionAutomaton2_AqFState2()
{
	digitalWrite(FerF, true);
	//digitalWrite(PasF, false);
	Serial.println("A2S2");
 	
}

void StateActionAutomaton3_AqMState0()
{
	digitalWrite(FerM, false);
	digitalWrite(PasM, false);
	Serial.println("A3S0");
 	
}

void StateActionAutomaton3_AqMState1()
{
	digitalWrite(FerM, true);
	//digitalWrite(PasM, false);
	Serial.println("A3S1");
 	
}

void StateActionAutomaton3_AqMState2()
{
	digitalWrite(FerM, true);
	//digitalWrite(PasM, false);
	Serial.println("A3S2");
 	
}

void StateActionAutomaton4_BFMState0()
{
	digitalWrite(BFM, false);
	Serial.println("A4S0");
 	
}

void StateActionAutomaton4_BFMState1()
{
	digitalWrite(BFM, true);
	Serial.println("A4S1");
 	
}

void StateActionAutomaton5_BFRState0()
{
	digitalWrite(BFR, false);
	Serial.println("A5S0");
 	
}

void StateActionAutomaton5_BFRState1()
{
	digitalWrite(BFR, true);
	Serial.println("A5S1");
 	
}

void StateActionAutomaton6_BMFState0()
{
	digitalWrite(BMF, false);
	Serial.println("A6S0");
 	
}

void StateActionAutomaton6_BMFState1()
{
	digitalWrite(BMF, true);
	Serial.println("A6S1");
 	
}

void StateActionAutomaton7_BMRState0()
{
	digitalWrite(BMR, false);
	Serial.println("A7S0");
 	
}

void StateActionAutomaton7_BMRState1()
{
	digitalWrite(BMR, true);
	Serial.println("A7S1");
 	
}

void StateActionAutomaton8_BRFState0()
{
	digitalWrite(BRF, false);
	Serial.println("A8S0");
 	
}

void StateActionAutomaton8_BRFState1()
{
	digitalWrite(BRF, true);
	Serial.println("A8S1");
 	
}

void StateActionAutomaton9_BRMState0()
{
	digitalWrite(BRM, false);
	Serial.println("A9S0");
 	
}

void StateActionAutomaton9_BRMState1()
{
	digitalWrite(BRM, true);
	Serial.println("A9S1");
 	
}

void StateActionAutomaton10_ExaVenState0()
{
	digitalWrite(ExaVen, false);
	Serial.println("A10S0");
 	
}

void StateActionAutomaton10_ExaVenState1()
{
	digitalWrite(ExaVen, true);
	Serial.println("A10S1");
 	
}

void StateActionAutomaton10_ExaVenState2()
{
	digitalWrite(ExaVen, true);
	Serial.println("A10S2");
 	
}

void StateActionAutomaton11_MisState0()
{
	digitalWrite(Misturador, false);
	Serial.println("A11S0");
 	
}

void StateActionAutomaton11_MisState1()
{
	digitalWrite(Misturador, true);
	Serial.println("A11S1");
 	
}

void StateActionAutomaton12_MoedorState0()
{
	digitalWrite(Moedor, false);
	Serial.println("A12S0");
 	
}

void StateActionAutomaton12_MoedorState1()
{
	digitalWrite(Moedor, true);
	Serial.println("A12S1");
 	
}

void StateActionAutomaton13_ResFState0()
{
	digitalWrite(ResF, false);
	Serial.println("A13S0");
 	
}

void StateActionAutomaton13_ResFState1()
{
	digitalWrite(ResF, true);
	Serial.println("A13S1");

}

void StateActionAutomaton14_ResMState0()
{
	digitalWrite(ResM, false);
	Serial.println("A14S0");

}

void StateActionAutomaton14_ResMState1()
{
	digitalWrite(ResM, true);
	Serial.println("A14S1");
}

void StateActionAutomaton15_SnFState0()
{
	DistF = SnF.dist();
	Serial.print("Nível F:");
	Serial.println(DistF);
	Serial.println("A15S0");
}

void StateActionAutomaton16_SnMState0()
{
	Serial.println(SnM.dist() );
    DistM = SnM.dist(); //return current distance (cm) in serial
	Serial.print("Nível M:");
	Serial.println(DistM);
	Serial.println("A16S0");
}

void StateActionAutomaton17_SnRState0()
{
	DistR = SnR.dist();
	Serial.print("Nível R:");
	Serial.println(DistR);
	Serial.println("A17S0");
}

void StateActionAutomaton18_StFState0()
{
	
  	StempF.requestTemperatures();    // Send command to get temperatures
  	TempF = StempF.getTempCByIndex(0);
  	Serial.print("Temperature from StempF is: ");
  	Serial.println(StempF.getTempCByIndex(0));
	Serial.println("A18S0");
}

void StateActionAutomaton19_StMState0()
{
	 StempM.requestTemperatures();
  	TempM = StempM.getTempCByIndex(0);
  	Serial.print("Temperature from StempM is: ");
  	Serial.println(StempM.getTempCByIndex(0));
	Serial.println("A19S0");
}
 
