//컴퓨터공학과 20184064 김정현
//RGB LED 센서 사용
#define PORT_R 3 //R을 3번 port로 사용
#define PORT_G 4 //G을 4번 port로 사용
#define PORT_B 5 //B을 5번 port로 사용

void setup() {
  Serial.begin(9600);
  pinMode(PORT_R, OUTPUT); //3번 port를 출력으로 설정
  pinMode(PORT_G, OUTPUT); //4번 port를 출력으로 설정
  pinMode(PORT_B, OUTPUT); //5번 port를 출력으로 설정
}

void loop() {
  int COLOR = 0b100; //색상을 정해줄 COLOR 변수에 4의 이진수 값을 저장
  //1초가 지날때마다 빨→초→파로 바꾸기 위해 for문과 쉬프트 연산을 이용
  //100(2)면 빨간색, 010(2)면 초록색, 001(2)면 파란색이 나오도록 함
  
  for(int i = 0; i < 3; i++){
    int COLOR_R = (COLOR >> 2) & 1; //COLOR 값을 오른쪽으로 2만틈 쉬프트 연산 후 1과 &연산 한뒤 COLOR_R 변수에 값을 저장
    int COLOR_G = (COLOR >> 1) & 1; //COLOR 값을 오른쪽으로 1만틈 쉬프트 연산 후 1과 &연산 한뒤 COLOR_G 변수에 값을 저장
    int COLOR_B = (COLOR >> 0) & 1; //COLOR 값을 오른쪽으로 0만틈 쉬프트 연산 후 1과 &연산 한뒤 COLOR_B 변수에 값을 저장
    
    Serial.println("COLOR_R : " + String(COLOR_R)); //시리얼 모니터에 R의 값을 출력
    Serial.println("COLOR_G : " + String(COLOR_G)); //시리얼 모니터에 G의 값을 출력
    Serial.println("COLOR_B : " + String(COLOR_B)); //시리얼 모니터에 B의 값을 출력
    Serial.println("----------------------------");
    
    digitalWrite(PORT_R, COLOR_R); //3번 포트에 연결된 COLOR_R에 저장된 값을 출력
    digitalWrite(PORT_G, COLOR_G); //3번 포트에 연결된 COLOR_G에 저장된 값을 출력
    digitalWrite(PORT_B, COLOR_B); //3번 포트에 연결된 COLOR_B에 저장된 값을 출력
    delay(1000); //1초에 지연 시간을 준다.
    COLOR = COLOR >> 1; //for문이 끝나기전에 COLOR의 값을 오른쪽으로 1씩 쉬프트 연산을 하여 COLOR에 저장
  }
  
}
