#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define SERVO_GPIO 22
#define PWM_FREQUENCY 50 // Frequência do PWM em Hz
#define CLOCK_DIVIDER 64 // Divisor de clock para gerar a frequência desejada

// Função para calcular o valor do ciclo ativo com base no tempo em microssegundos
uint16_t calcular_duty_cycle(uint16_t largura_pulso_us)
{
    uint32_t frequencia_clock = clock_get_hz(clk_sys) / CLOCK_DIVIDER; // Frequência do clock dividida
    uint32_t valor_maximo_contagem = frequencia_clock / PWM_FREQUENCY; // Valor de contagem máxima
    return (largura_pulso_us * valor_maximo_contagem) / 20000;         // Conversão para duty cycle
}

void definir_angulo_servo(uint16_t largura_pulso_us)
{
    pwm_set_gpio_level(SERVO_GPIO, calcular_duty_cycle(largura_pulso_us));
}

int main()
{
    stdio_init_all();

    // Configuração do pino GPIO como saída PWM
    gpio_set_function(SERVO_GPIO, GPIO_FUNC_PWM);
    uint slice_pwm = pwm_gpio_to_slice_num(SERVO_GPIO);

    // Configuração do PWM
    pwm_config configuracao_pwm = pwm_get_default_config();
    pwm_config_set_clkdiv(&configuracao_pwm, CLOCK_DIVIDER);
    pwm_config_set_wrap(&configuracao_pwm, clock_get_hz(clk_sys) / CLOCK_DIVIDER / PWM_FREQUENCY);
    pwm_init(slice_pwm, &configuracao_pwm, true);

    // Passo 1: Posição inicial de 180 graus (2400 µs)
    definir_angulo_servo(2400);
    sleep_ms(5000); // Aguarda 5 segundos na posição de 180 graus

    // Passo 2: Posição de 90 graus (1470 µs)
    definir_angulo_servo(1470);
    sleep_ms(5000); // Aguarda 5 segundos na posição de 90 graus

    // Passo 3: Posição de 0 graus (500 µs)
    definir_angulo_servo(500);
    sleep_ms(5000); // Aguarda 5 segundos na posição de 0 graus

    // Loop infinito para movimento suave entre 0 e 180 graus
    while (true)
    {
        // Movimento suave de 0° para 180°
        for (uint16_t pulso_atual = 500; pulso_atual <= 2400; pulso_atual += 5)
        {
            definir_angulo_servo(pulso_atual);
            sleep_ms(10); // Aguarda 10ms entre cada incremento
        }

        // Movimento suave de 180° para 0°
        for (uint16_t pulso_atual = 2400; pulso_atual >= 500; pulso_atual -= 5)
        {
            definir_angulo_servo(pulso_atual);
            sleep_ms(10); // Aguarda 10ms entre cada decremento
        }
    }
}
