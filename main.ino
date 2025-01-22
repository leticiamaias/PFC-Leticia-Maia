#include "Automaton.h"
#include "Event.h"

// Define the number of automatons
#define NUMBER_AUTOMATON 20
#define NUMBER_SUPERVISOR 11

int actualState;

// Functions
void executeTransition(Event eventOccurred);

// Initialize Events
int firstEventUncontrollable = 0;
int firstEventControllable = 0;

Event eventControllable = createEvent();
Event eventUncontrollable = createEvent();

Event eventEnabledControllable = createEvent();
Event eventEnabledUncontrollable = createEvent();

Event emptyEvent = createEvent();
Event eventEnabled = createEvent();

Event eventOccurred = createEvent();

// Create a vector to store the automatons
Automaton automata[NUMBER_AUTOMATON];
Automaton supervisor[NUMBER_SUPERVISOR];

uint8_t eventDataAUT0EV0[7] = {0b11111011, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT0EV1[7] = {0b11111101, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton0[2] = { createEventFromData(eventDataAUT0EV0), createEventFromData(eventDataAUT0EV1)};
uint8_t eventDataAUT1EV0[7] = {0b11111110, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT1EV1[7] = {0b11111111, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton1[2] = { createEventFromData(eventDataAUT1EV0), createEventFromData(eventDataAUT1EV1)};
uint8_t eventDataAUT2EV0[7] = {0b11111111, 0b10011111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT2EV1[7] = {0b11111111, 0b11000111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT2EV2[7] = {0b11111111, 0b10100111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton2[3] = { createEventFromData(eventDataAUT2EV0), createEventFromData(eventDataAUT2EV1), createEventFromData(eventDataAUT2EV2)};
uint8_t eventDataAUT3EV0[7] = {0b11111111, 0b11111001, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT3EV1[7] = {0b11111111, 0b11111100, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT3EV2[7] = {0b11111111, 0b11111010, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton3[3] = { createEventFromData(eventDataAUT3EV0), createEventFromData(eventDataAUT3EV1), createEventFromData(eventDataAUT3EV2)};
uint8_t eventDataAUT4EV0[7] = {0b11111111, 0b11111111, 0b10111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT4EV1[7] = {0b11111111, 0b11111111, 0b11011111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton4[2] = { createEventFromData(eventDataAUT4EV0), createEventFromData(eventDataAUT4EV1)};
uint8_t eventDataAUT5EV0[7] = {0b11111111, 0b11111111, 0b11101111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT5EV1[7] = {0b11111111, 0b11111111, 0b11110111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton5[2] = { createEventFromData(eventDataAUT5EV0), createEventFromData(eventDataAUT5EV1)};
uint8_t eventDataAUT6EV0[7] = {0b11111111, 0b11111111, 0b11111011, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT6EV1[7] = {0b11111111, 0b11111111, 0b11111101, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton6[2] = { createEventFromData(eventDataAUT6EV0), createEventFromData(eventDataAUT6EV1)};
uint8_t eventDataAUT7EV0[7] = {0b11111111, 0b11111111, 0b11111110, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT7EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b01111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton7[2] = { createEventFromData(eventDataAUT7EV0), createEventFromData(eventDataAUT7EV1)};
uint8_t eventDataAUT8EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b10111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT8EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11011111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton8[2] = { createEventFromData(eventDataAUT8EV0), createEventFromData(eventDataAUT8EV1)};
uint8_t eventDataAUT9EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11101111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT9EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11110111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton9[2] = { createEventFromData(eventDataAUT9EV0), createEventFromData(eventDataAUT9EV1)};
uint8_t eventDataAUT10EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111001, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT10EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111100, 0b01111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT10EV2[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111010, 0b01111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton10[3] = { createEventFromData(eventDataAUT10EV0), createEventFromData(eventDataAUT10EV1), createEventFromData(eventDataAUT10EV2)};
uint8_t eventDataAUT11EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b10111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT11EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11011111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton11[2] = { createEventFromData(eventDataAUT11EV0), createEventFromData(eventDataAUT11EV1)};
uint8_t eventDataAUT12EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11101111, 0b11111111, 0b11111111};
uint8_t eventDataAUT12EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton12[2] = { createEventFromData(eventDataAUT12EV0), createEventFromData(eventDataAUT12EV1)};
uint8_t eventDataAUT13EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111011, 0b11111111, 0b11111111};
uint8_t eventDataAUT13EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111101, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton13[2] = { createEventFromData(eventDataAUT13EV0), createEventFromData(eventDataAUT13EV1)};
uint8_t eventDataAUT14EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111110, 0b11111111, 0b11111111};
uint8_t eventDataAUT14EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b01111111, 0b11111111};

Event enabledEventStatesAutomaton14[2] = { createEventFromData(eventDataAUT14EV0), createEventFromData(eventDataAUT14EV1)};
uint8_t eventDataAUT15EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton15[1] = { createEventFromData(eventDataAUT15EV0)};
uint8_t eventDataAUT16EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton16[1] = { createEventFromData(eventDataAUT16EV0)};
uint8_t eventDataAUT17EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton17[1] = { createEventFromData(eventDataAUT17EV0)};
uint8_t eventDataAUT18EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton18[1] = { createEventFromData(eventDataAUT18EV0)};
uint8_t eventDataAUT19EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton19[1] = { createEventFromData(eventDataAUT19EV0)};
uint8_t eventDataAUT20EV0[7] = {0b11111111, 0b11111111, 0b11010111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT20EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton20[2] = { createEventFromData(eventDataAUT20EV0), createEventFromData(eventDataAUT20EV1)};
uint8_t eventDataAUT21EV0[7] = {0b11111111, 0b11111111, 0b11111101, 0b01111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT21EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton21[2] = { createEventFromData(eventDataAUT21EV0), createEventFromData(eventDataAUT21EV1)};
uint8_t eventDataAUT22EV0[7] = {0b11111111, 0b11111111, 0b11110111, 0b01111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT22EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton22[2] = { createEventFromData(eventDataAUT22EV0), createEventFromData(eventDataAUT22EV1)};
uint8_t eventDataAUT23EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT23EV1[7] = {0b11111111, 0b11111111, 0b11111101, 0b11011111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton23[2] = { createEventFromData(eventDataAUT23EV0), createEventFromData(eventDataAUT23EV1)};
uint8_t eventDataAUT24EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT24EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11010111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton24[2] = { createEventFromData(eventDataAUT24EV0), createEventFromData(eventDataAUT24EV1)};
uint8_t eventDataAUT25EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
uint8_t eventDataAUT25EV1[7] = {0b11111111, 0b11111111, 0b11011111, 0b11110111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton25[2] = { createEventFromData(eventDataAUT25EV0), createEventFromData(eventDataAUT25EV1)};
uint8_t eventDataAUT26EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110111, 0b11111111, 0b11111111};
uint8_t eventDataAUT26EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton26[2] = { createEventFromData(eventDataAUT26EV0), createEventFromData(eventDataAUT26EV1)};
uint8_t eventDataAUT27EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111101, 0b11111111, 0b11111111};
uint8_t eventDataAUT27EV1[7] = {0b11111111, 0b11100111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton27[2] = { createEventFromData(eventDataAUT27EV0), createEventFromData(eventDataAUT27EV1)};
uint8_t eventDataAUT28EV0[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b01111111, 0b11111111};
uint8_t eventDataAUT28EV1[7] = {0b11111111, 0b11111110, 0b01111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton28[2] = { createEventFromData(eventDataAUT28EV0), createEventFromData(eventDataAUT28EV1)};
uint8_t eventDataAUT29EV0[7] = {0b11111101, 0b11100111, 0b11111111, 0b11111111, 0b11011101, 0b11111111, 0b11111111};
uint8_t eventDataAUT29EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton29[2] = { createEventFromData(eventDataAUT29EV0), createEventFromData(eventDataAUT29EV1)};
uint8_t eventDataAUT30EV0[7] = {0b11111111, 0b01111110, 0b01111111, 0b11111110, 0b01110111, 0b01111111, 0b11111111};
uint8_t eventDataAUT30EV1[7] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};

Event enabledEventStatesAutomaton30[2] = { createEventFromData(eventDataAUT30EV0), createEventFromData(eventDataAUT30EV1)};


void setup()
{

    // Initialize the automatons
    
		automata[0] = Automaton(2,enabledEventStatesAutomaton0,&MakeTransitionAutomaton0_AgF,&Automaton0Loop_AgF);
		automata[1] = Automaton(2,enabledEventStatesAutomaton1,&MakeTransitionAutomaton1_AgM,&Automaton1Loop_AgM);
		automata[2] = Automaton(3,enabledEventStatesAutomaton2,&MakeTransitionAutomaton2_AqF,&Automaton2Loop_AqF);
		automata[3] = Automaton(3,enabledEventStatesAutomaton3,&MakeTransitionAutomaton3_AqM,&Automaton3Loop_AqM);
		automata[4] = Automaton(2,enabledEventStatesAutomaton4,&MakeTransitionAutomaton4_BFM,&Automaton4Loop_BFM);
		automata[5] = Automaton(2,enabledEventStatesAutomaton5,&MakeTransitionAutomaton5_BFR,&Automaton5Loop_BFR);
		automata[6] = Automaton(2,enabledEventStatesAutomaton6,&MakeTransitionAutomaton6_BMF,&Automaton6Loop_BMF);
		automata[7] = Automaton(2,enabledEventStatesAutomaton7,&MakeTransitionAutomaton7_BMR,&Automaton7Loop_BMR);
		automata[8] = Automaton(2,enabledEventStatesAutomaton8,&MakeTransitionAutomaton8_BRF,&Automaton8Loop_BRF);
		automata[9] = Automaton(2,enabledEventStatesAutomaton9,&MakeTransitionAutomaton9_BRM,&Automaton9Loop_BRM);
		automata[10] = Automaton(3,enabledEventStatesAutomaton10,&MakeTransitionAutomaton10_ExaVen,&Automaton10Loop_ExaVen);
		automata[11] = Automaton(2,enabledEventStatesAutomaton11,&MakeTransitionAutomaton11_Mis,&Automaton11Loop_Mis);
		automata[12] = Automaton(2,enabledEventStatesAutomaton12,&MakeTransitionAutomaton12_Moedor,&Automaton12Loop_Moedor);
		automata[13] = Automaton(2,enabledEventStatesAutomaton13,&MakeTransitionAutomaton13_ResF,&Automaton13Loop_ResF);
		automata[14] = Automaton(2,enabledEventStatesAutomaton14,&MakeTransitionAutomaton14_ResM,&Automaton14Loop_ResM);
		automata[15] = Automaton(1,enabledEventStatesAutomaton15,&MakeTransitionAutomaton15_SnF,&Automaton15Loop_SnF);
		automata[16] = Automaton(1,enabledEventStatesAutomaton16,&MakeTransitionAutomaton16_SnM,&Automaton16Loop_SnM);
		automata[17] = Automaton(1,enabledEventStatesAutomaton17,&MakeTransitionAutomaton17_SnR,&Automaton17Loop_SnR);
		automata[18] = Automaton(1,enabledEventStatesAutomaton18,&MakeTransitionAutomaton18_StF,&Automaton18Loop_StF);
		automata[19] = Automaton(1,enabledEventStatesAutomaton19,&MakeTransitionAutomaton19_StM,&Automaton19Loop_StM);
		supervisor[0] = Automaton(2,enabledEventStatesAutomaton20,&MakeTransitionAutomaton20_SupBFMBFRSnFBFReFMcTF,&Automaton20Loop_SupBFMBFRSnFBFReFMcTF);
		supervisor[1] = Automaton(2,enabledEventStatesAutomaton21,&MakeTransitionAutomaton21_SupBMFBMRSnMBMReMFcTM,&Automaton21Loop_SupBMFBMRSnMBMReMFcTM);
		supervisor[2] = Automaton(2,enabledEventStatesAutomaton22,&MakeTransitionAutomaton22_SupBMRBFRSnRBMReFRcTR,&Automaton22Loop_SupBMRBFRSnRBMReFRcTR);
		supervisor[3] = Automaton(2,enabledEventStatesAutomaton23,&MakeTransitionAutomaton23_SupBRFBMFSnFBMFeRFcTF,&Automaton23Loop_SupBRFBMFSnFBMFeRFcTF);
		supervisor[4] = Automaton(2,enabledEventStatesAutomaton24,&MakeTransitionAutomaton24_SupBRFBRMSnRBRFeRMcTR,&Automaton24Loop_SupBRFBRMSnRBRFeRMcTR);
		supervisor[5] = Automaton(2,enabledEventStatesAutomaton25,&MakeTransitionAutomaton25_SupBRMBFMSnMBFMeRMcTM,&Automaton25Loop_SupBRMBFMSnMBFMeRMcTM);
		supervisor[6] = Automaton(2,enabledEventStatesAutomaton26,&MakeTransitionAutomaton26_SupExaVenMoedorEXAcMOE,&Automaton26Loop_SupExaVenMoedorEXAcMOE);
		supervisor[7] = Automaton(2,enabledEventStatesAutomaton27,&MakeTransitionAutomaton27_SupResFAqFStFTFcAQeRES,&Automaton27Loop_SupResFAqFStFTFcAQeRES);
		supervisor[8] = Automaton(2,enabledEventStatesAutomaton28,&MakeTransitionAutomaton28_SupResMAqMStMTMcAQeRES,&Automaton28Loop_SupResMAqMStMTMcAQeRES);
		supervisor[9] = Automaton(2,enabledEventStatesAutomaton29,&MakeTransitionAutomaton29_SupSnFAgFResFAqFMisTFcSn,&Automaton29Loop_SupSnFAgFResFAqFMisTFcSn);
		supervisor[10] = Automaton(2,enabledEventStatesAutomaton30,&MakeTransitionAutomaton30_SupSnMExaVenAgMResMAqMMoedorTMcSn,&Automaton30Loop_SupSnMExaVenAgMResMAqMMoedorTMcSn);

    Serial.begin(9600);
    setupPin();
}

// Execute the main cycle
void loop()
{

    // Get the system events
    doEveryLoop();
    getEventControllable(eventControllable);
    getEventUncontrollable(eventUncontrollable);

    // Free the events that are physically possible
    zeroEvent(eventEnabled);
    // Check the events that are physically possible
    for (int i = 0; i < NUMBER_AUTOMATON; i++)
    {
        actualState = automata[i].getActualState();
        bitwiseOr(eventEnabled, eventEnabled, automata[i].enabledEventStates[actualState]);
    }

    bitwiseAnd(eventEnabledUncontrollable, eventUncontrollable, eventEnabled);
    bitwiseAnd(eventEnabledControllable, eventControllable, eventEnabled);
    //Serial.println(getBit(eventEnabledControllable, EVENT_LBRM));
    printEvent(eventEnabledUncontrollable);
    //printEvent(eventEnabledControllable);
    //printEvent(eventControllable);
    printEvent(eventUncontrollable);
    if (!areEqual(eventEnabledUncontrollable, emptyEvent))
    {
        //Serial.println("Chegou dentro if");
        for (int i = 0; i < NUMBER_EVENT; i++)
        {
            //Serial.println("Chegou dentro for");
            int index = (firstEventUncontrollable + i) % NUMBER_EVENT;
            // Get one Uncontrollable Event each time
            bool existEvent = getBit(eventEnabledUncontrollable, index);
            if (existEvent)
            {   
                //Serial.println(index);
                setBit(eventOccurred, index, true);
                executeTransition(eventOccurred);
                setBit(eventUncontrollable, index, false);

                zeroEvent(eventOccurred);
                continue;
            }
        }

        zeroEvent(eventEnabledUncontrollable);
        firstEventUncontrollable = (firstEventUncontrollable + 1) % NUMBER_EVENT;
    }
    else
    {
        //Serial.println("Chegou dentro do else cont");
        // Check the enabled events
        oneEvent(eventEnabled);
        //printEvent(eventEnabled);
        for (int i = 0; i < NUMBER_SUPERVISOR; i++)
        {
            bitwiseAnd(eventEnabled, eventEnabled, supervisor[i].getEnabledEvent());
        }
        //printEvent(eventEnabled);
        // Check if any enabled Controllable event was detected
        bitwiseAnd(eventEnabledControllable, eventEnabledControllable, eventEnabled);

        printEvent(eventEnabledControllable);
        printEvent(eventControllable);
        if (!areEqual(eventEnabledControllable, emptyEvent))
        {
            //Serial.println("Chegou dentro if cont");
            for (int i = 0; i < NUMBER_EVENT; i++)
            {
                //Serial.println("Chegou dentro for cont ");
                int index = (firstEventControllable + i) % NUMBER_EVENT;

                // Get one Controllable Event each time
                bool existEvent = getBit(eventEnabledControllable, index);

                if (existEvent)
                {
                    //Serial.println("Chegou dentro if exist event cont");
                    //Serial.println(index);
                    setBit(eventOccurred, index, true);
                    executeTransition(eventOccurred);
                    setBit(eventControllable, index, false);

                    zeroEvent(eventOccurred);
                    continue;
                }
            }

            zeroEvent(eventEnabledControllable);
            firstEventControllable = (firstEventControllable + 1) % NUMBER_EVENT;
        }

        zeroEvent(eventEnabled);
    }

    // Execute the Loop function for each automaton
    for (int i = 0; i < NUMBER_AUTOMATON; i++)
    {
        actualState = automata[i].getActualState();
        automata[i].Loop(actualState);
    }
}

void executeTransition(Event eventOccurred)
{
    // Execute the state transition for each supervisor
    for (int k = 0; k < NUMBER_SUPERVISOR; k++)
    {

        actualState = supervisor[k].getActualState();
        int nextState = supervisor[k].MakeTransition(actualState, eventOccurred);
        supervisor[k].setActualState(nextState);
    }

    // Execute the state transition for each automaton
    for (int j = 0; j < NUMBER_AUTOMATON; j++)
    {

        actualState = automata[j].getActualState();
        int nextState = automata[j].MakeTransition(actualState, eventOccurred);
        automata[j].setActualState(nextState);
    }
}
