# Cerradura-MQTT
Este proyecto engloba el programa de control de la cerradura electronica del local principal.

El esquema de funcionamiento del sistema de cerradura electrónica es el siguiente:
- Módulo wifi con ESP8266: Se trata de un clon de la Wemos D1 mini.
- Regulador de voltage DC-DC: para adaptar el voltage entrante al módulo wifi.
- Moduló con relé: Es el actuador que se encarga de controlar la apertura o cierre de la puerta
- Llave de contacto: Contamos con una llave que la debe poseer el presidente de la asociación y que si se gira se corta la alimentación de todo el circuito. Una vez devuelta a su posición original se vuelve a suministrar la alimentación y se produce el reseteo de todo el sistema. SI EL SISTEMA NO FUNCIONA COMO DEBERÍA PROBAD LO ANTERIOR.
- Módulo RFID RC522: Es un lector de NFC y está en fase de implementación.

![PuertaAETEL](https://github.com/aetel/Cerradura-MQTT/assets/87149204/e32018f0-66b5-4baa-bf61-d0bd0d30349a)

La apertura de la puerta se puede hacer de la siguiente manera:
1. Entrar al grupo de telegram de AETEL y escribir el siguiente mensaje: /abrir
2. (BETA) Entrar con tu etiqueta NFC o con tu móvil descargando la aplicación [NFC Tools ](https://play.google.com/store/apps/details?id=com.wakdev.wdnfc&pcampaignid=web_share) y configurando la etiqueta NFC correspondiente. (La app incorpora control de accesos)
