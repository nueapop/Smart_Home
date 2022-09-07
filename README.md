# Smart_Home
        ระบบบ้านอัจฉริยะที่ใช้สำหรับการควบคุมการทำงานของอุปกรณ์ในบ้านโดยใช้เทคโนโลยี IoT และ ระบบควบคุมอัจฉริยะโดยเก็บรวบรวม
    ข้อมูลจากเซนเซอร์ต่างๆ ที่ติดตั้งในบ้าน แล้วนำข้อมูลที่ได้มาวิเคราะห์และควบคุมการทำงานของอุปกรณ์ต่างๆ ในบ้านโดยอัตโนมัติ ซึ่งจะช่วย
    ให้ผู้ใช้งานสามารถควบคุมการทำงานของอุปกรณ์ต่างๆ ในบ้านได้อย่างง่ายดาย และสามารถประหยัดพลังงานได้

## Model of Smart Home
![Smart_Home](https://raw.githubusercontent.com/nueapop/Smart_Home/main/web/assets/image/room.jpg)

## Features
- สามารถควบคุมการทำงานของอุปกรณ์ต่างๆ ในบ้านได้ผ่าน Web Application
- สามารถตรวจจับการเปลี่ยนแปลงของสภาพแวดล้อมได้
- สามารถประหยัดพลังงานได้
- สามารถตรวจจับการเกิดออัคคีภัยได้

## Embedded Component
- NodeMCU ESP32 ( 1 Pc. )
    - ใช้ในการรับส่งข้อมูลจากเซนเซอร์ต่างๆ และควบคุมการทำงานของอุปกรณ์ต่างๆภายในบ้าน

- Breadboard ( 1 Pc. )
    - ใช้ในการเชื่อมต่อ NodeMCU ESP32 กับเซนเซอร์ต่างๆ และอุปกรณ์ต่างๆภายในบ้าน

- DHT11 ( 1 Pc. )
    - ใช้ในการตรวจจับความชื้นและอุณหภูมิภายในบ้าน

- MQ-2 ( 1 Pc. )
    - ใช้ในการตรวจจับค่าความเป็นมลพิษของควันภายในบ้าน

- Led ( 11 Pc. )
    - ใช้แทนหลอดไฟภายในบ้าน

- Resistor ( 11 Pc. )
    - ใช้ในการป้องกันการเกิดการกระแสไฟฟ้าที่มากเกินไป
    
## License

[GNU](https://github.com/nueapop/Smart_Home/blob/main/LICENSE)
