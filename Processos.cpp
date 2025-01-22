#include "Automaton.h"

int estadoLimpeza = 0, estadoMoagem = 0, estadoFermentacao = 0, estadoPasteurizacao = 0, estadoSecagem = 0, estadoMistura = 0, estadoCozimento = 0;
bool tanqueMOcupado = false, tanqueFOcupado = false;

void executarLimpeza() { //TANQUE M
  switch (estadoLimpeza) {
    case 0: //INICIO_LIMPEZA - enche tanque:
    Serial.println("Estado zero Limpeza");
      if (!DBRM){
        tanqueMOcupado = true;
        LBRM = true;
        FlagBRM = 0;
      }
      if(DBRM){
        estadoLimpeza++;
      }
      break;
    case 1:// LIGA Agitador
        if (agMEnd && !DagM) {
            Serial.println("Liga agitador ");
            FlagAgM = 0;
            LagM = true;
            agMTimer = millis();
            agMEnd = false;  // Marca o processo como iniciado
        }
        if (!LagM /*ou DagM*/ && agMEnd){ // Agitador desligado e processo finalizado
          estadoLimpeza++;
        }
        break;
    case 2:// Esvazia o tanque
    Serial.println("Esvazia o tanque");
      if (!DBMR){ //automata[0].getActualState()){
        LBMR = true;
        FlagBM = 0;
      } else{
        estadoLimpeza++;
      }
      break;
    case 3: // FIM LIMPEZA
      Serial.println("Fim da Limpeza");
      tanqueMOcupado = false;
      estadoLimpeza++;
      break;

    default:
      estadoLimpeza = -1;
  }
}

void executarSecagem() {// TANQUE M
  switch (estadoSecagem) {
    case 0:  //INICIO_SECAGEM - enche tanque:
    Serial.println("Estado zero Secagem - enche tanque M");
      if (!DBRM){
        tanqueMOcupado = true;
        LBRM = true;
        FlagBRM = 1; // Até metade
      }
      if(DBRM){
        estadoSecagem++;
      }
      break;
    case 1:// LIGA_Ventilador
      Serial.println("Liga Ventilador");
      if (venEnd && !Dven) {
        GesqVen = true;
        tanqueMOcupado = true;
        venTimer = millis();
        venEnd = false;  // Marca o processo como iniciado
      }
      if (Dven && venEnd){ // Ventilador desligado e processo finalizado
          estadoSecagem++;
      }
      break;
    case 2:// Esvazia o tanque
      Serial.println("Esvazia tanque M");
      if (!DBMR){ 
        LBMR = true;
        FlagBM = 0;
      } else{
        estadoSecagem++;
      }
      break;
    case 3: 
      Serial.println("Fim da Secagem");
      tanqueMOcupado = false;
      estadoSecagem++;
      break;

    default:
      estadoSecagem = -1;
  }
}

void executarMoagem() { // TANQUE M

  switch (estadoMoagem) {
    case 0: //INICIO_MOAGEM - enche tanque:
    Serial.println("Inicio Moagem - enche tanque M até metade");
      if (!DBRM){
        tanqueMOcupado = true;
        LBRM = true;
        FlagBRM = 1; // Até metade
      }
      if(DBRM){
        estadoMoagem++;
      }
      break;
    case 1:// 
    Serial.println("Liga Exaustor ");
      if (exaEnd && !Dexa) {//LIGA_exaustor
      Serial.println("Exaustor Ligou");
        GdirExa = true;
        tanqueMOcupado = true;
        exaEnd = false;
      }
      if (GdirExa){  // Marca o processo como iniciado
        estadoMoagem++;
      } else {
        GdirExa = true;
      }
      
      break;
    case 2: 
      Serial.println("Ligar Moedor");
      if (moeEnd && !Dmoe && GdirExa){//LIGA_moedor
      Serial.println(" Moedor ligou");
        Lmoe = true;
        moeTimer = millis();
        moeEnd = false;
      }
      if (Dmoe && moeEnd){ // MOEDOR E EXAUSTOR desligados e processos finalizados
          estadoMoagem++;
      }
      break;
    case 3:// Esvazia o tanque
    Serial.println("Esvazia tanque M");
      if (!DBMR){ 
        LBMR = true;
        FlagBM = 0;
      } else{
        estadoMoagem++;
      }
      break;
    case 4: 
      Serial.println("Fim da Moagem");
      tanqueMOcupado = false;
      estadoMoagem++;
      break;

    default:
      estadoMoagem = -1;
  }
}

void executarFermentacao() { //TANQUE F
  switch (estadoFermentacao) {
    case 0: //INICIO - enche tanque:
      if (!DBRF){
        tanqueFOcupado = true;
        LBRF = true;
        FlagBRF = 0;
      } else {
        estadoFermentacao++;
      }
      break;
    case 1:// LIGA Agitador
        if (agFEnd && !DagF) {
            LagF = true;
            FlagAgF = 1;
            agFEnd = false;  // Marca o processo como iniciado
            estadoFermentacao++;
        }
        break;
    case 2: // LIGA AQUECEDOR 
        if(aqFerFEnd && !DAFerF) {
          AferF = true;
        }
        if(QFerF){
          estadoFermentacao++;
        }
        break;
    case 3: // MANTEM pelo tempo definido
        if(aqFerFEnd && !DAFerF) {
          aqFerFTimer = millis();
          FlagAqFerF = 0;
          aqFerFEnd = false;
        }
        if(aqFerFEnd && DAFerF){
          estadoFermentacao++;
        }
        break;
    case 4: // RESFRIA
        if(!DresF) {
          LresF = true;
        }
        if(DresF){ 
          estadoFermentacao++;
        }
        break;
    case 5: // SINALIZA o momento de desligar o agitador
        if(!DagF){
          AgFFer = true;
        }
        if(DagF) {
          AgFFer = false;
          estadoFermentacao++;
        }
        break;
    case 6:// ESVAZIA a agua 
      if (!DBFR){
        LBFR = true;
        FlagBF = 0;
      } else{
        estadoFermentacao++;
      }
      break;
    case 7: // FIM Fermentação
      Serial.println("Fim da Fermentacao");
      tanqueFOcupado = false;
      estadoFermentacao++;
      break;
    default:
      estadoFermentacao = -1;
  }
}

