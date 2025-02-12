# **Controle de Servomotor por PWM - TAREFA INDIVIDUAL**

## **Descrição do Projeto**

Este projeto implementa o controle de um servomotor utilizando o módulo PWM (Pulse Width Modulation) do microcontrolador Raspberry Pi Pico W. O objetivo é simular o ajuste do ângulo do servomotor em diferentes posições (0°, 90° e 180°) e realizar uma movimentação suave entre esses ângulos.

O código foi desenvolvido utilizando o **Pico SDK** e testado no simulador online **Wokwi**.

---

## **Requisitos do Sistema**

Para executar este projeto, você precisará dos seguintes componentes e ferramentas:

### **Hardware (Simulado)**

- Microcontrolador: **Raspberry Pi Pico W**
- Servomotor: **Motor Micro Servo Padrão** (simulado no Wokwi)

### **Software**

- **VS Code**: Ambiente de desenvolvimento integrado.
- **Pico SDK**: Kit de desenvolvimento de software para Raspberry Pi Pico.
- **Wokwi Simulator**: Simulador online integrado ao VS Code.
- **Git**: Para versionamento e submissão do código no GitHub.

---

## **Instruções de Uso**

### **1. Configuração do Ambiente**

1. Instale o **VS Code** em seu computador.
2. Configure o **Pico SDK** seguindo as instruções oficiais disponíveis [aqui](https://github.com/raspberrypi/pico-sdk).
3. Integre o simulador **Wokwi** ao VS Code seguindo as instruções disponíveis [aqui](https://wokwi.com/vscode).

### **2. Clonagem do Repositório**

Clone este repositório em sua máquina local usando o comando:

```bash
git clone https://github.com/davi-aguiar/ATV_embarcatech4
```

### **3. Compilação e Upload do Código**

1. Abra o projeto no VS Code.
2. Compile o código usando a extensão.

### **4. Execução no Wokwi**

1. Após entrar no `diagram.json`, o simulador Wokwi iniciará automaticamente.
2. Observe o comportamento do servomotor:
   - Ele começará na posição de **180°** (2400 µs) e permanecerá por 5 segundos.
   - Em seguida, moverá para **90°** (1470 µs) e permanecerá por 5 segundos.
   - Depois, moverá para **0°** (500 µs) e permanecerá por 5 segundos.
   - Finalmente, entrará em um loop infinito realizando uma movimentação suave entre **0° e 180°**.

---

## **Resultados Esperados**

- O servomotor deve seguir os ângulos especificados (0°, 90° e 180°) nos tempos definidos.
- A movimentação suave entre 0° e 180° deve ocorrer de forma contínua, com incrementos de **±5 µs** e atraso de **10 ms**.

---

## **Vídeo Demonstrativo**

Um vídeo demonstrando o funcionamento do programa pode ser acessado no link abaixo:
[Link para o Vídeo](https://youtu.be/bxK6pQrRWms)
