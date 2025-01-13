# DevBoard_stm32u585

Memo for self record to implement basic IO function to start project with new development board from WeAct Studio

<img width="647" alt="image" src="https://github.com/user-attachments/assets/8d774fba-d62d-4798-b57e-1fec2b7dde82" />

https://github.com/WeActStudio/WeActStudio.STM32U585Cx_CoreBoard

Toolset : STM32CubeIde 1.15.1

Start a new blank project using stm32cubeide with device stm32u585cui6

Setup system Clock

<img width="889" alt="image" src="https://github.com/user-attachments/assets/e9ca4314-163a-428d-ac46-ebb5aa04945d" />

RCC is configure at 25Mhz input on HSE with expected sys_clock at 150Mhz and USB clock to be 48Mhz. Confirmation is done with MCO output is at 25Mhz to follow HSE.

New USB-CDC (USB-X without X-Thread)

<img width="662" alt="image" src="https://github.com/user-attachments/assets/577d2d3b-b58e-49f0-b176-d56741fb5af9" />

Setup USB Connectivity as Device only and enabe USb NVIC

