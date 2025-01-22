#include "Automaton.h" 
#include <ArduinoQueue.h> // Biblioteca filas


// Filas de processos para cada tanque
ArduinoQueue<Processo> filaTanqueM(10);
ArduinoQueue<Processo> filaTanqueF(10);

// Função para inicializar as filas de processos
void inicializarFilas() {
    // Adicionar processos ao Tanque M
    filaTanqueM.enqueue({"Limpeza", executarLimpeza, &estadoLimpeza});
    filaTanqueM.enqueue({"Pasteurização", executarPasteurizacao, &estadoPasteurizacao});
    filaTanqueM.enqueue({"Moagem", executarMoagem, &estadoMoagem});
    filaTanqueM.enqueue({"Secagem", executarSecagem, &estadoSecagem});

    // Adicionar processos ao Tanque F
    filaTanqueF.enqueue({"Fermentação", executarFermentacao, &estadoFermentacao});
    filaTanqueF.enqueue({"Mistura", executarMistura, &estadoMistura});
    filaTanqueF.enqueue({"Cozimento", executarCozimento, &estadoCozimento});
}

// Função para gerenciar a execução de processos
void executarProcessos() {
    // Verificar fila do Tanque M
    if (!filaTanqueM.isEmpty()) {
        Processo processoAtual = filaTanqueM.getHead();
        if (*processoAtual.estado == -1) {
            // Processo concluído, remover da fila
            digitalWrite(PasM, true);
            filaTanqueM.dequeue();
            digitalWrite(PasM, false);
            Serial.println("Processo concluído no Tanque M: " + processoAtual.nome);
        } else if (*processoAtual.estado != -1) {
            // Executar processo
            Serial.println("Chamou a função de: " + processoAtual.nome);
            processoAtual.executar();
        }
    }

    // Verificar fila do Tanque F
    if (!filaTanqueF.isEmpty()) {
        Processo processoAtual = filaTanqueF.getHead();
        if (*processoAtual.estado == -1) {
            // Processo concluído, remover da fila
            digitalWrite(PasF, true);
            filaTanqueF.dequeue();
            digitalWrite(PasF, false);
            Serial.println("Processo concluído no Tanque F: " + processoAtual.nome);
        } else if (*processoAtual.estado != -1) {
            // Executar processo
            Serial.println("Chamou a função de: " + processoAtual.nome);
            processoAtual.executar();
        }
    }
}