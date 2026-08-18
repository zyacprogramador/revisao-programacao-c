#include "monitor.h"

#include <stdio.h>
#include <stdlib.h>

double celsius_para_fahrenheit(double temperatura) {
    return temperatura * 9.0 / 5.0 + 32.0;
}

bool leitura_valida(double valor) {
    return valor >= -40.0 && valor <= 125.0;
}

EstadoLeitura classificar_leitura(double valor) {
    if (!leitura_valida(valor)) {
        return LEITURA_INVALIDA;
    } else if (valor >= 80.0) {
        return LEITURA_ALERTA;
    } else {
        return LEITURA_NORMAL;
    }
}

const char *estado_como_texto(EstadoLeitura estado) {
    switch (estado) {
        case LEITURA_INVALIDA:
            return "INVALIDA";
        case LEITURA_NORMAL:
            return "NORMAL";
        case LEITURA_ALERTA:
            return "ALERTA";
    }

    return "DESCONHECIDA";
}

bool calcular_estatisticas(const Sensor *sensor, Estatisticas *resultado) {
    /* ETAPA 02: calcule mínima, máxima e média das leituras válidas. */
    (void)sensor;
    (void)resultado;
    return false;
}

bool sensor_adicionar_leitura(Sensor *sensor, double valor) {
    /* ETAPA 03: valide os ponteiros, a leitura e a capacidade do vetor. */
    (void)sensor;
    (void)valor;
    return false;
}

void exibir_relatorio(const Sensor *sensor) {
    /* ETAPA 03: substitua esta mensagem pelo relatório completo. */
    if (sensor != NULL) {
        printf("Sensor: %s\n", sensor->tag);
    }
}

bool lista_adicionar(NoLeitura **inicio, double valor) {
    /* ETAPA 03: aloque um nó e encadeie-o ao final da lista. */
    (void)inicio;
    (void)valor;
    return false;
}

size_t lista_quantidade(const NoLeitura *inicio) {
    /* ETAPA 03: percorra a lista com while. */
    (void)inicio;
    return 0;
}

double lista_media(const NoLeitura *inicio, bool *possui_dados) {
    /* ETAPA 03: calcule a média sem acessar um ponteiro nulo. */
    (void)inicio;
    if (possui_dados != NULL) {
        *possui_dados = false;
    }
    return 0.0;
}

void lista_liberar(NoLeitura **inicio) {
    /* ETAPA 03: libere todos os nós e deixe *inicio igual a NULL. */
    (void)inicio;
}

bool salvar_leituras(const char *caminho, const NoLeitura *inicio) {
    /* ETAPA 04: grave uma leitura por linha e feche o arquivo. */
    (void)caminho;
    (void)inicio;
    return false;
}

bool carregar_leituras(const char *caminho, NoLeitura **inicio) {
    /* ETAPA 04: leia as linhas, reconstrua a lista e feche o arquivo. */
    (void)caminho;
    (void)inicio;
    return false;
}
