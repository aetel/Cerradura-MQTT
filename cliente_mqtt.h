 
  #ifndef CLIENTE_MQTT_H
  #define CLIENTE_MQTT_H

    #include <PubSubClient.h>
    #include "hardware.h"

    
    /* IP del BROKER MQTT (Raspberry en nuestro caso) */
    
    const char* mqtt_server = "";
    const char* mqtt_server_user = "";
    const char* mqtt_server_password = "";

    
    /* Cliente ESP8266 (MQTT) */
    
    WiFiClient espClient;
    PubSubClient client(mqtt_server,1883,espClient); // 1883 es el puerto listener para el Broker
    //const char* clientID = "ESP8266_1";
    uint8_t intentos_conexion = 0; // Contador q usaremos para limitar el nº de intentos de conexion a la red wifi
    
    
    /* Variables correspondientes a los TOPIC SUB y PUB ( MQTT ) */
    
    const char* topic_subs_puerta = "cmnd/PUERTA/POWER"; // Variable Correspondiente al ACTUADOR LA PUERTA
    const char* topic_log_puerta = "cmnd/PUERTA/LOG"; // Variable Correspondiente al ACTUADOR LA PUERTA
    const char* topic_LWT_puerta = "cmnd/LWT/puerta";//Last will message

    /* Cabeceras de las funciones */
    
    void callback(char* topic, byte* payload, unsigned int length); // Funcion callback para los mensajes entrantes (llamadas) mqtt
    void reconnect(); // Funcion para reconectar en caso de perderse la conexion con el broker mqtt
    void arrancar_cliente_mqtt();
    void manejadorClienteMQTT();
  
  #endif
