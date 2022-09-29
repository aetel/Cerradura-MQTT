
  #include "hardware.h"
  #include "gestionWifi.h"
  #include "cliente_mqtt.h"
//  #include <avr/wdt.h>
  
  void setup() {
    
    Serial.begin(115200); // Establecer la velocidad de consola serie
    Serial.println("");
    wdt_disable();//Deshabilitamos el WDT
    setup_wifi(); // Funcion que inicializa los parámetros para la conexion WIFI y se encarga de establecer la misma, 
                 //  el objetivo final es simplificar al maximo la conexion WIFI y que si se requieren cambios, estos se hagan de forma más sencilla, mas info en --> gestionWifi
    
    inicializarPines(); // Esta funcion es llamada para inicializar todos los pines de la placa que seran usados para realizar alguna tarea (sensor, interruptor, led, etc.), 
                       //  para mas info ver --> hardware

    arrancar_cliente_mqtt(); // Se encarga de inicializar y arrancar el cliente MQTT, tanto para hacer SUB como PUT al BROKER, ver --> cliente_mqtt
    wdt_enable(9);//corresponde con 8 segundos
  }
  
  void loop() {
    
    manejadorClienteMQTT(); // Se encarga de controlar que el cliente MQTT no se ha desconectado y en caso de estar desconectado, tomar medidas, mas info en --> cliente_mqtt
    
    estadoWifi(); // Funcion que se encarga de mantener la conexion WIFI establecida, toma medidas en caso de perderse la conexion
    wdt_reset();
  }
