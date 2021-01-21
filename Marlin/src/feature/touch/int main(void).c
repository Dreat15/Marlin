int main(void)
{
	SetupHardware();

	puts_P(PSTR(ESC_FG_CYAN "Android Accessory Host Demo running.\r\n" ESC_FG_WHITE));

	LEDs_SetAllLEDs(LEDMASK_USB_NOTREADY);
	GlobalInterruptEnable();

	for (;;)
	{
		AOAHost_Task();

		AOA_Host_USBTask(&AndroidDevice_AOA_Interface);
		USB_USBTask();
	}
}