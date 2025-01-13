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

<img width="689" alt="image" src="https://github.com/user-attachments/assets/e5c6714e-1ba4-4133-beb7-e3f4f8802ebd" />

Setup USB-X middleware (Not using ThreadX but a standalone solution in this use case). Select the Core system, Device core stack and controller stack and finally the Device class CDC-ACM


<img width="454" alt="image" src="https://github.com/user-attachments/assets/11aa4d41-1f6f-46e4-bad1-8584d21030f3" />

Get rid of the warning in the platform tag.

<img width="662" alt="image" src="https://github.com/user-attachments/assets/b71ff30a-d5f5-4d26-b9fa-51e051a3e5fa" />

Set the both "UXDevice memory pool size" & "USBX Device System Stack Size" to 10k


<img width="863" alt="image" src="https://github.com/user-attachments/assets/9307d776-82e8-4b3b-b7fc-5442a721f5a5" />

Add code into main.c, line of code to be added is Line 99, 102 & 109

<img width="908" alt="image" src="https://github.com/user-attachments/assets/a9367d03-3111-4657-a2ee-951f764dae59" />

Untick do not generate function call for "MX_USB_OTG_FS_PCD_Init" to add the function call "MX_USB_OTG_FS_PCD_Init();" into main function.
