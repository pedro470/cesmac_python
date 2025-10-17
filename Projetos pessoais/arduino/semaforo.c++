struct Semaforo {
    int vermelho;
    int amarelo;
    int verde;
    unsigned long tempoVerde;
    unsigned long tempoAmarelo;
    unsigned long tempoVermelho;
    unsigned long tempoDecorrido;
    unsigned long tempoEstadoAtual;
};

Semaforo semaforo1;
Semaforo semaforo2;
Semaforo semaforoPedestre;

void acendeVermelho(Semaforo *semaforo);
void acendeAmarelo(Semaforo *semaforo);
void acendeVerde(Semaforo *semaforo);
void pedestreAcionado(Semaforo *semaforoPedestre, Semaforo *semaforoRua1, Semaforo *semaforoRua2);

int botao = 5;
bool pedestre = false;
bool sinal_amarelo = false;
bool pedestre_amarelo = false;
bool pedestre_aceso_sinal_1 = false;
bool pedestre_aceso_sinal_2 = false;

void acendeVermelho(Semaforo *semaforo) {
    digitalWrite(semaforo->vermelho, HIGH);
    digitalWrite(semaforo->amarelo, LOW);
    digitalWrite(semaforo->verde, LOW);
}

void acendeAmarelo(Semaforo *semaforo) {
    digitalWrite(semaforo->vermelho, LOW);
    digitalWrite(semaforo->amarelo, HIGH);
    digitalWrite(semaforo->verde, LOW);
}

void acendeVerde(Semaforo *semaforo) {
    digitalWrite(semaforo->vermelho, LOW);
    digitalWrite(semaforo->amarelo, LOW);
    digitalWrite(semaforo->verde, HIGH);
}

void pedestreAcionado(Semaforo *semaforoPedestre, Semaforo *semaforoRua1, Semaforo *semaforoRua2) {
    semaforoPedestre->tempoEstadoAtual = millis() - semaforoPedestre->tempoDecorrido;
    if (semaforoPedestre->tempoEstadoAtual >= semaforoPedestre->tempoVerde) {
        pedestre_aceso_sinal_1 = false;
        pedestre_aceso_sinal_2 = false;
        pedestre = false;
        acendeVermelho(semaforoPedestre);
        acendeVerde(semaforoRua1);
        semaforoRua1->tempoDecorrido = millis();
        semaforoRua2->tempoDecorrido = millis();
    }
}

void setup() {
    semaforo1.vermelho = 9;
    semaforo1.amarelo = 10;
    semaforo1.verde = 11;
    semaforo1.tempoVerde = 11000;
    semaforo1.tempoAmarelo = 2000;
    semaforo1.tempoVermelho = 7000;
    semaforo1.tempoDecorrido = 0;

    semaforo2.vermelho = 2;
    semaforo2.amarelo = 3;
    semaforo2.verde = 4;
    semaforo2.tempoVerde = 5000;
    semaforo2.tempoAmarelo = 2000;
    semaforo2.tempoVermelho = 13000;
    semaforo2.tempoDecorrido = 0;

    semaforoPedestre.vermelho = 12;
    semaforoPedestre.verde = 13;
    semaforoPedestre.tempoVerde = 5000;
    semaforoPedestre.tempoDecorrido = 0;

    pinMode(semaforo1.vermelho, OUTPUT);
    pinMode(semaforo1.amarelo, OUTPUT);
    pinMode(semaforo1.verde, OUTPUT);
    
    pinMode(semaforo2.vermelho, OUTPUT);
    pinMode(semaforo2.amarelo, OUTPUT);
    pinMode(semaforo2.verde, OUTPUT);
    
    pinMode(semaforoPedestre.vermelho, OUTPUT);
    pinMode(semaforoPedestre.verde, OUTPUT);
    
    pinMode(botao, INPUT);
    acendeVerde(&semaforo1);
    acendeVermelho(&semaforo2);
    digitalWrite(semaforoPedestre.vermelho, HIGH);
    digitalWrite(semaforoPedestre.verde, LOW);
}

void loop() {
    sinal_amarelo = digitalRead(semaforo1.amarelo) || digitalRead(semaforo2.amarelo);
    if ((sinal_amarelo == true) && (digitalRead(botao) == HIGH) && (pedestre == false) && (pedestre_amarelo == false)){
        pedestre_amarelo = true;
    }
    else if ((digitalRead(botao) == HIGH) && (pedestre_amarelo == false) && (pedestre == false)){
        pedestre = true;
    }
    else if (pedestre_aceso_sinal_1 == true) {
        pedestreAcionado(&semaforoPedestre, &semaforo1, &semaforo2);
    }
    else if (pedestre_aceso_sinal_2 == true) {
        pedestreAcionado(&semaforoPedestre, &semaforo2, &semaforo1);
    }
    else {
        if (digitalRead(semaforo1.vermelho) == HIGH) {
            semaforo1.tempoEstadoAtual = millis() - semaforo1.tempoDecorrido;
            if (semaforo1.tempoEstadoAtual >= semaforo1.tempoVermelho) {
                if (pedestre == true){
                    pedestre_aceso_sinal_1 = true;
                    acendeVerde(&semaforoPedestre);
                    semaforoPedestre.tempoDecorrido = millis();
                }
                else {
                    if (pedestre_amarelo == true){
                        pedestre_amarelo = false;
                        pedestre = true;
                        acendeVerde(&semaforo1);
                        semaforo1.tempoDecorrido = millis();
                    }
                }
            }
        }   
        else if (digitalRead(semaforo1.amarelo) == HIGH) {
            semaforo1.tempoEstadoAtual = millis() - semaforo1.tempoDecorrido;
            if (semaforo1.tempoEstadoAtual >= semaforo1.tempoAmarelo) {
                acendeVermelho(&semaforo1);
                semaforo1.tempoDecorrido = millis();
            }
        }
        else if (digitalRead(semaforo1.verde) == HIGH) {
            semaforo1.tempoEstadoAtual = millis() - semaforo1.tempoDecorrido;
            if (semaforo1.tempoEstadoAtual >= semaforo1.tempoVerde) {
                acendeAmarelo(&semaforo1);
                semaforo1.tempoDecorrido = millis();
            }
        }
        if (digitalRead(semaforo2.vermelho) == HIGH) {
            semaforo2.tempoEstadoAtual = millis() - semaforo2.tempoDecorrido;
            if (semaforo2.tempoEstadoAtual >= semaforo2.tempoVermelho) {
                
                if (pedestre == true){
                    pedestre_aceso_sinal_2 = true;
                    acendeVerde(&semaforoPedestre);
                    semaforoPedestre.tempoDecorrido = millis();
                }
                else {
                    if (pedestre_amarelo == true){
                        pedestre_amarelo = false;
                        pedestre = true;
                    }
                    acendeVerde(&semaforo2);
                    semaforo2.tempoDecorrido = millis();
                }
            }
        }
        else if (digitalRead(semaforo2.amarelo) == HIGH) {
            semaforo2.tempoEstadoAtual = millis() - semaforo2.tempoDecorrido;
            if (semaforo2.tempoEstadoAtual >= semaforo2.tempoAmarelo) {
                acendeVermelho(&semaforo2);
                semaforo2.tempoDecorrido = millis();
            }
        }
        else if (digitalRead(semaforo2.verde) == HIGH) {
            semaforo2.tempoEstadoAtual = millis() - semaforo2.tempoDecorrido;
            if (semaforo2.tempoEstadoAtual >= semaforo2.tempoVerde) {
                acendeAmarelo(&semaforo2);
                semaforo2.tempoDecorrido = millis();
            }
        }
    }
}