Версия 3.0

BOM:
Name	Value	Layer	Comment
1. D1-D32	LED	Top	5mm
2. R1-R8	82R*	Bottom	0805

Name	Value	Layer	Comment
1. B1-B5	Button	Top	
2. C1,C2	22p	Bottom	0805
3. C3	0.33u	Bottom	0805
4. C4-C7	0.1u	Bottom	
5. Q1	16Mhz	Bottom	
6. Q2	IRF530NPBF	Top	TO-220AB
7. R1	100R	Bottom	0805
8. R2	22k	Bottom	0805
9. R3	10k	Top	3362H
10. R4-R11	10k	Bottom	0805
11. S1	DS-261B	Top	
12. S2	301-021-12	Top	
13. S3	Encoder	Top	
14. SCREEN	1602	Top	
15. U1	Atmega328	Bottom	
16. U2	L7805	Top	TO-220AB

Как прошить:
1. Любым программатором загружается bootloader (HEX файл и фьюзы прилагаются). Самой простой вариант прошить через USB Arduino NANO и "сдуть" с нее чип.
2. Впаивается чип на плату.
3. Заливается INO файл из Arduino IDE (как Arduino NANO) с помощью USB-UART преобразователя (FTDI).
