//컴퓨터공학과 20184064 김정현
#define PORT_R 3 //R을 3번 포트로 사용
#define PORT_G 4 //G을 4번 포트로 사용
#define PORT_B 5 //B을 5번 포트로 사용
#define PORT_BUTTON 6 //버튼을 6번 포트로 사용
#define Buzzer 7 //작은 소리 buzzer를 7번 포트로 사용

int COLOR = 0b100; 
int sound = 523; //부져의 시작 소리를 523으로 설정
int beforeStatus = HIGH; 

void setup() {
  Serial.begin(9600);
  pinMode(PORT_R, OUTPUT); //3번 포트를 출력으로 설정
  pinMode(PORT_G, OUTPUT); //4번 포트를 출력으로 설정
  pinMode(PORT_B, OUTPUT); //5번 포트를 출력으로 설정
  pinMode(PORT_BUTTON, INPUT); //6번 포트를 입력으로 설정
  pinMode(Buzzer, OUTPUT); //7번 포트를 출력으로 설정
}

void loop() {
  int buttonStatus = digitalRead(PORT_BUTTON); //버튼 클릭 여부 값을 저장
  Serial.println("------------");
  Serial.println(String(buttonStatus==LOW));
  Serial.println(beforeStatus);
  Serial.println("------------");
  
  if( buttonStatus == LOW && beforeStatus == HIGH){ //만약 버튼이 눌리고 상태가 1이면
    beforeStatus = LOW; //상태를 0으로 설정
    
    if(COLOR == 0b000){ //만약 RGB값이 각각 0이면
      COLOR = 0b100; //COLOR 변수 값을 100(2)로 저장
    }
    else{
      int COLOR_R = (COLOR >> 2) & 1; //COLOR 값을 오른쪽으로 2만틈 쉬프트 연산 후 1과 &연산 한뒤 COLOR_R 변수에 값을 저장
      int COLOR_G = (COLOR >> 1) & 1; //COLOR 값을 오른쪽으로 1만틈 쉬프트 연산 후 1과 &연산 한뒤 COLOR_G 변수에 값을 저장
      int COLOR_B = (COLOR >> 0) & 1; //COLOR 값을 오른쪽으로 0만틈 쉬프트 연산 후 1과 &연산 한뒤 COLOR_B 변수에 값을 저장
      Serial.println("COLOR_R : " + String(COLOR_R)); //시리얼 모니터에 R의 값을 출력
      Serial.println("COLOR_G : " + String(COLOR_G)); //시리얼 모니터에 G의 값을 출력
      Serial.println("COLOR_B : " + String(COLOR_B)); //시리얼 모니터에 B의 값을 출력
      
      switch(COLOR){ //COLOR의 값에 따라 색상이 바뀌는 것이기 때문에 COLOR에 저장되는 값에 따라 맞는 색상이 출력되도록 함
        case 4: Serial.println("빨간색"); break;
        case 2: Serial.println("초록색"); break;
        case 1: Serial.println("파란색"); break;
        default: break;
      }  
 
      digitalWrite(PORT_R, COLOR_R); //3번 포트에 연결된 COLOR_R에 저장된 값을 출력
      digitalWrite(PORT_G, COLOR_G); //4번 포트에 연결된 COLOR_G에 저장된 값을 출력
      digitalWrite(PORT_B, COLOR_B); //5번 포트에 연결된 COLOR_B에 저장된 값을 출력
      COLOR = COLOR >> 1; //COLOR의 값을 오른쪽으로 1씩 쉬프트 연산을 하여 COLOR에 저장
      
      tone(Buzzer, sound); //색상이 바뀔때마다 설정한 피치의 소리가 나도록 한다.
      delay(500); //0.5초에 지연 시간을 준다.
      noTone(Buzzer); //소리를 내고 0.5초뒤에 멈추게한다.
      sound += 20; //버튼이 클릭 될때마다 소리의 피치가 20씩 증가하도록 한다.
    }
  }
  else{
    beforeStatus = HIGH; 
  }
}
