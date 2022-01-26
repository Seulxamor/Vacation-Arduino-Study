//컴퓨터공학과 20184064 김정현
#define LED_R 3 //빨간색 LED (3번 port)
#define LED_G 4 //초록색 LED (4번 port)
int delaySec = 1000; //delay 시간을 증가시키기 위해 초기값 1000 저장
int statusNow = HIGH; //HIGH 상태를 갖고있는 변수 선언

void setup() {
  Serial.begin(9600); //아두이노가 시리얼 통신을 사용하도록 만드는 함수
  pinMode(LED_R, OUTPUT); //3번 port의 핀모드를 출력으로 설정
  pinMode(LED_G, OUTPUT); //4번 port의 핀모드를 출력으로 설정
}

void loop() {
  digitalWrite(LED_R, statusNow); //3번 port에 연결된 빨간 LED를 켜기
  digitalWrite(LED_G, !statusNow); //4번 port에 연결된 녹색 LED를 켜기
  delay(delaySec); //1초 대기
  Serial.println("Time : " + String(delaySec)); //시리얼 모니터에 현재 지연 시간 출력
  Serial.println("Red : " + String(statusNow)); //시리얼 모니터에 빨간 LED 상태 출력
  Serial.println("Green : " + String(!statusNow)); //시리얼 모니터에 녹색 LED 상태 출력
  statusNow = !statusNow; //빨간색과 녹색을 번갈아가며 켜지게 하기 위해 loop문이 끝나기 전에 상태 반전
  delaySec += 500; //1초 대기 후 지연 시간을 0.5초씩 늘린다.
}
