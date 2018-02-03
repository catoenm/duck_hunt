#ifndef __functions_h
#define __functions_h

#include "functions.h"

#endif
#include <stdio.h>
#include "LPC17xx.H"                         /* LPC17xx definitions           */
#include "GLCD.h"
#include "Serial.h"
#include "LED.h"
#include "ADC.h"


void changeDisplay(int score, int bullets) {
	char text [20];
	
	GLCD_SetBackColor(Green);
	GLCD_ClearLn(9,__FI);
	GLCD_SetTextColor(Black);											

	
	sprintf(text, "Score:%04u         ", score);       /* format text for print out     */
	GLCD_DisplayString(9, 0, 1, (unsigned char *)text);
	
	sprintf(text, "B:%01u  ", bullets);       /* format text for print out     */
	GLCD_DisplayString(9, 16, 1, (unsigned char *)text);
	
}

void ScreenMaintain(int round) {
	char text [20];
	
	GLCD_SetBackColor(Blue);
	GLCD_SetTextColor(White);											

	sprintf(text, "Round:%01u  ", (unsigned char *)round);       /* format text for print out     */
	GLCD_DisplayString(1, 1, 1, text);
	
	GLCD_SetBackColor(Green);
	GLCD_ClearLn(8,__FI);
}

void Init_Joy() {
	LPC_SC->PCONP |= 1 << 15;
	LPC_PINCON->PINSEL3 &= ~((3<< 8)|(3<<14)|(3<<16)|(3<<18)|(3<<20)); 
	LPC_GPIO1->FIODIR &= ~((1<<20)|(1<<23)|(1<<24)|(1<<25)|(1<<26));
}

void ShowGameOverScreen(int score){
	char text [20];
	
	GLCD_Clear(Blue);

	GLCD_SetTextColor(White);	
	GLCD_SetBackColor(Blue);
	GLCD_DisplayString(4, 5, 1, "Game Over");
	sprintf(text, "Score:%04u         ", score);       /* format text for print out     */
	GLCD_DisplayString(5, 5, 1, (unsigned char *)text);
	GLCD_SetBackColor(Green);
	GLCD_ClearLn(8,__FI);
	GLCD_ClearLn(9,__FI);
}