void executarPasteurizacao() { // TANQUE M
  switch (estadoPasteurizacao) {
    case 0: //INICIO - enche tanque:
      Serial.println("enche tanque");
      if (!DBRM){
        tanqueMOcupado = true;
        LBRM = true;
        FlagBRM = 0;
      } else {
        estadoPasteurizacao++;
        //digitalWrite(PasM, false);
      }
      break;
    case 1: // LIGA AQUECEDOR 
        //Serial.println(aqMEnd);
        Serial.println("liga aquecedor");
        if(aqPasMEnd && !DAPasM) {
          Serial.println("ligou aquecedor");
          ApasM = true;
        }
        if(QPasM || QFerM){
          estadoPasteurizacao++;
        }
        break;
    case 2: // MANTEM pelo tempo definido
        Serial.println(aqPasMEnd);
        if(aqPasMEnd && !DAPasM) {
          Serial.println("começou o tempo");
          aqPasMTimer = millis();
          aqPasMEnd = false;
        }
        if(aqPasMEnd && DAPasM){
          //aqPasMEnd = true;
          estadoPasteurizacao++;
        }
        break;
    case 3: // REDUZ agua até metade
        if (!DBMR){
          LBMR = true;
          FlagBM = 1;
        } else{
          estadoPasteurizacao++;
        }
        break;
    case 4:  // RESFRIA
        if(!DresM) {
          Serial.println("Resfria");
          LresM = true;
        }
        if(DresM){ 
          estadoPasteurizacao++;
        }
        break;
    case 5:// ESVAZIA a agua 
      if (!DBMR){
        LBMR = true;
        FlagBM = 0;
      } else{
        estadoPasteurizacao++;
      }
      break;
    case 6: // FIM PATEURIZACAO
      Serial.println("Fim da Pasteurizacao");
      tanqueMOcupado = false;
      estadoPasteurizacao++;
      break;
    default:
      estadoPasteurizacao = -1;
  }
}

void executarCozimento() { // TANQUE F
  switch (estadoCozimento) {
    case 0: //INICIO - enche tanque:
    Serial.println("enche tanque - inicio cozimento");
      if (!DBRF){
        tanqueFOcupado = true;
        LBRF = true;
        FlagBRF = 0;
      } else {
        estadoCozimento++;
      }
      break;
    case 1: // LIGA AQUECEDOR 
        if(aqFerFEnd && !DAFerF) {
          Serial.println("aquecedor ligou");
          AferF = true;
        }
        if(QFerF){
          estadoCozimento++;
        }
        break;
    case 2: // MANTEM pelo tempo definido
        if(aqFerFEnd && !DAFerF) {
          FlagAqFerF = 1;
          aqFerFTimer = millis();
          aqFerFEnd = false;
        }
        Serial.println("aqFEnd:");
        Serial.println(aqFerFEnd);
        Serial.println("DAqF:");
        Serial.println(DAFerF);

        if(!AferF){
          aqFerFEnd = true;
          Serial.println("passou pro esvaziar");
          estadoCozimento++;
        }
        break;
    case 3: // ESVAZIA a agua 
    Serial.println("esvazia a agua");
        if (!DBFR){
          LBFR = true;
          FlagBF = 0;
        } else{
          estadoCozimento++;
        }
        break;
    case 4: // FIM Cozimento
      Serial.println("Fim do Cozimento");
      tanqueFOcupado = false;
      estadoCozimento++;
      break;
    default:
      estadoCozimento = -1;
  }
}

void executarMistura() { //TANQUE F
  switch (estadoMistura) {
    Serial.println("Inicio Mistura");
    case 0: //INICIO - enche tanque:
      if (!DBRF){
        tanqueFOcupado = true;
        LBRF = true;
        FlagBRF = 0;
      } else {
          estadoMistura++;
      }
      break;
    case 1:// LIGA Agitador
    Serial.println("ligar agitador");
        if (agFEnd && !DagF) {
          Serial.println("agitador ligou");
            LagF = true;
            agFTimer = millis();
            FlagAgF = 2;
            agFEnd = false;  // Marca o processo como iniciado
            estadoMistura++;
        }
        break;
    case 2:// LIGA Pá de Fundo
        if (misEnd && !Dmis) {
          Serial.println("pá de fundo ligou");
            Lmis = true;
            misTimer = millis();
            misEnd = false;  // Marca o processo como iniciado
        }
        if(misEnd && Dmis ){
            estadoMistura++;
        }
        break;
    case 3: // ESVAZIA a agua 
    Serial.println("esvazia agua");
        if (!DBFR){
          LBFR = true;
          FlagBF = 0;
        } else{
          estadoMistura++;
        }
        break;
    case 4: // FIM Mistura
      Serial.println("Fim da Mistura");
      tanqueFOcupado = false;
      estadoMistura++;
      break;
    default:
      estadoMistura = -1;
  }
}







    
