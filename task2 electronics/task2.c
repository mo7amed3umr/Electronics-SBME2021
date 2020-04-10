 #include< reg51 .h>   

sbit UP_0 = p1^0;
sbit UP_1 = p1^1;
sbit UP_2 = p1^2;
sbit UP_3 = p1^3;
sbit DOWN_1 = p1^4;
sbit DOWN_2 = p1^5;
sbit DOWN_3 = p1^6;
sbit DOWN_4 = p1^7;
Up_direc_req = 0;
Down_direc_req = 0;
Up_direc_current = 1;
Down_direc_current= 0;
Floor0 = 0;
Floor1 = 0;
Floor2 = 0;
Floor3 = 0;
Floor4 = 0;
current_Position = 0;
request_Position = 0;

void req_direction(void){
    if (UP_0 || UP_1 || UP_2 || UP_3){
        Up_direc_req = 1;
    }
    else if (DOWN_1 || DOWN_2 || DOWN_3 || DOWN_4)
    {
        Down_direc_req = 1;
    }  
}

void req_position(void){
    if (Up_direc_req){
        if (UP_0 ){
            Floor0 = 1;
            request_Position = 0;
        }
        else if (UP_1 || DOWN_1){
            Floor1 = 1;
            request_Position = 1;
        }
        else if (UP_2 || DOWN_2 ){
            Floor2 = 1;
            request_Position = 2;
        }
        else if (UP_3 || DOWN_3 ){
            Floor3 = 1;
            request_Position = 3;
        }
        else if (DOWN_4 ){
            Floor4 = 1;
            request_Position = 4;
        }
    }
}

void elev_moving(void){
    if (Up_direc_req == Up_direc_current){
        if (current_Position > request_Position ){
            

        }
    }
}

void timer0_ISR (void) interrupt 1  //interrupt no. 1 for Timer0  
 {  
    TH0=0xFC;   // loading initial values to timer   
    TL0=0x66;  
}   
void main()   
{  
    P1 = 0xFF;      // Reading From Port 1
    TMOD=0x0l;      // mode 1 of Timer0  
    TH0 = 0xFC:    // initial value is loaded to timer  (252)
    TL0 = 0x66:           
    ET0 =1;         // enable timer 0 interrupt  
    TR0 = 1;        // start timer  
    while (1){
        req_direction();
        req_position();
    }        
 }  
