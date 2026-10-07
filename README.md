# Embedded / AVR Practice

AVR 기반 보드에서 LED, 스위치, 각종 센서와 모터를 제어하며 임베디드 기초를 학습한 코드 모음입니다.

## 학습 내용

- Digital I/O와 LED 제어
- Pull-down / Internal Pull-up 스위치 입력
- Analog 센서 값 읽기
- PIR, CDS, Sound, Gas, Rain, Tilt 센서 활용
- HC-SR04 초음파 거리 측정
- SHT2x 온습도 센서와 I2C 통신
- DC Motor / FAN 제어
- 여러 센서를 결합한 자동 제어 프로젝트

## Repository Structure

```text
Embedded-AVR/
├─ 01_Basics/
│  └─ LED/
├─ 02_Switch/
│  ├─ Pull_Down/
│  └─ Pull_Up/
├─ 03_Sensors/
│  ├─ CDS/
│  ├─ PIR/
│  ├─ Sound/
│  ├─ Gas/
│  ├─ Rain/
│  ├─ Tilt/
│  ├─ Ultrasonic/
│  └─ Temperature_Humidity/
├─ 04_Actuators/
│  └─ DC_Motor/
├─ 05_Projects/
│  └─ Anti_Fog_System/
└─ 99_Archive/
   └─ Blank_Sketch/
```

## 주요 예제

| 구분 | 내용 |
|---|---|
| LED | 단일 LED 및 2개 LED 점멸 |
| Pull-down | 외부 Pull-down 스위치 입력으로 LED 제어 |
| Pull-up | 내부 Pull-up 입력과 LOW 활성 방식 확인 |
| CDS | 조도 값에 따라 LED 자동 제어 |
| PIR | 인체 감지 및 알람 ON/OFF |
| Sound | 소리 임계값을 이용한 LED 토글 |
| Gas | 가스 센서 임계값 기반 경고 |
| Rain | 물 감지 센서 값에 따른 FAN 제어 |
| Tilt | 기울기 스위치를 이용한 진동/충격 감지 연습 |
| Ultrasonic | HC-SR04 거리 측정 및 거리에 따른 LED 제어 |
| Temperature / Humidity | SHT2x 센서 값 측정 및 FAN 제어 |
| DC Motor | Serial 입력으로 모터 정방향 / 정지 / 역방향 제어 |
| Anti-Fog System | 온습도 + 물 감지 + LED + FAN을 결합한 결로 방지 시스템 |

## 대표 프로젝트: Anti-Fog System

SHT2x 온습도 센서와 물 감지 센서를 이용해 결로 가능성을 판단하고 FAN을 자동으로 동작시키는 실습입니다.

- 습도 60% 미만: LED OFF
- 습도 60~75%: LED 1개 ON
- 습도 75% 이상: LED 2개 ON
- 습도 75% 이상 또는 물 감지 값이 기준치를 넘으면 FAN ON

## 사용 환경

- AVR / Arduino compatible board
- Arduino IDE
- Serial Monitor: 115200 baud

## External Libraries

일부 예제는 아래 라이브러리가 필요합니다.

- SHT2x
- HCSR04

라이브러리 원본 소스는 학습 코드와 구분하기 위해 저장소에 중복 포함하지 않고, 사용하는 스케치만 정리했습니다.

## Note

이 저장소는 임베디드 기초 학습 과정을 정리한 저장소입니다. 각 코드는 센서 입력 확인 → 출력 제어 → 여러 장치 결합 순서로 확장하면서 작성했습니다.
