# DevBoard_stm32h503cbt6

Memo for self record to implement basic IO function in preparation for new development with this micro controller. To Build the code, clone the repo, import using ST32CubeIDE and remember to generate start device configuration tool code generation before building and download the code.  

<img width="671" alt="image" src="https://github.com/user-attachments/assets/b9ec99e0-77ba-4d7c-83f1-bad48d1716f0" />

System Clock Setup

<img width="879" alt="image" src="https://github.com/user-attachments/assets/4c3006f4-1754-419e-9d8e-6cb7aeadee0e" />

USB Connectivity Setup.

<img width="541" alt="image" src="https://github.com/user-attachments/assets/83e58bc6-dcb5-4c68-a56b-2e559053d7b8" />

DEfault Parameters is sufficient.

<img width="398" alt="image" src="https://github.com/user-attachments/assets/4d1cd34a-2e1f-451c-8300-7cb5fcba87a6" />

Enable NVIC

USB-X Middleware

<img width="395" alt="image" src="https://github.com/user-attachments/assets/0c0d0afa-9f5f-4fb0-8b6a-87436e226e3c" />

Enable Core, Controller and CDC-ACM

<img width="494" alt="image" src="https://github.com/user-attachments/assets/7d3690ba-daee-4c7a-a8bc-2c538b18e4b5" />

Change default stack size and set ACM_TRANSMISSION_DISABLE to disable for non blocking transfer

Modify main.c as follows:-

<img width="461" alt="image" src="https://github.com/user-attachments/assets/0085be51-d085-4f64-8993-255264f1541a" />

Modify ux_device_cdc_acm.c as follows:-

Part 1

<img width="835" alt="image" src="https://github.com/user-attachments/assets/0b4932a9-8d64-4b08-8b90-36a69ef678db" />

Part 2

<img width="815" alt="image" src="https://github.com/user-attachments/assets/2d7fc981-914d-44fa-9629-0aec2651edde" />

Part 3

<img width="743" alt="image" src="https://github.com/user-attachments/assets/36912768-db73-4814-9f3d-4e2ea6212593" />

USB-X Status 

1. USB enumeration is Working and USB serial is detected on PC side.
2. Loopback of keyboard entry key stroke is able to echo back on the terminal display. Receiving and Sending of CDC packet is working.

#

# DevBoard_stm32u585

Memo for self record to implement basic IO function to start project with new development board from WeAct Studio. To Build the code, clone the repo, import using ST32CubeIDE and remember to generate start device configuration tool code generation before building and download the code.  

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

<img width="715" alt="image" src="https://github.com/user-attachments/assets/097ea1b7-5d57-406a-a95c-851bc0986505" />

Add code into "app_usbx_device.c", line of code to be added in Line  204

<img width="1098" alt="image" src="https://github.com/user-attachments/assets/5758849a-fea9-498b-a966-44a7eb569253" />

USB should be detected and pass USB enumeration and a Serial Communication device will appear under "USB\VID_0483&PID_5710"  

USB-X Status 

1. USB enumeration is Working and USB serial is detected on PC side.
2. Still not working, Same code from the h503 is not working for the u585. Receive callback happen when a key is input from the terminal but the issue is usb task is locked up after trying to send a non block USB write request with no callback from the write run..... Strange!
