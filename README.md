# Smart_Home
        ระบบบ้านอัจฉริยะที่ใช้สำหรับการควบคุมการทำงานของอุปกรณ์ในบ้านโดยใช้เทคโนโลยี IoT และ ระบบควบคุมอัจฉริยะโดยเก็บรวบรวม
    ข้อมูลจากเซนเซอร์ต่างๆ ที่ติดตั้งในบ้าน แล้วนำข้อมูลที่ได้มาวิเคราะห์และควบคุมการทำงานของอุปกรณ์ต่างๆ ในบ้านโดยอัตโนมัติ ซึ่งจะช่วย
    ให้ผู้ใช้งานสามารถควบคุมการทำงานของอุปกรณ์ต่างๆ ในบ้านได้อย่างง่ายดาย และสามารถประหยัดพลังงานได้
![Smart_Home](https://raw.githubusercontent.com/nueapop/Smart_Home/main/web/assets/image/banner.png)

## Features
- สามารถควบคุมการทำงานของอุปกรณ์ต่างๆ ในบ้านได้ผ่าน Web Application
- สามารถตรวจจับการเปลี่ยนแปลงของสภาพแวดล้อมได้
- สามารถประหยัดพลังงานได้
- สามารถตรวจจับการเกิดออัคคีภัยได้

![Smart_Home](https://raw.githubusercontent.com/nueapop/Smart_Home/main/web/assets/image/room.jpg)

## Architecture
<p align="center">
  <img src="https://raw.githubusercontent.com/nueapop/Smart_Home/main/web/assets/image/architecture.jpg" alt="Smart_Home"/>
</p>

## Embedded Component
- NodeMCU ESP32 ( 1 Pc. )
    <> ใช้ในการรับส่งข้อมูลจากเซนเซอร์ต่างๆ และควบคุมการทำงานของอุปกรณ์ต่างๆภายในบ้าน
- Breadboard ( 1 Pc. )
    <> ใช้ในการเชื่อมต่อ NodeMCU ESP32 กับเซนเซอร์ต่างๆ และอุปกรณ์ต่างๆภายในบ้าน
- DHT11 ( 1 Pc. )
    <> ใช้ในการตรวจจับความชื้นและอุณหภูมิภายในบ้าน
- MQ-2 ( 1 Pc. )
    <> ใช้ในการตรวจจับค่าความเป็นมลพิษของควันภายในบ้าน
- Led ( 11 Pc. )
    <> ใช้แทนหลอดไฟภายในบ้าน
- Resistor ( 11 Pc. )
    <> ใช้ในการป้องกันการเกิดการกระแสไฟฟ้าที่มากเกินไป

## Embedded Library
- DHT11.h <> ใช้ในการตรวจจับความชื้นและอุณหภูมิภายในบ้าน
- WiFi.h <> ใช้ในการเชื่อมต่อ NodeMCU ESP32 กับ WiFi เพื่อให้กลายเป็นอุปกรณ์ IoT
- ThingSpeak.h <> ใช้ในการส่งข้อมูลจาก NodeMCU ESP32 ไปยัง ThingSpeak

![Smart_Home](https://raw.githubusercontent.com/nueapop/Smart_Home/main/web/assets/image/embedded.png)

## Wire Circuit
![Smart_Home](https://raw.githubusercontent.com/nueapop/Smart_Home/main/web/assets/image/wire.png)

## Web Application Function
- Line OA <> Official Account สำหรับการแจ้งเตือน และ ใช้งาน Feature Line LIFF
- Line LIFF <> ใช้ในการเชื่อมต่อกับ Web Application และ Integrate กับ Line Login API
- ThingSpeak <> ใช้ในการรับข้อมูลจาก NodeMCU ESP32 และส่งข้อมูลไปแสดงผลบน Web Application
- Dashboard <> ใช้ในการแสดงผลข้อมูลจาก NodeMCU ESP32 และสามารถควบคุมการทำงานของอุปกรณ์ต่างๆภายในบ้าน

![Smart_Home](https://raw.githubusercontent.com/nueapop/Smart_Home/main/web/assets/image/webOnload.png)
![Smart_Home](https://raw.githubusercontent.com/nueapop/Smart_Home/main/web/assets/image/webLogin.png)
![Smart_Home](https://raw.githubusercontent.com/nueapop/Smart_Home/main/web/assets/image/webDashboard1.png)
![Smart_Home](https://raw.githubusercontent.com/nueapop/Smart_Home/main/web/assets/image/webDashboard2.png)

## Video Presentation
[![Video Presentation](https://raw.githubusercontent.com/nueapop/Smart_Home/main/web/assets/image/youtube.png)](https://www.youtube.com/watch?v=0JP2ZqZhrDc)

<p align="center"><br>63111934 นายเหนือภพ<br>63104079 นายธนบดี<br>63104509 นายธันยบูรณ์<br>63104020  นายธนโชติ<br><br>Information Technology and Digital Innovation<br>Walailak University</p>

## License

[GNU](https://github.com/nueapop/Smart_Home/blob/main/LICENSE)
