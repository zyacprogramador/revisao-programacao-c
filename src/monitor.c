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
    if (sensor == NULL || resultado == NULL ||
        sensor->quantidade > MAX_LEITURAS) {
        return false;
    }

    size_t validas = 0;
    double soma = 0.0;

    for (size_t i = 0; i < sensor->quantidade; i++) {
        double valor = sensor->leituras[i];

        if (!leitura_valida(valor)) {
            continue;
        }

        if (validas == 0 || valor < resultado->minima) {
            resultado->minima = valor;
        }

        if (validas == 0 || valor > resultado->maxima) {
            resultado->maxima = valor;
        }

        soma += valor;
        validas++;
    }

    if (validas == 0) {
        return false;
    }

    resultado->media = soma / validas;
    return true;
}

bool sensor_adicionar_leitura(Sensor *sensor, double valor) {
    if (sensor == NULL || !leitura_valida(valor) ||
        sensor->quantidade >= MAX_LEITURAS) {
        return false;
    }

    sensor->leituras[sensor->quantidade] = valor;
    sensor->quantidade++;
    return true;
}

void exibir_relatorio(const Sensor *sensor) {
    if (sensor == NULL) {
        return;
    }

    Estatisticas resultado;
    if (!calcular_estatisticas(sensor, &resultado)) {
        printf("Sensor %s sem leituras validas\n", sensor->tag);
        return;
    }

    size_t validas = 0;
    for (size_t i = 0; i < sensor->quantidade; i++) {
        if (leitura_valida(sensor->leituras[i])) {
            validas++;
        }
    }

    printf("Sensor: %s\n", sensor->tag);
    printf("Leituras aceitas: %zu\n", validas);
    printf("Minima: %.1f C\n", resultado.minima);
    printf("Maxima: %.1f C\n", resultado.maxima);
    printf("Media: %.1f C\n", resultado.media);
    printf("Estado: %s\n",
           estado_como_texto(classificar_leitura(resultado.media)));
}

bool lista_adicionar(NoLeitura **inicio, double valor) {
    if (inicio == NULL || !leitura_valida(valor)) {
        return false;
    }

    NoLeitura *novo = malloc(sizeof(*novo));
    if (novo == NULL) {
        return false;
    }

    novo->valor = valor;
    novo->proximo = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
        return true;
    }

    NoLeitura *atual = *inicio;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novo;
    return true;
}

size_t lista_quantidade(const NoLeitura *inicio) {
    size_t quantidade = 0;
    const NoLeitura *atual = inicio;

    while (atual != NULL) {
        quantidade++;
        atual = atual->proximo;
    }

    return quantidade;
}

double lista_media(const NoLeitura *inicio, bool *possui_dados) {
    if (possui_dados == NULL) {
        return 0.0;
    }

    double soma = 0.0;
    size_t quantidade = 0;
    const NoLeitura *atual = inicio;

    while (atual != NULL) {
        soma += atual->valor;
        quantidade++;
        atual = atual->proximo;
    }

    *possui_dados = quantidade > 0;
    return quantidade > 0 ? soma / quantidade : 0.0;
}

void lista_liberar(NoLeitura **inicio) {
    if (inicio == NULL) {
        return;
    }

    while (*inicio != NULL) {
        NoLeitura *proximo = (*inicio)->proximo;
        free(*inicio);
        *inicio = proximo;
    }
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
